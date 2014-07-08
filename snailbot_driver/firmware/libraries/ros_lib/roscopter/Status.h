#ifndef _ROS_roscopter_Status_h
#define _ROS_roscopter_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace roscopter
{

  class Status : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int16_t battery_voltage;
      int16_t battery_current;
      int8_t battery_remaining;
      uint32_t sensors_enabled;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_battery_voltage;
      u_battery_voltage.real = this->battery_voltage;
      *(outbuffer + offset + 0) = (u_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_voltage.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->battery_voltage);
      union {
        int16_t real;
        uint16_t base;
      } u_battery_current;
      u_battery_current.real = this->battery_current;
      *(outbuffer + offset + 0) = (u_battery_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_current.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->battery_current);
      union {
        int8_t real;
        uint8_t base;
      } u_battery_remaining;
      u_battery_remaining.real = this->battery_remaining;
      *(outbuffer + offset + 0) = (u_battery_remaining.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_remaining);
      *(outbuffer + offset + 0) = (this->sensors_enabled >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensors_enabled >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensors_enabled >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensors_enabled >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensors_enabled);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_battery_voltage;
      u_battery_voltage.base = 0;
      u_battery_voltage.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_voltage.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->battery_voltage = u_battery_voltage.real;
      offset += sizeof(this->battery_voltage);
      union {
        int16_t real;
        uint16_t base;
      } u_battery_current;
      u_battery_current.base = 0;
      u_battery_current.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_current.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->battery_current = u_battery_current.real;
      offset += sizeof(this->battery_current);
      union {
        int8_t real;
        uint8_t base;
      } u_battery_remaining;
      u_battery_remaining.base = 0;
      u_battery_remaining.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->battery_remaining = u_battery_remaining.real;
      offset += sizeof(this->battery_remaining);
      this->sensors_enabled =  ((uint32_t) (*(inbuffer + offset)));
      this->sensors_enabled |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sensors_enabled |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sensors_enabled |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sensors_enabled);
     return offset;
    }

    const char * getType(){ return "roscopter/Status"; };
    const char * getMD5(){ return "44bba29061029309cd51365dfdec8bae"; };

  };

}
#endif