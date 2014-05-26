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

#ifndef _SNAILBOT_DRIVER_H_
#define _SNAILBOT_DRIVER_H_

#include <math.h>

#include <ros/ros.h>
#include <snailbot_msgs/RawOdom.h>
#include <snailbot_msgs/Motors.h>
#include <snailbot_driver/MotorGainsConfig.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <dynamic_reconfigure/server.h>



class Snailbot
{
private:
	ros::NodeHandle nh_;
	ros::NodeHandle nh_private_;
	//Subsribers
	ros::Subscriber raw_sub_;
	ros::Subscriber vel_sub_;
	//Publishers
	ros::Publisher odom_pub_;
	ros::Publisher motor_pub_;
	//Dynamic Reconfigure
	dynamic_reconfigure::Server<snailbot_driver::MotorGainsConfig> gain_server_;
	//Members
	ros::Time encoder_current_time_;
	ros::Time encoder_previous_time_;
	tf::TransformBroadcaster *odom_broadcaster_;
	//Odom variables
	double x_; // [m]
	double y_; // [m]
	double theta_; // [radians]
	double dx_; // [m/s]
	double dy_; // [m/s]
	double dtheta_; // [radians/s]
	//Encoder variables
	long int right_counts_;	// [counts]
	long int left_counts_;	// [counts]
	long int old_right_counts_;	// [counts]
	long int old_left_counts_;	// [counts]
	// Vehicle characteristics
	int pwm_range_;
	int pwm_min_;
	int counts_per_rev_;	// [counts/rev]
	double gear_ratio_;
	bool encoder_on_motor_shaft_;
	double wheel_radius_;	// [m]
	double base_width_;	// [m]
	double meters_per_counts_; // [m/counts]
	// Vehicle control variables
	double K_left_P_, K_left_I_, K_left_D_;
	double K_right_P_, K_right_I_, K_right_D_;
	double velocity_estimate_left_, velocity_estimate_right_;
	double velocity_control_freq_;
	ros::Time control_current_time_;
	ros::Time control_previous_time_;
	snailbot_msgs::Motors motors_previous_cmd_;
	int pwmBound(int pwm);
	// ROS Member functions
	void cmdVelCallback(const geometry_msgs::Twist::ConstPtr& vel_msg);
	void rawOdomCallback(const snailbot_msgs::RawOdom::ConstPtr& raw_msg);
	void motorGainsCallback(snailbot_driver::MotorGainsConfig &config, uint32_t level);

public:
	Snailbot(ros::NodeHandle nh, ros::NodeHandle nh_private);
	virtual ~Snailbot();
};
#endif // _SNAILBOT_DRIVER_H


