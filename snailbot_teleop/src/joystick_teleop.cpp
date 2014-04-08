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

#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>

class JoystickTeleop
{
private:
	//Node Handle
	ros::NodeHandle nh_;
	//Subscribers
	ros::Subscriber joy_sub_;
	//Publishers
	ros::Publisher vel_pub_;
	//Members
	int linear_;
	int angular_;
	double linear_scale_;
	double angular_scale_;
	int trigger_;

public:
	JoystickTeleop() :
		//Members default values
		linear_(1),
		linear_scale_(0.5),
		angular_(0),
		angular_scale_(2),
		trigger_(0)
		{
		//ROS Parameters
		nh_.param("axis_linear", linear_, linear_);
		nh_.param("axis_angular", angular_, angular_);
		nh_.param("scale_angular", angular_scale_, angular_scale_);
		nh_.param("scale_linear", linear_scale_, linear_scale_);
		nh_.param("deadman_switch", trigger_, trigger_);
		//Init everything
		initSubscribers();
		initPublishers();
		}

	~JoystickTeleop()
	{
	}

	void initSubscribers()
	{
		//Init Subs
		joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("/joy", 10, &JoystickTeleop::joyCallback, this,ros::TransportHints().tcpNoDelay());
	}

	void initPublishers()
	{
		//Init Pub
		vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
	}

	void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
	{
		geometry_msgs::Twist vel_msg;
		if (joy->buttons[trigger_])
		{
			vel_msg.angular.z = angular_scale_*joy->axes[angular_];
			vel_msg.linear.x = linear_scale_*joy->axes[linear_];
		}
		else
		{
			vel_msg.angular.z = 0;
			vel_msg.linear.x = 0;
		}
			vel_pub_.publish(vel_msg);
	}
};



int main(int argc, char **argv)
{
	ros::init(argc, argv, "joystick_teleop");
	JoystickTeleop joystick_teleop;
	ros::spin();
	return 0;
}

