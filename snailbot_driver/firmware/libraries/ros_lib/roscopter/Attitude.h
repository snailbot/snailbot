#ifndef _ROS_roscopter_Attitude_h
#define _ROS_roscopter_Attitude_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscopter
{

  class Attitude : public ros::Msg
  {
    public:
      float roll;
      float pitch;
      float yaw;
      float rollspeed;
      float pitchspeed;
      float yawspeed;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_rollspeed;
      u_rollspeed.real = this->rollspeed;
      *(outbuffer + offset + 0) = (u_rollspeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rollspeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rollspeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rollspeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rollspeed);
      union {
        float real;
        uint32_t base;
      } u_pitchspeed;
      u_pitchspeed.real = this->pitchspeed;
      *(outbuffer + offset + 0) = (u_pitchspeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitchspeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitchspeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitchspeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitchspeed);
      union {
        float real;
        uint32_t base;
      } u_yawspeed;
      u_yawspeed.real = this->yawspeed;
      *(outbuffer + offset + 0) = (u_yawspeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yawspeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yawspeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yawspeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yawspeed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_rollspeed;
      u_rollspeed.base = 0;
      u_rollspeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rollspeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rollspeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rollspeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rollspeed = u_rollspeed.real;
      offset += sizeof(this->rollspeed);
      union {
        float real;
        uint32_t base;
      } u_pitchspeed;
      u_pitchspeed.base = 0;
      u_pitchspeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitchspeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitchspeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitchspeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitchspeed = u_pitchspeed.real;
      offset += sizeof(this->pitchspeed);
      union {
        float real;
        uint32_t base;
      } u_yawspeed;
      u_yawspeed.base = 0;
      u_yawspeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yawspeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yawspeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yawspeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yawspeed = u_yawspeed.real;
      offset += sizeof(this->yawspeed);
     return offset;
    }

    const char * getType(){ return "roscopter/Attitude"; };
    const char * getMD5(){ return "a0ed90d05663fe955b3f4e85f83050df"; };

  };

}
#endif