#ifndef _ROS_visp_camera_calibration_CalibPoint_h
#define _ROS_visp_camera_calibration_CalibPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_camera_calibration
{

  class CalibPoint : public ros::Msg
  {
    public:
      int32_t i;
      int32_t j;
      float X;
      float Y;
      float Z;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_i;
      u_i.real = this->i;
      *(outbuffer + offset + 0) = (u_i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i);
      union {
        int32_t real;
        uint32_t base;
      } u_j;
      u_j.real = this->j;
      *(outbuffer + offset + 0) = (u_j.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_j.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_j.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_j.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->j);
      int32_t * val_X = (int32_t *) &(this->X);
      int32_t exp_X = (((*val_X)>>23)&255);
      if(exp_X != 0)
        exp_X += 1023-127;
      int32_t sig_X = *val_X;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_X<<5) & 0xff;
      *(outbuffer + offset++) = (sig_X>>3) & 0xff;
      *(outbuffer + offset++) = (sig_X>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_X<<4) & 0xF0) | ((sig_X>>19)&0x0F);
      *(outbuffer + offset++) = (exp_X>>4) & 0x7F;
      if(this->X < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_Y = (int32_t *) &(this->Y);
      int32_t exp_Y = (((*val_Y)>>23)&255);
      if(exp_Y != 0)
        exp_Y += 1023-127;
      int32_t sig_Y = *val_Y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Y<<4) & 0xF0) | ((sig_Y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Y>>4) & 0x7F;
      if(this->Y < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_Z = (int32_t *) &(this->Z);
      int32_t exp_Z = (((*val_Z)>>23)&255);
      if(exp_Z != 0)
        exp_Z += 1023-127;
      int32_t sig_Z = *val_Z;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Z<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Z>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Z>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Z<<4) & 0xF0) | ((sig_Z>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Z>>4) & 0x7F;
      if(this->Z < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_i;
      u_i.base = 0;
      u_i.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->i = u_i.real;
      offset += sizeof(this->i);
      union {
        int32_t real;
        uint32_t base;
      } u_j;
      u_j.base = 0;
      u_j.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_j.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_j.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_j.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->j = u_j.real;
      offset += sizeof(this->j);
      uint32_t * val_X = (uint32_t*) &(this->X);
      offset += 3;
      *val_X = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_X |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_X |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_X |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_X = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_X |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_X !=0)
        *val_X |= ((exp_X)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->X = -this->X;
      uint32_t * val_Y = (uint32_t*) &(this->Y);
      offset += 3;
      *val_Y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Y !=0)
        *val_Y |= ((exp_Y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->Y = -this->Y;
      uint32_t * val_Z = (uint32_t*) &(this->Z);
      offset += 3;
      *val_Z = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Z |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Z |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Z |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Z = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Z |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Z !=0)
        *val_Z |= ((exp_Z)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->Z = -this->Z;
     return offset;
    }

    const char * getType(){ return "visp_camera_calibration/CalibPoint"; };
    const char * getMD5(){ return "9b9d41ff2127a593c07cec2a11858ac5"; };

  };

}
#endif