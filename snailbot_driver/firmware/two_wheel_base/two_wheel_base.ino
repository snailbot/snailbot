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

#include <ros.h>
#include <snailbot_msgs/Encoders.h>
#include <snailbot_msgs/CmdDiffVel.h>
#include <Encoder.h>
#include <PololuMC33926.h>
#include "boot_buzzer.h"

// Left and Right motor driver objects
MC33926 left_motor(2,3,4,5);
MC33926 right_motor(12,11,10,9);

// Left side encoders pins
#define LEFT_ENCODER_A 14  // Interrupt on Teensy 3.0
#define LEFT_ENCODER_B 15  // Interrupt on Teensy 3.0
// Right side encoders pins
#define RIGHT_ENCODER_A 6  // Interrupt on Teensy 3.0
#define RIGHT_ENCODER_B 7  // Interrupt on Teensy 3.0

// Encoder objects from PJRC encoder library.
Encoder left_encoder(LEFT_ENCODER_A,LEFT_ENCODER_B);
Encoder right_encoder(RIGHT_ENCODER_A,RIGHT_ENCODER_B);

// Vehicle characteristics
float counts_per_rev = 48.0;
float gear_ratio = 75.0/1.0;
boolean encoder_on_motor_shaft = true;
float wheel_radius = 0.120/2.0; // [m]
float meters_per_counts;  // [m/counts]
int pwm_range = 255;

typedef struct {
  float desired_velocity;  // [m/s]
  uint32_t current_time;  // [miliseconds]
  uint32_t previous_time;  // [miliseconds]
  long current_encoder;  // [counts]
  long previous_encoder;  // [counts]
  int previous_error;  // [m/s]  
  int total_error;  // [m/s]
  int command; // [PWM]
}
ControlData;

// Gains
int Kp = 20;
int Ki = 0;
int Kd = 15;
int pid_gains[3] = {Kp,Ki,Kd};

ControlData left_motor_controller;
ControlData right_motor_controller;

// Control methods prototypes
void updateControl(ControlData * ctrl);
void doControl(ControlData * ctrl);
void Control();

int control_rate[1] = {50};  // Hz
int encoder_rate[1] = {50};  // Hz
int no_cmd_timeout[1] = {2}; // seconds

static uint32_t last_encoders_time;  // miliseconds
static uint32_t last_cmd_time;  // miliseconds
static uint32_t last_control_time;  // miliseconds


// SPEAKER
#define SPEAKER 13

// ROS node
ros::NodeHandle_<ArduinoHardware, 10, 10, 1024, 1024> nh;

// ROS subribers/service callbacks prototye
void cmdDiffVelCallback( const snailbot_msgs::CmdDiffVel& diff_vel_msg); 

// ROS subsribers
ros::Subscriber<snailbot_msgs::CmdDiffVel> sub_diff_vel("cmd_diff_vel", cmdDiffVelCallback);

// ROS publishers msgs
snailbot_msgs::Encoders encoders_msg;

// ROS publishers
ros::Publisher pub_encoders("encoders", &encoders_msg);


void setup() 
{ 
  // Initalize Motors
  left_motor.init();
  right_motor.init();

  // Speaker
  pinMode(SPEAKER, OUTPUT);
  digitalWrite(SPEAKER, LOW); // Turn pullup resistor on

  // Set the node handle
  nh.getHardware()->setBaud(115200);
  nh.initNode();

  // Pub/Sub
  nh.advertise(pub_encoders);
  nh.subscribe(sub_diff_vel);

  // Wait for ROSserial to connect
  while (!nh.connected()) 
  {
    nh.spinOnce();
  }
  nh.loginfo("Connected to microcontroller.");
  
  // Look for node params TOODO(tonybaltovski)
  if (!nh.getParam("pid_gains", pid_gains,3))
  { 
    nh.loginfo("Using default gains.");
  } 
  else
  {
    Kp = pid_gains[0];
    Ki = pid_gains[1];
    Kd = pid_gains[2];
  }
  
  // compute the meters per count
  if (encoder_on_motor_shaft == true)
  {
    meters_per_counts = ((PI * 2 * wheel_radius) / (counts_per_rev* gear_ratio));
  }
  else
  {
    meters_per_counts = ((PI * 2 * wheel_radius) / counts_per_rev);
  }
  start_tune(SPEAKER);

} 

void loop() 
{
  if ((millis() - last_encoders_time) >= (1000 / encoder_rate[0]))
  { 
    encoders_msg.left = left_encoder.read();
    encoders_msg.right = right_encoder.read();
    pub_encoders.publish(&encoders_msg);
    last_encoders_time = millis();
  }
  if ((millis()) - last_control_time >= (1000 / control_rate[0]))
  {
    Control();
    last_control_time = millis();
  }
  // Stop motors after a period of no commands
  if((millis() - last_cmd_time) >= (no_cmd_timeout[0] * 1000))
  {
    left_motor_controller.desired_velocity = 0.0;
    right_motor_controller.desired_velocity = 0.0;
  }
  nh.spinOnce();
}


void cmdDiffVelCallback( const snailbot_msgs::CmdDiffVel& diff_vel_msg) 
{
  left_motor_controller.desired_velocity = diff_vel_msg.left;
  right_motor_controller.desired_velocity = diff_vel_msg.right;
  last_cmd_time = millis();
}

void updateControl()
{
  left_motor_controller.current_encoder = left_encoder.read();
  left_motor_controller.current_time = millis();
  right_motor_controller.current_encoder = right_encoder.read();
  right_motor_controller.current_time = millis();
}
void doControl(ControlData * ctrl)
{
  float estimated_velocity = meters_per_counts * (ctrl->current_encoder - ctrl->previous_encoder) * 1000.0 / (ctrl->current_time - ctrl->previous_time);
  float error = ctrl->desired_velocity - estimated_velocity;
  float cmd = Kp * error + Ki * (ctrl->total_error + error) + Kd * (error - ctrl->previous_error);
  
  cmd += ctrl->command;
  
  
  if(cmd >= pwm_range)
  {
    cmd = pwm_range;
  }
  else if (cmd <= -pwm_range)
  {
    cmd = -pwm_range;
  }
  else
  {
    ctrl->total_error += error;
  }
  
  ctrl->command = cmd;
  ctrl->previous_time = ctrl->current_time;
  ctrl->previous_encoder = ctrl->current_encoder;
  ctrl->previous_error = error;
  
}

void Control()
{
  updateControl();
  
  doControl(&left_motor_controller);
  doControl(&right_motor_controller);
  
  if(left_motor_controller.desired_velocity > 0 || left_motor_controller.desired_velocity < 0)
  {
      left_motor.set_pwm(left_motor_controller.command);
  }
  else
  {
      left_motor.set_pwm(0);
  }
    
  if(right_motor_controller.desired_velocity > 0 || right_motor_controller.desired_velocity < 0)
  {
      right_motor.set_pwm(right_motor_controller.command);
  }
  else
  {
      right_motor.set_pwm(0);
  }
}




