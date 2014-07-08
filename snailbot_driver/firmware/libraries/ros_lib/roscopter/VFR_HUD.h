#ifndef _ROS_roscopter_VFR_HUD_h
#define _ROS_roscopter_VFR_HUD_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscopter
{

  class VFR_HUD : public ros::Msg
  {
    public:
      float airspeed;
      float groundspeed;
      int16_t heading;
      uint16_t throttle;
      float alt;
      float climb;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_airspeed;
      u_airspeed.real = this->airspeed;
      *(outbuffer + offset + 0) = (u_airspeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_airspeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_airspeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_airspeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->airspeed);
      union {
        float real;
        uint32_t base;
      } u_groundspeed;
      u_groundspeed.real = this->groundspeed;
      *(outbuffer + offset + 0) = (u_groundspeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_groundspeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_groundspeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_groundspeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->groundspeed);
      union {
        int16_t real;
        uint16_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->heading);
      *(outbuffer + offset + 0) = (this->throttle >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->throttle >> (8 * 1)) & 0xFF;
      offset += sizeof(this->throttle);
      union {
        float real;
        uint32_t base;
      } u_alt;
      u_alt.real = this->alt;
      *(outbuffer + offset + 0) = (u_alt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alt);
      union {
        float real;
        uint32_t base;
      } u_climb;
      u_climb.real = this->climb;
      *(outbuffer + offset + 0) = (u_climb.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_climb.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_climb.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_climb.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->climb);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_airspeed;
      u_airspeed.base = 0;
      u_airspeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_airspeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_airspeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_airspeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->airspeed = u_airspeed.real;
      offset += sizeof(this->airspeed);
      union {
        float real;
        uint32_t base;
      } u_groundspeed;
      u_groundspeed.base = 0;
      u_groundspeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_groundspeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_groundspeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_groundspeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->groundspeed = u_groundspeed.real;
      offset += sizeof(this->groundspeed);
      union {
        int16_t real;
        uint16_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
      this->throttle =  ((uint16_t) (*(inbuffer + offset)));
      this->throttle |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->throttle);
      union {
        float real;
        uint32_t base;
      } u_alt;
      u_alt.base = 0;
      u_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alt = u_alt.real;
      offset += sizeof(this->alt);
      union {
        float real;
        uint32_t base;
      } u_climb;
      u_climb.base = 0;
      u_climb.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_climb.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_climb.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_climb.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->climb = u_climb.real;
      offset += sizeof(this->climb);
     return offset;
    }

    const char * getType(){ return "roscopter/VFR_HUD"; };
    const char * getMD5(){ return "d675e2b95b45d51cd67453c819986216"; };

  };

}
#endif