#ifndef _ROS_ardrone_autonomy_navdata_pressure_raw_h
#define _ROS_ardrone_autonomy_navdata_pressure_raw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_pressure_raw : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float drone_time;
      uint16_t tag;
      uint16_t size;
      int32_t up;
      int16_t ut;
      int32_t Temperature_meas;
      int32_t Pression_meas;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      int32_t * val_drone_time = (int32_t *) &(this->drone_time);
      int32_t exp_drone_time = (((*val_drone_time)>>23)&255);
      if(exp_drone_time != 0)
        exp_drone_time += 1023-127;
      int32_t sig_drone_time = *val_drone_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_drone_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_drone_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_drone_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_drone_time<<4) & 0xF0) | ((sig_drone_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_drone_time>>4) & 0x7F;
      if(this->drone_time < 0) *(outbuffer + offset -1) |= 0x80;
      *(outbuffer + offset + 0) = (this->tag >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tag >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tag);
      *(outbuffer + offset + 0) = (this->size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size >> (8 * 1)) & 0xFF;
      offset += sizeof(this->size);
      union {
        int32_t real;
        uint32_t base;
      } u_up;
      u_up.real = this->up;
      *(outbuffer + offset + 0) = (u_up.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_up.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_up.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_up.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->up);
      union {
        int16_t real;
        uint16_t base;
      } u_ut;
      u_ut.real = this->ut;
      *(outbuffer + offset + 0) = (u_ut.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ut.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ut);
      union {
        int32_t real;
        uint32_t base;
      } u_Temperature_meas;
      u_Temperature_meas.real = this->Temperature_meas;
      *(outbuffer + offset + 0) = (u_Temperature_meas.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Temperature_meas.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Temperature_meas.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Temperature_meas.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Temperature_meas);
      union {
        int32_t real;
        uint32_t base;
      } u_Pression_meas;
      u_Pression_meas.real = this->Pression_meas;
      *(outbuffer + offset + 0) = (u_Pression_meas.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Pression_meas.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Pression_meas.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Pression_meas.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Pression_meas);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t * val_drone_time = (uint32_t*) &(this->drone_time);
      offset += 3;
      *val_drone_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_drone_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_drone_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_drone_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_drone_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_drone_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_drone_time !=0)
        *val_drone_time |= ((exp_drone_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->drone_time = -this->drone_time;
      this->tag =  ((uint16_t) (*(inbuffer + offset)));
      this->tag |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->tag);
      this->size =  ((uint16_t) (*(inbuffer + offset)));
      this->size |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->size);
      union {
        int32_t real;
        uint32_t base;
      } u_up;
      u_up.base = 0;
      u_up.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_up.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_up.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_up.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->up = u_up.real;
      offset += sizeof(this->up);
      union {
        int16_t real;
        uint16_t base;
      } u_ut;
      u_ut.base = 0;
      u_ut.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ut.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ut = u_ut.real;
      offset += sizeof(this->ut);
      union {
        int32_t real;
        uint32_t base;
      } u_Temperature_meas;
      u_Temperature_meas.base = 0;
      u_Temperature_meas.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Temperature_meas.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Temperature_meas.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Temperature_meas.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Temperature_meas = u_Temperature_meas.real;
      offset += sizeof(this->Temperature_meas);
      union {
        int32_t real;
        uint32_t base;
      } u_Pression_meas;
      u_Pression_meas.base = 0;
      u_Pression_meas.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Pression_meas.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Pression_meas.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Pression_meas.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Pression_meas = u_Pression_meas.real;
      offset += sizeof(this->Pression_meas);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_pressure_raw"; };
    const char * getMD5(){ return "bee798af5d1297cfcb39217d797b8d90"; };

  };

}
#endif