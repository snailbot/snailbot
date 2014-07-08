#ifndef _ROS_visp_tracker_MovingEdgeSettings_h
#define _ROS_visp_tracker_MovingEdgeSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_tracker
{

  class MovingEdgeSettings : public ros::Msg
  {
    public:
      int64_t mask_size;
      int64_t n_mask;
      int64_t range;
      float threshold;
      float mu1;
      float mu2;
      int64_t sample_step;
      int64_t ntotal_sample;
      int64_t strip;
      float min_samplestep;
      float aberration;
      float init_aberration;
      float lambda;
      float first_threshold;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mask_size;
      u_mask_size.real = this->mask_size;
      *(outbuffer + offset + 0) = (u_mask_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mask_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mask_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mask_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mask_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mask_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mask_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mask_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mask_size);
      union {
        int64_t real;
        uint64_t base;
      } u_n_mask;
      u_n_mask.real = this->n_mask;
      *(outbuffer + offset + 0) = (u_n_mask.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_n_mask.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_n_mask.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_n_mask.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_n_mask.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_n_mask.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_n_mask.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_n_mask.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->n_mask);
      union {
        int64_t real;
        uint64_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_range.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_range.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_range.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_range.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->range);
      int32_t * val_threshold = (int32_t *) &(this->threshold);
      int32_t exp_threshold = (((*val_threshold)>>23)&255);
      if(exp_threshold != 0)
        exp_threshold += 1023-127;
      int32_t sig_threshold = *val_threshold;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_threshold<<5) & 0xff;
      *(outbuffer + offset++) = (sig_threshold>>3) & 0xff;
      *(outbuffer + offset++) = (sig_threshold>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_threshold<<4) & 0xF0) | ((sig_threshold>>19)&0x0F);
      *(outbuffer + offset++) = (exp_threshold>>4) & 0x7F;
      if(this->threshold < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_mu1 = (int32_t *) &(this->mu1);
      int32_t exp_mu1 = (((*val_mu1)>>23)&255);
      if(exp_mu1 != 0)
        exp_mu1 += 1023-127;
      int32_t sig_mu1 = *val_mu1;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_mu1<<5) & 0xff;
      *(outbuffer + offset++) = (sig_mu1>>3) & 0xff;
      *(outbuffer + offset++) = (sig_mu1>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_mu1<<4) & 0xF0) | ((sig_mu1>>19)&0x0F);
      *(outbuffer + offset++) = (exp_mu1>>4) & 0x7F;
      if(this->mu1 < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_mu2 = (int32_t *) &(this->mu2);
      int32_t exp_mu2 = (((*val_mu2)>>23)&255);
      if(exp_mu2 != 0)
        exp_mu2 += 1023-127;
      int32_t sig_mu2 = *val_mu2;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_mu2<<5) & 0xff;
      *(outbuffer + offset++) = (sig_mu2>>3) & 0xff;
      *(outbuffer + offset++) = (sig_mu2>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_mu2<<4) & 0xF0) | ((sig_mu2>>19)&0x0F);
      *(outbuffer + offset++) = (exp_mu2>>4) & 0x7F;
      if(this->mu2 < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        int64_t real;
        uint64_t base;
      } u_sample_step;
      u_sample_step.real = this->sample_step;
      *(outbuffer + offset + 0) = (u_sample_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sample_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sample_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sample_step.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sample_step.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sample_step.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sample_step.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sample_step.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sample_step);
      union {
        int64_t real;
        uint64_t base;
      } u_ntotal_sample;
      u_ntotal_sample.real = this->ntotal_sample;
      *(outbuffer + offset + 0) = (u_ntotal_sample.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ntotal_sample.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ntotal_sample.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ntotal_sample.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ntotal_sample.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ntotal_sample.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ntotal_sample.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ntotal_sample.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ntotal_sample);
      union {
        int64_t real;
        uint64_t base;
      } u_strip;
      u_strip.real = this->strip;
      *(outbuffer + offset + 0) = (u_strip.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strip.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strip.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strip.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_strip.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_strip.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_strip.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_strip.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->strip);
      int32_t * val_min_samplestep = (int32_t *) &(this->min_samplestep);
      int32_t exp_min_samplestep = (((*val_min_samplestep)>>23)&255);
      if(exp_min_samplestep != 0)
        exp_min_samplestep += 1023-127;
      int32_t sig_min_samplestep = *val_min_samplestep;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_min_samplestep<<5) & 0xff;
      *(outbuffer + offset++) = (sig_min_samplestep>>3) & 0xff;
      *(outbuffer + offset++) = (sig_min_samplestep>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_min_samplestep<<4) & 0xF0) | ((sig_min_samplestep>>19)&0x0F);
      *(outbuffer + offset++) = (exp_min_samplestep>>4) & 0x7F;
      if(this->min_samplestep < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_aberration = (int32_t *) &(this->aberration);
      int32_t exp_aberration = (((*val_aberration)>>23)&255);
      if(exp_aberration != 0)
        exp_aberration += 1023-127;
      int32_t sig_aberration = *val_aberration;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_aberration<<5) & 0xff;
      *(outbuffer + offset++) = (sig_aberration>>3) & 0xff;
      *(outbuffer + offset++) = (sig_aberration>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_aberration<<4) & 0xF0) | ((sig_aberration>>19)&0x0F);
      *(outbuffer + offset++) = (exp_aberration>>4) & 0x7F;
      if(this->aberration < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_init_aberration = (int32_t *) &(this->init_aberration);
      int32_t exp_init_aberration = (((*val_init_aberration)>>23)&255);
      if(exp_init_aberration != 0)
        exp_init_aberration += 1023-127;
      int32_t sig_init_aberration = *val_init_aberration;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_init_aberration<<5) & 0xff;
      *(outbuffer + offset++) = (sig_init_aberration>>3) & 0xff;
      *(outbuffer + offset++) = (sig_init_aberration>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_init_aberration<<4) & 0xF0) | ((sig_init_aberration>>19)&0x0F);
      *(outbuffer + offset++) = (exp_init_aberration>>4) & 0x7F;
      if(this->init_aberration < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_lambda = (int32_t *) &(this->lambda);
      int32_t exp_lambda = (((*val_lambda)>>23)&255);
      if(exp_lambda != 0)
        exp_lambda += 1023-127;
      int32_t sig_lambda = *val_lambda;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_lambda<<5) & 0xff;
      *(outbuffer + offset++) = (sig_lambda>>3) & 0xff;
      *(outbuffer + offset++) = (sig_lambda>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_lambda<<4) & 0xF0) | ((sig_lambda>>19)&0x0F);
      *(outbuffer + offset++) = (exp_lambda>>4) & 0x7F;
      if(this->lambda < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_first_threshold = (int32_t *) &(this->first_threshold);
      int32_t exp_first_threshold = (((*val_first_threshold)>>23)&255);
      if(exp_first_threshold != 0)
        exp_first_threshold += 1023-127;
      int32_t sig_first_threshold = *val_first_threshold;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_first_threshold<<5) & 0xff;
      *(outbuffer + offset++) = (sig_first_threshold>>3) & 0xff;
      *(outbuffer + offset++) = (sig_first_threshold>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_first_threshold<<4) & 0xF0) | ((sig_first_threshold>>19)&0x0F);
      *(outbuffer + offset++) = (exp_first_threshold>>4) & 0x7F;
      if(this->first_threshold < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mask_size;
      u_mask_size.base = 0;
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mask_size = u_mask_size.real;
      offset += sizeof(this->mask_size);
      union {
        int64_t real;
        uint64_t base;
      } u_n_mask;
      u_n_mask.base = 0;
      u_n_mask.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_n_mask.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_n_mask.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_n_mask.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_n_mask.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_n_mask.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_n_mask.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_n_mask.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->n_mask = u_n_mask.real;
      offset += sizeof(this->n_mask);
      union {
        int64_t real;
        uint64_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->range = u_range.real;
      offset += sizeof(this->range);
      uint32_t * val_threshold = (uint32_t*) &(this->threshold);
      offset += 3;
      *val_threshold = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_threshold |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_threshold |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_threshold |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_threshold = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_threshold |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_threshold !=0)
        *val_threshold |= ((exp_threshold)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->threshold = -this->threshold;
      uint32_t * val_mu1 = (uint32_t*) &(this->mu1);
      offset += 3;
      *val_mu1 = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_mu1 |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_mu1 |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_mu1 |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_mu1 = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_mu1 |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_mu1 !=0)
        *val_mu1 |= ((exp_mu1)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->mu1 = -this->mu1;
      uint32_t * val_mu2 = (uint32_t*) &(this->mu2);
      offset += 3;
      *val_mu2 = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_mu2 |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_mu2 |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_mu2 |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_mu2 = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_mu2 |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_mu2 !=0)
        *val_mu2 |= ((exp_mu2)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->mu2 = -this->mu2;
      union {
        int64_t real;
        uint64_t base;
      } u_sample_step;
      u_sample_step.base = 0;
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sample_step = u_sample_step.real;
      offset += sizeof(this->sample_step);
      union {
        int64_t real;
        uint64_t base;
      } u_ntotal_sample;
      u_ntotal_sample.base = 0;
      u_ntotal_sample.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ntotal_sample.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ntotal_sample.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ntotal_sample.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ntotal_sample.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ntotal_sample.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ntotal_sample.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ntotal_sample.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ntotal_sample = u_ntotal_sample.real;
      offset += sizeof(this->ntotal_sample);
      union {
        int64_t real;
        uint64_t base;
      } u_strip;
      u_strip.base = 0;
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->strip = u_strip.real;
      offset += sizeof(this->strip);
      uint32_t * val_min_samplestep = (uint32_t*) &(this->min_samplestep);
      offset += 3;
      *val_min_samplestep = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_min_samplestep |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_min_samplestep |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_min_samplestep |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_min_samplestep = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_min_samplestep |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_min_samplestep !=0)
        *val_min_samplestep |= ((exp_min_samplestep)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->min_samplestep = -this->min_samplestep;
      uint32_t * val_aberration = (uint32_t*) &(this->aberration);
      offset += 3;
      *val_aberration = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_aberration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_aberration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_aberration |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_aberration = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_aberration |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_aberration !=0)
        *val_aberration |= ((exp_aberration)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->aberration = -this->aberration;
      uint32_t * val_init_aberration = (uint32_t*) &(this->init_aberration);
      offset += 3;
      *val_init_aberration = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_init_aberration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_init_aberration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_init_aberration |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_init_aberration = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_init_aberration |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_init_aberration !=0)
        *val_init_aberration |= ((exp_init_aberration)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->init_aberration = -this->init_aberration;
      uint32_t * val_lambda = (uint32_t*) &(this->lambda);
      offset += 3;
      *val_lambda = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_lambda |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_lambda |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_lambda |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_lambda = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_lambda |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_lambda !=0)
        *val_lambda |= ((exp_lambda)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->lambda = -this->lambda;
      uint32_t * val_first_threshold = (uint32_t*) &(this->first_threshold);
      offset += 3;
      *val_first_threshold = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_first_threshold |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_first_threshold |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_first_threshold |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_first_threshold = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_first_threshold |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_first_threshold !=0)
        *val_first_threshold |= ((exp_first_threshold)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->first_threshold = -this->first_threshold;
     return offset;
    }

    const char * getType(){ return "visp_tracker/MovingEdgeSettings"; };
    const char * getMD5(){ return "376fefab194f3282c421288b8a099b76"; };

  };

}
#endif