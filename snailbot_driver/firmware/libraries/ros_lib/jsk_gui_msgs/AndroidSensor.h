#ifndef _ROS_jsk_gui_msgs_AndroidSensor_h
#define _ROS_jsk_gui_msgs_AndroidSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

  class AndroidSensor : public ros::Msg
  {
    public:
      float accel_x;
      float accel_y;
      float accel_z;
      float orientation_x;
      float orientation_y;
      float orientation_z;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_accel_x = (int32_t *) &(this->accel_x);
      int32_t exp_accel_x = (((*val_accel_x)>>23)&255);
      if(exp_accel_x != 0)
        exp_accel_x += 1023-127;
      int32_t sig_accel_x = *val_accel_x;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_accel_x<<5) & 0xff;
      *(outbuffer + offset++) = (sig_accel_x>>3) & 0xff;
      *(outbuffer + offset++) = (sig_accel_x>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_accel_x<<4) & 0xF0) | ((sig_accel_x>>19)&0x0F);
      *(outbuffer + offset++) = (exp_accel_x>>4) & 0x7F;
      if(this->accel_x < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_accel_y = (int32_t *) &(this->accel_y);
      int32_t exp_accel_y = (((*val_accel_y)>>23)&255);
      if(exp_accel_y != 0)
        exp_accel_y += 1023-127;
      int32_t sig_accel_y = *val_accel_y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_accel_y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_accel_y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_accel_y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_accel_y<<4) & 0xF0) | ((sig_accel_y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_accel_y>>4) & 0x7F;
      if(this->accel_y < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_accel_z = (int32_t *) &(this->accel_z);
      int32_t exp_accel_z = (((*val_accel_z)>>23)&255);
      if(exp_accel_z != 0)
        exp_accel_z += 1023-127;
      int32_t sig_accel_z = *val_accel_z;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_accel_z<<5) & 0xff;
      *(outbuffer + offset++) = (sig_accel_z>>3) & 0xff;
      *(outbuffer + offset++) = (sig_accel_z>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_accel_z<<4) & 0xF0) | ((sig_accel_z>>19)&0x0F);
      *(outbuffer + offset++) = (exp_accel_z>>4) & 0x7F;
      if(this->accel_z < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_orientation_x = (int32_t *) &(this->orientation_x);
      int32_t exp_orientation_x = (((*val_orientation_x)>>23)&255);
      if(exp_orientation_x != 0)
        exp_orientation_x += 1023-127;
      int32_t sig_orientation_x = *val_orientation_x;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_orientation_x<<5) & 0xff;
      *(outbuffer + offset++) = (sig_orientation_x>>3) & 0xff;
      *(outbuffer + offset++) = (sig_orientation_x>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_orientation_x<<4) & 0xF0) | ((sig_orientation_x>>19)&0x0F);
      *(outbuffer + offset++) = (exp_orientation_x>>4) & 0x7F;
      if(this->orientation_x < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_orientation_y = (int32_t *) &(this->orientation_y);
      int32_t exp_orientation_y = (((*val_orientation_y)>>23)&255);
      if(exp_orientation_y != 0)
        exp_orientation_y += 1023-127;
      int32_t sig_orientation_y = *val_orientation_y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_orientation_y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_orientation_y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_orientation_y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_orientation_y<<4) & 0xF0) | ((sig_orientation_y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_orientation_y>>4) & 0x7F;
      if(this->orientation_y < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_orientation_z = (int32_t *) &(this->orientation_z);
      int32_t exp_orientation_z = (((*val_orientation_z)>>23)&255);
      if(exp_orientation_z != 0)
        exp_orientation_z += 1023-127;
      int32_t sig_orientation_z = *val_orientation_z;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_orientation_z<<5) & 0xff;
      *(outbuffer + offset++) = (sig_orientation_z>>3) & 0xff;
      *(outbuffer + offset++) = (sig_orientation_z>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_orientation_z<<4) & 0xF0) | ((sig_orientation_z>>19)&0x0F);
      *(outbuffer + offset++) = (exp_orientation_z>>4) & 0x7F;
      if(this->orientation_z < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_accel_x = (uint32_t*) &(this->accel_x);
      offset += 3;
      *val_accel_x = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_accel_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_accel_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_accel_x |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_accel_x = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_accel_x |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_accel_x !=0)
        *val_accel_x |= ((exp_accel_x)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->accel_x = -this->accel_x;
      uint32_t * val_accel_y = (uint32_t*) &(this->accel_y);
      offset += 3;
      *val_accel_y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_accel_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_accel_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_accel_y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_accel_y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_accel_y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_accel_y !=0)
        *val_accel_y |= ((exp_accel_y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->accel_y = -this->accel_y;
      uint32_t * val_accel_z = (uint32_t*) &(this->accel_z);
      offset += 3;
      *val_accel_z = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_accel_z |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_accel_z |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_accel_z |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_accel_z = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_accel_z |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_accel_z !=0)
        *val_accel_z |= ((exp_accel_z)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->accel_z = -this->accel_z;
      uint32_t * val_orientation_x = (uint32_t*) &(this->orientation_x);
      offset += 3;
      *val_orientation_x = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_orientation_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_orientation_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_orientation_x |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_orientation_x = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_orientation_x |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_orientation_x !=0)
        *val_orientation_x |= ((exp_orientation_x)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->orientation_x = -this->orientation_x;
      uint32_t * val_orientation_y = (uint32_t*) &(this->orientation_y);
      offset += 3;
      *val_orientation_y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_orientation_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_orientation_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_orientation_y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_orientation_y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_orientation_y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_orientation_y !=0)
        *val_orientation_y |= ((exp_orientation_y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->orientation_y = -this->orientation_y;
      uint32_t * val_orientation_z = (uint32_t*) &(this->orientation_z);
      offset += 3;
      *val_orientation_z = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_orientation_z |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_orientation_z |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_orientation_z |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_orientation_z = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_orientation_z |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_orientation_z !=0)
        *val_orientation_z |= ((exp_orientation_z)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->orientation_z = -this->orientation_z;
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/AndroidSensor"; };
    const char * getMD5(){ return "d832dbe3be7e7f061d963f2188f1a407"; };

  };

}
#endif