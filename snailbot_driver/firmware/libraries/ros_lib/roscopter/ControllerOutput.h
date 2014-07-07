#ifndef _ROS_roscopter_ControllerOutput_h
#define _ROS_roscopter_ControllerOutput_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscopter
{

  class ControllerOutput : public ros::Msg
  {
    public:
      float nav_roll;
      float nav_pitch;
      int16_t nav_bearing;
      float alt_error;
      float air_spd_error;
      float xtrack_error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_nav_roll;
      u_nav_roll.real = this->nav_roll;
      *(outbuffer + offset + 0) = (u_nav_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nav_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nav_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nav_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nav_roll);
      union {
        float real;
        uint32_t base;
      } u_nav_pitch;
      u_nav_pitch.real = this->nav_pitch;
      *(outbuffer + offset + 0) = (u_nav_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nav_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nav_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nav_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nav_pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_nav_bearing;
      u_nav_bearing.real = this->nav_bearing;
      *(outbuffer + offset + 0) = (u_nav_bearing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nav_bearing.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->nav_bearing);
      union {
        float real;
        uint32_t base;
      } u_alt_error;
      u_alt_error.real = this->alt_error;
      *(outbuffer + offset + 0) = (u_alt_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alt_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alt_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alt_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alt_error);
      union {
        float real;
        uint32_t base;
      } u_air_spd_error;
      u_air_spd_error.real = this->air_spd_error;
      *(outbuffer + offset + 0) = (u_air_spd_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_air_spd_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_air_spd_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_air_spd_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->air_spd_error);
      union {
        float real;
        uint32_t base;
      } u_xtrack_error;
      u_xtrack_error.real = this->xtrack_error;
      *(outbuffer + offset + 0) = (u_xtrack_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xtrack_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xtrack_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xtrack_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xtrack_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_nav_roll;
      u_nav_roll.base = 0;
      u_nav_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nav_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nav_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nav_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nav_roll = u_nav_roll.real;
      offset += sizeof(this->nav_roll);
      union {
        float real;
        uint32_t base;
      } u_nav_pitch;
      u_nav_pitch.base = 0;
      u_nav_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nav_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nav_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nav_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nav_pitch = u_nav_pitch.real;
      offset += sizeof(this->nav_pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_nav_bearing;
      u_nav_bearing.base = 0;
      u_nav_bearing.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nav_bearing.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->nav_bearing = u_nav_bearing.real;
      offset += sizeof(this->nav_bearing);
      union {
        float real;
        uint32_t base;
      } u_alt_error;
      u_alt_error.base = 0;
      u_alt_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alt_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alt_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alt_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alt_error = u_alt_error.real;
      offset += sizeof(this->alt_error);
      union {
        float real;
        uint32_t base;
      } u_air_spd_error;
      u_air_spd_error.base = 0;
      u_air_spd_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_air_spd_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_air_spd_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_air_spd_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->air_spd_error = u_air_spd_error.real;
      offset += sizeof(this->air_spd_error);
      union {
        float real;
        uint32_t base;
      } u_xtrack_error;
      u_xtrack_error.base = 0;
      u_xtrack_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xtrack_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xtrack_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xtrack_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xtrack_error = u_xtrack_error.real;
      offset += sizeof(this->xtrack_error);
     return offset;
    }

    const char * getType(){ return "roscopter/ControllerOutput"; };
    const char * getMD5(){ return "14e8f32f6dc13cd7db7fdae805a6677b"; };

  };

}
#endif