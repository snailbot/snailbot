#ifndef _ROS_visp_tracker_KltPoint_h
#define _ROS_visp_tracker_KltPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_tracker
{

  class KltPoint : public ros::Msg
  {
    public:
      float i;
      float j;
      int32_t id;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_i = (int32_t *) &(this->i);
      int32_t exp_i = (((*val_i)>>23)&255);
      if(exp_i != 0)
        exp_i += 1023-127;
      int32_t sig_i = *val_i;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_i<<5) & 0xff;
      *(outbuffer + offset++) = (sig_i>>3) & 0xff;
      *(outbuffer + offset++) = (sig_i>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_i<<4) & 0xF0) | ((sig_i>>19)&0x0F);
      *(outbuffer + offset++) = (exp_i>>4) & 0x7F;
      if(this->i < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_j = (int32_t *) &(this->j);
      int32_t exp_j = (((*val_j)>>23)&255);
      if(exp_j != 0)
        exp_j += 1023-127;
      int32_t sig_j = *val_j;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_j<<5) & 0xff;
      *(outbuffer + offset++) = (sig_j>>3) & 0xff;
      *(outbuffer + offset++) = (sig_j>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_j<<4) & 0xF0) | ((sig_j>>19)&0x0F);
      *(outbuffer + offset++) = (exp_j>>4) & 0x7F;
      if(this->j < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_i = (uint32_t*) &(this->i);
      offset += 3;
      *val_i = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_i |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_i = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_i |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_i !=0)
        *val_i |= ((exp_i)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->i = -this->i;
      uint32_t * val_j = (uint32_t*) &(this->j);
      offset += 3;
      *val_j = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_j |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_j |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_j |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_j = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_j |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_j !=0)
        *val_j |= ((exp_j)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->j = -this->j;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return "visp_tracker/KltPoint"; };
    const char * getMD5(){ return "6014cf727908e3e35d0048962e94796f"; };

  };

}
#endif