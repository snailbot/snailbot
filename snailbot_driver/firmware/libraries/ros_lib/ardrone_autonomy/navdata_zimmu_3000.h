#ifndef _ROS_ardrone_autonomy_navdata_zimmu_3000_h
#define _ROS_ardrone_autonomy_navdata_zimmu_3000_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_zimmu_3000 : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float drone_time;
      uint16_t tag;
      uint16_t size;
      int32_t vzimmuLSB;
      float vzfind;

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
      } u_vzimmuLSB;
      u_vzimmuLSB.real = this->vzimmuLSB;
      *(outbuffer + offset + 0) = (u_vzimmuLSB.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vzimmuLSB.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vzimmuLSB.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vzimmuLSB.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vzimmuLSB);
      union {
        float real;
        uint32_t base;
      } u_vzfind;
      u_vzfind.real = this->vzfind;
      *(outbuffer + offset + 0) = (u_vzfind.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vzfind.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vzfind.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vzfind.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vzfind);
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
      } u_vzimmuLSB;
      u_vzimmuLSB.base = 0;
      u_vzimmuLSB.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vzimmuLSB.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vzimmuLSB.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vzimmuLSB.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vzimmuLSB = u_vzimmuLSB.real;
      offset += sizeof(this->vzimmuLSB);
      union {
        float real;
        uint32_t base;
      } u_vzfind;
      u_vzfind.base = 0;
      u_vzfind.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vzfind.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vzfind.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vzfind.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vzfind = u_vzfind.real;
      offset += sizeof(this->vzfind);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_zimmu_3000"; };
    const char * getMD5(){ return "ae43ce2a4ef6cf0002f177f8265000bc"; };

  };

}
#endif