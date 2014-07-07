#ifndef _ROS_roscopter_Waypoint_h
#define _ROS_roscopter_Waypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscopter
{

  class Waypoint : public ros::Msg
  {
    public:
      int32_t latitude;
      int32_t longitude;
      int32_t altitude;
      uint16_t pos_acc;
      uint8_t speed_to;
      uint16_t hold_time;
      int32_t yaw_from;
      int32_t pan_angle;
      int32_t tilt_angle;
      uint8_t waypoint_type;
      enum { TYPE_NAV =  1 };
      enum { TYPE_CONDITION_YAW =  2 };
      enum { TYPE_CONDITION_CHANGE_ALT =  3 };
      enum { TYPE_TAKEOFF =  4 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        int32_t real;
        uint32_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        int32_t real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      *(outbuffer + offset + 0) = (this->pos_acc >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pos_acc >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pos_acc);
      *(outbuffer + offset + 0) = (this->speed_to >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_to);
      *(outbuffer + offset + 0) = (this->hold_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hold_time >> (8 * 1)) & 0xFF;
      offset += sizeof(this->hold_time);
      union {
        int32_t real;
        uint32_t base;
      } u_yaw_from;
      u_yaw_from.real = this->yaw_from;
      *(outbuffer + offset + 0) = (u_yaw_from.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_from.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_from.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_from.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_from);
      union {
        int32_t real;
        uint32_t base;
      } u_pan_angle;
      u_pan_angle.real = this->pan_angle;
      *(outbuffer + offset + 0) = (u_pan_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pan_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pan_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pan_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pan_angle);
      union {
        int32_t real;
        uint32_t base;
      } u_tilt_angle;
      u_tilt_angle.real = this->tilt_angle;
      *(outbuffer + offset + 0) = (u_tilt_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tilt_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tilt_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tilt_angle);
      *(outbuffer + offset + 0) = (this->waypoint_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->waypoint_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        int32_t real;
        uint32_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        int32_t real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      this->pos_acc =  ((uint16_t) (*(inbuffer + offset)));
      this->pos_acc |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pos_acc);
      this->speed_to =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->speed_to);
      this->hold_time =  ((uint16_t) (*(inbuffer + offset)));
      this->hold_time |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->hold_time);
      union {
        int32_t real;
        uint32_t base;
      } u_yaw_from;
      u_yaw_from.base = 0;
      u_yaw_from.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_from.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_from.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_from.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_from = u_yaw_from.real;
      offset += sizeof(this->yaw_from);
      union {
        int32_t real;
        uint32_t base;
      } u_pan_angle;
      u_pan_angle.base = 0;
      u_pan_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pan_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pan_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pan_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pan_angle = u_pan_angle.real;
      offset += sizeof(this->pan_angle);
      union {
        int32_t real;
        uint32_t base;
      } u_tilt_angle;
      u_tilt_angle.base = 0;
      u_tilt_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tilt_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tilt_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tilt_angle = u_tilt_angle.real;
      offset += sizeof(this->tilt_angle);
      this->waypoint_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->waypoint_type);
     return offset;
    }

    const char * getType(){ return "roscopter/Waypoint"; };
    const char * getMD5(){ return "6dac49f8cf4308a151d9b97deaca8a40"; };

  };

}
#endif