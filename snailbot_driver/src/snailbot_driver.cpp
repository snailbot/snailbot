/*

Copyright (c) 2013, Tony Baltovski 
All rights reserved. 

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met: 

 * Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer. 
 * Redistributions in binary form must reproduce the above copyright 
   notice, this list of conditions and the following disclaimer in the 
   documentation and/or other materials provided with the distribution. 
 * Neither the name of  nor the names of its contributors may be used to 
   endorse or promote products derived from this software without specific 
   prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
POSSIBILITY OF SUCH DAMAGE. 

*/
#include <math.h>
#include "snailbot_driver/snailbot_driver.h"

Snailbot::Snailbot(ros::NodeHandle nh, ros::NodeHandle nh_private):
	nh_(nh),
	nh_private_(nh_private),
	x_(0.0),
	y_(0.0),
	theta_(0.0),
	dx_(0.0),
	dy_(0.0),
	dtheta_(0.0),
	right_counts_(0),
	left_counts_(0),
	old_right_counts_(0),
	old_left_counts_(0),
	counts_per_rev_(48),
	gear_ratio_(75.0/1.0),
	encoder_on_motor_shaft_(true),
	wheel_radius_(0.120/2.0),
	base_width_(0.225),
	velocity_control_freq_(20.0),
	previous_error_left_(0.0),
	total_error_left_(0.0),
	previous_error_right_(0.0),
	total_error_right_(0.0),
	pwm_range_(255)
{
	//ROS params
	// TODO
	motor_pub_ = nh_.advertise<snailbot_msgs::Motors>("cmd_motors", 5);
	odom_pub_ = nh_.advertise<nav_msgs::Odometry>("odom", 5);
	raw_sub_ = nh_.subscribe("raw_odom", 5, &Snailbot::raw_odom_callback,this,ros::TransportHints().tcpNoDelay());	
	vel_sub_ = nh_.subscribe("cmd_vel", 5, &Snailbot::cmd_vel_callback,this,ros::TransportHints().tcpNoDelay());
	dynamic_reconfigure::Server<snailbot_driver::MotorGainsConfig>::CallbackType f = boost::bind(&Snailbot::motor_gains_callback, this, _1, _2);
	gain_server_.setCallback(f);	
	if (encoder_on_motor_shaft_)
	{
		meters_per_counts_ = ((M_PI * 2 * wheel_radius_) / (counts_per_rev_ * gear_ratio_));
	}	
	else
	{
		meters_per_counts_ = ((M_PI * 2 * wheel_radius_) / counts_per_rev_);
	}
}

Snailbot::~Snailbot()
{
	ROS_INFO ("Destroying Snailbot Driver");
}


void Snailbot::cmd_vel_callback(const geometry_msgs::TwistConstPtr& vel_msg)
{
	// TODO Maybe move the this to its own node
	control_current_time_ = ros::Time::now();
	double dt = (control_current_time_ - control_previous_time_).toSec();
	if (dt >= (1/velocity_control_freq_))
	{
		double velocity_desired_right = (vel_msg->linear.x + ((base_width_ / 2) * vel_msg->angular.z));
		double velocity_desired_left = (vel_msg->linear.x + ((base_width_ / -2) * vel_msg->angular.z));	
		snailbot_msgs::Motors motors_current_cmd;
		double error_vel_right = velocity_desired_right - velocity_estimate_right_;
		double error_vel_left = velocity_desired_left - velocity_estimate_left_;
		motors_current_cmd.leftPWM = pwm_bound((error_vel_left * K_left_P_ + K_left_I_*total_error_left_ + (K_left_D_*(error_vel_left - previous_error_left_)/dt)));
		motors_current_cmd.rightPWM = pwm_bound((error_vel_right * K_right_P_ + K_right_I_*total_error_right_ + (K_right_D_*(error_vel_right - previous_error_right_)/dt)));
		motor_pub_.publish(motors_current_cmd);
		control_previous_time_ = control_current_time_;
		motors_previous_cmd_ = motors_current_cmd;
	}
}

void Snailbot::motor_gains_callback(snailbot_driver::MotorGainsConfig &config, uint32_t level) 
{
	K_left_P_ = config.K_left_P;
	K_left_I_ = config.K_left_I;
	K_left_D_ = config.K_left_D;
	K_right_P_ = config.K_right_P;
	K_right_I_ = config.K_right_I;
	K_right_D_ = config.K_right_D;
	ROS_INFO("Motor Gains changed to Left P:%f I:%f D: %f and Right P:%f I:%f D:%f",K_left_P_,K_left_I_,K_left_D_,K_right_P_,K_right_I_,K_right_D_);
}
void Snailbot::raw_odom_callback(const snailbot_msgs::RawOdomConstPtr& raw_msg)
{
	encoder_current_time_ = ros::Time::now();
	odom_broadcaster_ = new tf::TransformBroadcaster();  
	nav_msgs::Odometry odom;
	left_counts_ = raw_msg->left;
	right_counts_ = raw_msg->right;

	double dt = (encoder_current_time_ - encoder_previous_time_).toSec(); // [s]
	velocity_estimate_left_ = meters_per_counts_ * (left_counts_ - old_left_counts_)/dt; //[m/s]
	velocity_estimate_right_ = meters_per_counts_ * (right_counts_ - old_right_counts_)/dt; //[m/s]
	double delta_s = meters_per_counts_ * (((right_counts_ - old_right_counts_) + (left_counts_ - old_left_counts_))/2.0); // [m]
	double delta_theta = meters_per_counts_ * (((right_counts_-old_right_counts_) - (left_counts_ - old_left_counts_))/ base_width_ ); // [radians]
	double dx = delta_s * cos(theta_ + delta_theta/2.0); // [m]
	double dy = delta_s * sin(theta_ + delta_theta/2.0); // [m]
	x_+= dx; // [m]
	y_+= dy; // [m]
	theta_+= delta_theta; // [radians]
	geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(theta_);

	geometry_msgs::TransformStamped odom_trans;
	odom_trans.header.stamp = encoder_current_time_;
	odom_trans.header.frame_id = "odom";
	odom_trans.child_frame_id = "base_footprint";
	odom_trans.transform.translation.x = x_;
	odom_trans.transform.translation.y = y_;
	odom_trans.transform.translation.z = 0.0;
	odom_trans.transform.rotation = odom_quat;
	odom_broadcaster_->sendTransform(odom_trans);
   
	odom.header.stamp = encoder_current_time_;
	odom.header.frame_id = "odom";
	odom.child_frame_id = "base_footprint";
	odom.pose.pose.position.x = x_;
	odom.pose.pose.position.y = y_;
	odom.pose.pose.position.z = 0.0;
	odom.pose.pose.orientation = odom_quat;
	odom.twist.twist.linear.x = dx/dt;
	odom.twist.twist.linear.y = dy/dt;
	odom.twist.twist.linear.z = 0.0;
	odom.twist.twist.angular.x = 0.0;
	odom.twist.twist.angular.y = 0.0;
	odom.twist.twist.angular.z = delta_theta/dt;
	odom.pose.covariance[0]  = 0.01;  //x
	odom.pose.covariance[7]  = 0.01;  //y
	odom.pose.covariance[14] = 99999; //z
	odom.pose.covariance[21] = 99999; //roll
	odom.pose.covariance[28] = 99999; //pitch
	odom.pose.covariance[35] = 0.01; //yaw(theta)
	odom.twist.covariance[0]  = 0.01;  //x
	odom.twist.covariance[7]  = 0.01;  //y
	odom.twist.covariance[14] = 99999; //z
	odom.twist.covariance[21] = 99999; //roll
	odom.twist.covariance[28] = 99999; //pitch
	odom.twist.covariance[35] = 0.01; //yaw(theta)

	odom_pub_.publish(odom);

	encoder_previous_time_ = encoder_current_time_;
	old_right_counts_ = right_counts_;
	old_left_counts_ = left_counts_;
}

int Snailbot::pwm_bound(int pwm)
{
	if (pwm > pwm_range_)
		return pwm_range_;
	else if (pwm < -pwm_range_)
		return -pwm_range_;
	else
		return pwm;
}
