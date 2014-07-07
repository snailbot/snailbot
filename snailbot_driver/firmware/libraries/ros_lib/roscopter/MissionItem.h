#ifndef _ROS_roscopter_MissionItem_h
#define _ROS_roscopter_MissionItem_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace roscopter
{

  class MissionItem : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t mission_num;
      uint8_t isCurrent;
      uint8_t isAutoContinue;
      float posAcc;
      float holdTime;
      float loiterRadius;
      float yawFrom;
      float x_lat;
      float y_long;
      float z_alt;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mission_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mission_num >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mission_num);
      *(outbuffer + offset + 0) = (this->isCurrent >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isCurrent);
      *(outbuffer + offset + 0) = (this->isAutoContinue >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isAutoContinue);
      union {
        float real;
        uint32_t base;
      } u_posAcc;
      u_posAcc.real = this->posAcc;
      *(outbuffer + offset + 0) = (u_posAcc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_posAcc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_posAcc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_posAcc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->posAcc);
      union {
        float real;
        uint32_t base;
      } u_holdTime;
      u_holdTime.real = this->holdTime;
      *(outbuffer + offset + 0) = (u_holdTime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_holdTime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_holdTime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_holdTime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->holdTime);
      union {
        float real;
        uint32_t base;
      } u_loiterRadius;
      u_loiterRadius.real = this->loiterRadius;
      *(outbuffer + offset + 0) = (u_loiterRadius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_loiterRadius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_loiterRadius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_loiterRadius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loiterRadius);
      union {
        float real;
        uint32_t base;
      } u_yawFrom;
      u_yawFrom.real = this->yawFrom;
      *(outbuffer + offset + 0) = (u_yawFrom.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yawFrom.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yawFrom.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yawFrom.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yawFrom);
      union {
        float real;
        uint32_t base;
      } u_x_lat;
      u_x_lat.real = this->x_lat;
      *(outbuffer + offset + 0) = (u_x_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_lat.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_lat);
      union {
        float real;
        uint32_t base;
      } u_y_long;
      u_y_long.real = this->y_long;
      *(outbuffer + offset + 0) = (u_y_long.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_long.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_long.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_long.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_long);
      union {
        float real;
        uint32_t base;
      } u_z_alt;
      u_z_alt.real = this->z_alt;
      *(outbuffer + offset + 0) = (u_z_alt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_alt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_alt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_alt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_alt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->mission_num =  ((uint16_t) (*(inbuffer + offset)));
      this->mission_num |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->mission_num);
      this->isCurrent =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->isCurrent);
      this->isAutoContinue =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->isAutoContinue);
      union {
        float real;
        uint32_t base;
      } u_posAcc;
      u_posAcc.base = 0;
      u_posAcc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_posAcc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_posAcc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_posAcc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->posAcc = u_posAcc.real;
      offset += sizeof(this->posAcc);
      union {
        float real;
        uint32_t base;
      } u_holdTime;
      u_holdTime.base = 0;
      u_holdTime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_holdTime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_holdTime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_holdTime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->holdTime = u_holdTime.real;
      offset += sizeof(this->holdTime);
      union {
        float real;
        uint32_t base;
      } u_loiterRadius;
      u_loiterRadius.base = 0;
      u_loiterRadius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_loiterRadius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_loiterRadius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_loiterRadius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->loiterRadius = u_loiterRadius.real;
      offset += sizeof(this->loiterRadius);
      union {
        float real;
        uint32_t base;
      } u_yawFrom;
      u_yawFrom.base = 0;
      u_yawFrom.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yawFrom.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yawFrom.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yawFrom.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yawFrom = u_yawFrom.real;
      offset += sizeof(this->yawFrom);
      union {
        float real;
        uint32_t base;
      } u_x_lat;
      u_x_lat.base = 0;
      u_x_lat.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_lat.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_lat.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_lat.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_lat = u_x_lat.real;
      offset += sizeof(this->x_lat);
      union {
        float real;
        uint32_t base;
      } u_y_long;
      u_y_long.base = 0;
      u_y_long.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_long.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_long.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_long.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_long = u_y_long.real;
      offset += sizeof(this->y_long);
      union {
        float real;
        uint32_t base;
      } u_z_alt;
      u_z_alt.base = 0;
      u_z_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_alt = u_z_alt.real;
      offset += sizeof(this->z_alt);
     return offset;
    }

    const char * getType(){ return "roscopter/MissionItem"; };
    const char * getMD5(){ return "a4eec5db18601d2affa66a99457a442d"; };

  };

}
#endif