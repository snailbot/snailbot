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
#include <snailbot_msgs/RawOdom.h>
#include <snailbot_msgs/Motors.h>
#include "PololuMC33926.h"
#include "boot_buzzer.h"

//Motor Driver Pins
MC33926 left_motor(2,3,4,5);
MC33926 right_motor(12,11,10,9);
//Left Side Encoder
#define LEFT_ENCODER_A 14  //Interrupt on Teensy 3.0
#define LEFT_ENCODER_B 15 //Interrupt on Teensy 3.0
//Right Side Encoder
#define RIGHT_ENCODER_A 6  //Interrupt on Teensy 3.0
#define RIGHT_ENCODER_B 7  //Interrupt on Teensy 3.0

//Encoder variables
volatile int left_old;
volatile int right_old;
volatile int left_current;
volatile int right_current;
volatile long  left_encoder_counts = 0;
volatile long right_encoder_counts = 0;
int encoder_table[16] = {0,-1,1,2,1,0,2,-1,-1,2,0,1,2,1,-1,0};

ros::NodeHandle  nh;
static uint32_t last_time = 0;
//SPEAKER
#define SPEAKER 13

void motorsCallback( const snailbot_msgs::Motors& motors_msg) 
{
  left_motor.set_pwm(motors_msg.leftPWM);
  right_motor.set_pwm(motors_msg.rightPWM);
}

snailbot_msgs::RawOdom odom_msg;
ros::Publisher raw_odom("raw_odom", &odom_msg);
ros::Subscriber<snailbot_msgs::Motors> cmd_motors("cmd_motors", motorsCallback);

void setup() 
{ 
  //Set pin mode
  left_motor.init();
  right_motor.init();
  pinMode(LEFT_ENCODER_A, INPUT);
  pinMode(LEFT_ENCODER_B, INPUT);
  pinMode(RIGHT_ENCODER_A, INPUT);
  pinMode(RIGHT_ENCODER_B, INPUT);
  pinMode(SPEAKER, OUTPUT);

  digitalWrite(LEFT_ENCODER_A, HIGH); //turn pullup resistor on
  digitalWrite(LEFT_ENCODER_B, HIGH); //turn pullup resistor on
  digitalWrite(RIGHT_ENCODER_A, HIGH); //turn pullup resistor on
  digitalWrite(RIGHT_ENCODER_B, HIGH); //turn pullup resistor on
  digitalWrite(SPEAKER, LOW); //turn pullup resistor on

  //Add interrupt for encoders
  attachInterrupt(14, leftUpdateEncoder, CHANGE); 
  attachInterrupt(15, leftUpdateEncoder, CHANGE);
  attachInterrupt(6, rightUpdateEncoder, CHANGE); 
  attachInterrupt(7, rightUpdateEncoder, CHANGE);

  start_tune(SPEAKER);

  nh.initNode();
  nh.advertise(raw_odom);
  nh.subscribe(cmd_motors);
} 

void loop() 
{
  if (millis() - last_time >= 10)
  {
    odom_msg.left = left_encoder_counts;
    odom_msg.right = right_encoder_counts;
    raw_odom.publish(&odom_msg);
    last_time = millis();
  }
  nh.spinOnce();
  
}

void leftUpdateEncoder(){
  left_current = digitalRead(LEFT_ENCODER_A)*2 +digitalRead(LEFT_ENCODER_B);       
  left_encoder_counts -= encoder_table[left_old*4 +left_current];
  left_old = left_current;
}

void rightUpdateEncoder(){
  right_current = digitalRead(RIGHT_ENCODER_A)*2 +digitalRead(RIGHT_ENCODER_B);      
  right_encoder_counts -= encoder_table[right_old*4 +right_current];
  right_old = right_current;
}


