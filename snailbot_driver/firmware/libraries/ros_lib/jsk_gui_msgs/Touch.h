#ifndef _ROS_jsk_gui_msgs_Touch_h
#define _ROS_jsk_gui_msgs_Touch_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

  class Touch : public ros::Msg
  {
    public:
      int64_t finger_id;
      float x;
      float y;
      int64_t image_width;
      int64_t image_height;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_finger_id;
      u_finger_id.real = this->finger_id;
      *(outbuffer + offset + 0) = (u_finger_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_finger_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_finger_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_finger_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_finger_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_finger_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_finger_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_finger_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->finger_id);
      int32_t * val_x = (int32_t *) &(this->x);
      int32_t exp_x = (((*val_x)>>23)&255);
      if(exp_x != 0)
        exp_x += 1023-127;
      int32_t sig_x = *val_x;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_x<<5) & 0xff;
      *(outbuffer + offset++) = (sig_x>>3) & 0xff;
      *(outbuffer + offset++) = (sig_x>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_x<<4) & 0xF0) | ((sig_x>>19)&0x0F);
      *(outbuffer + offset++) = (exp_x>>4) & 0x7F;
      if(this->x < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_y = (int32_t *) &(this->y);
      int32_t exp_y = (((*val_y)>>23)&255);
      if(exp_y != 0)
        exp_y += 1023-127;
      int32_t sig_y = *val_y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_y<<4) & 0xF0) | ((sig_y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_y>>4) & 0x7F;
      if(this->y < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        int64_t real;
        uint64_t base;
      } u_image_width;
      u_image_width.real = this->image_width;
      *(outbuffer + offset + 0) = (u_image_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_width.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_image_width.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_image_width.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_image_width.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_image_width.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->image_width);
      union {
        int64_t real;
        uint64_t base;
      } u_image_height;
      u_image_height.real = this->image_height;
      *(outbuffer + offset + 0) = (u_image_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_image_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_image_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_image_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_image_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->image_height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_finger_id;
      u_finger_id.base = 0;
      u_finger_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_finger_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_finger_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_finger_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_finger_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_finger_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_finger_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_finger_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->finger_id = u_finger_id.real;
      offset += sizeof(this->finger_id);
      uint32_t * val_x = (uint32_t*) &(this->x);
      offset += 3;
      *val_x = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_x |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_x = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_x |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_x !=0)
        *val_x |= ((exp_x)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->x = -this->x;
      uint32_t * val_y = (uint32_t*) &(this->y);
      offset += 3;
      *val_y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_y !=0)
        *val_y |= ((exp_y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->y = -this->y;
      union {
        int64_t real;
        uint64_t base;
      } u_image_width;
      u_image_width.base = 0;
      u_image_width.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_width.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_width.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_width.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_image_width.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_image_width.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_image_width.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_image_width.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->image_width = u_image_width.real;
      offset += sizeof(this->image_width);
      union {
        int64_t real;
        uint64_t base;
      } u_image_height;
      u_image_height.base = 0;
      u_image_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_image_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_image_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_image_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_image_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->image_height = u_image_height.real;
      offset += sizeof(this->image_height);
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/Touch"; };
    const char * getMD5(){ return "d96a284d39fcc410f375ac68fd380177"; };

  };

}
#endif