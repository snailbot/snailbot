#ifndef _ROS_roscopter_FilteredPosition_h
#define _ROS_roscopter_FilteredPosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace roscopter
{

  class FilteredPosition : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t latitude;
      int32_t longitude;
      int32_t altitude;
      int32_t relative_altitude;
      int16_t ground_x_speed;
      int16_t ground_y_speed;
      int16_t ground_z_speed;
      uint16_t heading;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      union {
        int32_t real;
        uint32_t base;
      } u_relative_altitude;
      u_relative_altitude.real = this->relative_altitude;
      *(outbuffer + offset + 0) = (u_relative_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_altitude);
      union {
        int16_t real;
        uint16_t base;
      } u_ground_x_speed;
      u_ground_x_speed.real = this->ground_x_speed;
      *(outbuffer + offset + 0) = (u_ground_x_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ground_x_speed.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ground_x_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_ground_y_speed;
      u_ground_y_speed.real = this->ground_y_speed;
      *(outbuffer + offset + 0) = (u_ground_y_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ground_y_speed.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ground_y_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_ground_z_speed;
      u_ground_z_speed.real = this->ground_z_speed;
      *(outbuffer + offset + 0) = (u_ground_z_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ground_z_speed.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ground_z_speed);
      *(outbuffer + offset + 0) = (this->heading >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->heading >> (8 * 1)) & 0xFF;
      offset += sizeof(this->heading);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      union {
        int32_t real;
        uint32_t base;
      } u_relative_altitude;
      u_relative_altitude.base = 0;
      u_relative_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_altitude = u_relative_altitude.real;
      offset += sizeof(this->relative_altitude);
      union {
        int16_t real;
        uint16_t base;
      } u_ground_x_speed;
      u_ground_x_speed.base = 0;
      u_ground_x_speed.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ground_x_speed.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ground_x_speed = u_ground_x_speed.real;
      offset += sizeof(this->ground_x_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_ground_y_speed;
      u_ground_y_speed.base = 0;
      u_ground_y_speed.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ground_y_speed.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ground_y_speed = u_ground_y_speed.real;
      offset += sizeof(this->ground_y_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_ground_z_speed;
      u_ground_z_speed.base = 0;
      u_ground_z_speed.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ground_z_speed.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ground_z_speed = u_ground_z_speed.real;
      offset += sizeof(this->ground_z_speed);
      this->heading =  ((uint16_t) (*(inbuffer + offset)));
      this->heading |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->heading);
     return offset;
    }

    const char * getType(){ return "roscopter/FilteredPosition"; };
    const char * getMD5(){ return "c085fbfb9542cd7c5704f043b5e23e5c"; };

  };

}
#endif