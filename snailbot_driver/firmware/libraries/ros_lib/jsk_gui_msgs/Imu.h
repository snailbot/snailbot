#ifndef _ROS_jsk_gui_msgs_Imu_h
#define _ROS_jsk_gui_msgs_Imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace jsk_gui_msgs
{

  class Imu : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Quaternion orientation;
      geometry_msgs::Vector3 angular_velocity;
      geometry_msgs::Vector3 linear_acceleration;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->angular_velocity.serialize(outbuffer + offset);
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->angular_velocity.deserialize(inbuffer + offset);
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/Imu"; };
    const char * getMD5(){ return "69f0756e896955a61f27c7dd4838f021"; };

  };

}
#endif