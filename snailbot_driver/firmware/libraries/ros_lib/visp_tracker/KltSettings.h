#ifndef _ROS_visp_tracker_KltSettings_h
#define _ROS_visp_tracker_KltSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_tracker
{

  class KltSettings : public ros::Msg
  {
    public:
      int64_t max_features;
      int64_t window_size;
      float quality;
      float min_distance;
      float harris;
      int64_t size_block;
      int64_t pyramid_lvl;
      float angle_appear;
      float angle_disappear;
      int64_t mask_border;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_max_features;
      u_max_features.real = this->max_features;
      *(outbuffer + offset + 0) = (u_max_features.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_features.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_features.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_features.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_features.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_features.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_features.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_features.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_features);
      union {
        int64_t real;
        uint64_t base;
      } u_window_size;
      u_window_size.real = this->window_size;
      *(outbuffer + offset + 0) = (u_window_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_window_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_window_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_window_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_window_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_window_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_window_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_window_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->window_size);
      int32_t * val_quality = (int32_t *) &(this->quality);
      int32_t exp_quality = (((*val_quality)>>23)&255);
      if(exp_quality != 0)
        exp_quality += 1023-127;
      int32_t sig_quality = *val_quality;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_quality<<5) & 0xff;
      *(outbuffer + offset++) = (sig_quality>>3) & 0xff;
      *(outbuffer + offset++) = (sig_quality>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_quality<<4) & 0xF0) | ((sig_quality>>19)&0x0F);
      *(outbuffer + offset++) = (exp_quality>>4) & 0x7F;
      if(this->quality < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_min_distance = (int32_t *) &(this->min_distance);
      int32_t exp_min_distance = (((*val_min_distance)>>23)&255);
      if(exp_min_distance != 0)
        exp_min_distance += 1023-127;
      int32_t sig_min_distance = *val_min_distance;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_min_distance<<5) & 0xff;
      *(outbuffer + offset++) = (sig_min_distance>>3) & 0xff;
      *(outbuffer + offset++) = (sig_min_distance>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_min_distance<<4) & 0xF0) | ((sig_min_distance>>19)&0x0F);
      *(outbuffer + offset++) = (exp_min_distance>>4) & 0x7F;
      if(this->min_distance < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_harris = (int32_t *) &(this->harris);
      int32_t exp_harris = (((*val_harris)>>23)&255);
      if(exp_harris != 0)
        exp_harris += 1023-127;
      int32_t sig_harris = *val_harris;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_harris<<5) & 0xff;
      *(outbuffer + offset++) = (sig_harris>>3) & 0xff;
      *(outbuffer + offset++) = (sig_harris>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_harris<<4) & 0xF0) | ((sig_harris>>19)&0x0F);
      *(outbuffer + offset++) = (exp_harris>>4) & 0x7F;
      if(this->harris < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        int64_t real;
        uint64_t base;
      } u_size_block;
      u_size_block.real = this->size_block;
      *(outbuffer + offset + 0) = (u_size_block.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size_block.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size_block.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size_block.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_size_block.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_size_block.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_size_block.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_size_block.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->size_block);
      union {
        int64_t real;
        uint64_t base;
      } u_pyramid_lvl;
      u_pyramid_lvl.real = this->pyramid_lvl;
      *(outbuffer + offset + 0) = (u_pyramid_lvl.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pyramid_lvl.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pyramid_lvl.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pyramid_lvl.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pyramid_lvl.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pyramid_lvl.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pyramid_lvl.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pyramid_lvl.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pyramid_lvl);
      int32_t * val_angle_appear = (int32_t *) &(this->angle_appear);
      int32_t exp_angle_appear = (((*val_angle_appear)>>23)&255);
      if(exp_angle_appear != 0)
        exp_angle_appear += 1023-127;
      int32_t sig_angle_appear = *val_angle_appear;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_angle_appear<<5) & 0xff;
      *(outbuffer + offset++) = (sig_angle_appear>>3) & 0xff;
      *(outbuffer + offset++) = (sig_angle_appear>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_angle_appear<<4) & 0xF0) | ((sig_angle_appear>>19)&0x0F);
      *(outbuffer + offset++) = (exp_angle_appear>>4) & 0x7F;
      if(this->angle_appear < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_angle_disappear = (int32_t *) &(this->angle_disappear);
      int32_t exp_angle_disappear = (((*val_angle_disappear)>>23)&255);
      if(exp_angle_disappear != 0)
        exp_angle_disappear += 1023-127;
      int32_t sig_angle_disappear = *val_angle_disappear;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_angle_disappear<<5) & 0xff;
      *(outbuffer + offset++) = (sig_angle_disappear>>3) & 0xff;
      *(outbuffer + offset++) = (sig_angle_disappear>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_angle_disappear<<4) & 0xF0) | ((sig_angle_disappear>>19)&0x0F);
      *(outbuffer + offset++) = (exp_angle_disappear>>4) & 0x7F;
      if(this->angle_disappear < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        int64_t real;
        uint64_t base;
      } u_mask_border;
      u_mask_border.real = this->mask_border;
      *(outbuffer + offset + 0) = (u_mask_border.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mask_border.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mask_border.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mask_border.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mask_border.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mask_border.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mask_border.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mask_border.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mask_border);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_max_features;
      u_max_features.base = 0;
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_features = u_max_features.real;
      offset += sizeof(this->max_features);
      union {
        int64_t real;
        uint64_t base;
      } u_window_size;
      u_window_size.base = 0;
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->window_size = u_window_size.real;
      offset += sizeof(this->window_size);
      uint32_t * val_quality = (uint32_t*) &(this->quality);
      offset += 3;
      *val_quality = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_quality |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_quality |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_quality |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_quality = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_quality |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_quality !=0)
        *val_quality |= ((exp_quality)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->quality = -this->quality;
      uint32_t * val_min_distance = (uint32_t*) &(this->min_distance);
      offset += 3;
      *val_min_distance = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_min_distance |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_min_distance |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_min_distance |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_min_distance = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_min_distance |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_min_distance !=0)
        *val_min_distance |= ((exp_min_distance)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->min_distance = -this->min_distance;
      uint32_t * val_harris = (uint32_t*) &(this->harris);
      offset += 3;
      *val_harris = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_harris |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_harris |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_harris |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_harris = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_harris |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_harris !=0)
        *val_harris |= ((exp_harris)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->harris = -this->harris;
      union {
        int64_t real;
        uint64_t base;
      } u_size_block;
      u_size_block.base = 0;
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->size_block = u_size_block.real;
      offset += sizeof(this->size_block);
      union {
        int64_t real;
        uint64_t base;
      } u_pyramid_lvl;
      u_pyramid_lvl.base = 0;
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pyramid_lvl = u_pyramid_lvl.real;
      offset += sizeof(this->pyramid_lvl);
      uint32_t * val_angle_appear = (uint32_t*) &(this->angle_appear);
      offset += 3;
      *val_angle_appear = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_angle_appear |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_angle_appear |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_angle_appear |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_angle_appear = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_angle_appear |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_angle_appear !=0)
        *val_angle_appear |= ((exp_angle_appear)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->angle_appear = -this->angle_appear;
      uint32_t * val_angle_disappear = (uint32_t*) &(this->angle_disappear);
      offset += 3;
      *val_angle_disappear = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_angle_disappear |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_angle_disappear |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_angle_disappear |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_angle_disappear = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_angle_disappear |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_angle_disappear !=0)
        *val_angle_disappear |= ((exp_angle_disappear)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->angle_disappear = -this->angle_disappear;
      union {
        int64_t real;
        uint64_t base;
      } u_mask_border;
      u_mask_border.base = 0;
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mask_border = u_mask_border.real;
      offset += sizeof(this->mask_border);
     return offset;
    }

    const char * getType(){ return "visp_tracker/KltSettings"; };
    const char * getMD5(){ return "a9f61cd7210b4d3872b77b5d1101b830"; };

  };

}
#endif