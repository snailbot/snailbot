#ifndef _ROS_ardrone_autonomy_navdata_vision_raw_h
#define _ROS_ardrone_autonomy_navdata_vision_raw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_vision_raw : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float drone_time;
      uint16_t tag;
      uint16_t size;
      float vision_tx_raw;
      float vision_ty_raw;
      float vision_tz_raw;

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
        float real;
        uint32_t base;
      } u_vision_tx_raw;
      u_vision_tx_raw.real = this->vision_tx_raw;
      *(outbuffer + offset + 0) = (u_vision_tx_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vision_tx_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vision_tx_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vision_tx_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vision_tx_raw);
      union {
        float real;
        uint32_t base;
      } u_vision_ty_raw;
      u_vision_ty_raw.real = this->vision_ty_raw;
      *(outbuffer + offset + 0) = (u_vision_ty_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vision_ty_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vision_ty_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vision_ty_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vision_ty_raw);
      union {
        float real;
        uint32_t base;
      } u_vision_tz_raw;
      u_vision_tz_raw.real = this->vision_tz_raw;
      *(outbuffer + offset + 0) = (u_vision_tz_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vision_tz_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vision_tz_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vision_tz_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vision_tz_raw);
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
        float real;
        uint32_t base;
      } u_vision_tx_raw;
      u_vision_tx_raw.base = 0;
      u_vision_tx_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vision_tx_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vision_tx_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vision_tx_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vision_tx_raw = u_vision_tx_raw.real;
      offset += sizeof(this->vision_tx_raw);
      union {
        float real;
        uint32_t base;
      } u_vision_ty_raw;
      u_vision_ty_raw.base = 0;
      u_vision_ty_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vision_ty_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vision_ty_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vision_ty_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vision_ty_raw = u_vision_ty_raw.real;
      offset += sizeof(this->vision_ty_raw);
      union {
        float real;
        uint32_t base;
      } u_vision_tz_raw;
      u_vision_tz_raw.base = 0;
      u_vision_tz_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vision_tz_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vision_tz_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vision_tz_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vision_tz_raw = u_vision_tz_raw.real;
      offset += sizeof(this->vision_tz_raw);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_vision_raw"; };
    const char * getMD5(){ return "a656de33995320e1ee5a84370378836e"; };

  };

}
#endif