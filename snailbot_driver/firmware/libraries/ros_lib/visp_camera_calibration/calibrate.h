#ifndef _ROS_SERVICE_calibrate_h
#define _ROS_SERVICE_calibrate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_camera_calibration
{

static const char CALIBRATE[] = "visp_camera_calibration/calibrate";

  class calibrateRequest : public ros::Msg
  {
    public:
      int32_t method;
      int32_t sample_width;
      int32_t sample_height;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_method;
      u_method.real = this->method;
      *(outbuffer + offset + 0) = (u_method.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_method.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_method.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_method.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->method);
      union {
        int32_t real;
        uint32_t base;
      } u_sample_width;
      u_sample_width.real = this->sample_width;
      *(outbuffer + offset + 0) = (u_sample_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sample_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sample_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sample_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sample_width);
      union {
        int32_t real;
        uint32_t base;
      } u_sample_height;
      u_sample_height.real = this->sample_height;
      *(outbuffer + offset + 0) = (u_sample_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sample_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sample_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sample_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sample_height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_method;
      u_method.base = 0;
      u_method.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_method.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_method.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_method.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->method = u_method.real;
      offset += sizeof(this->method);
      union {
        int32_t real;
        uint32_t base;
      } u_sample_width;
      u_sample_width.base = 0;
      u_sample_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sample_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sample_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sample_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sample_width = u_sample_width.real;
      offset += sizeof(this->sample_width);
      union {
        int32_t real;
        uint32_t base;
      } u_sample_height;
      u_sample_height.base = 0;
      u_sample_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sample_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sample_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sample_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sample_height = u_sample_height.real;
      offset += sizeof(this->sample_height);
     return offset;
    }

    const char * getType(){ return CALIBRATE; };
    const char * getMD5(){ return "7b57c459896a8f1f8df45a385acfc123"; };

  };

  class calibrateResponse : public ros::Msg
  {
    public:
      uint8_t stdDevErrs_length;
      float st_stdDevErrs;
      float * stdDevErrs;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = stdDevErrs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < stdDevErrs_length; i++){
      int32_t * val_stdDevErrsi = (int32_t *) &(this->stdDevErrs[i]);
      int32_t exp_stdDevErrsi = (((*val_stdDevErrsi)>>23)&255);
      if(exp_stdDevErrsi != 0)
        exp_stdDevErrsi += 1023-127;
      int32_t sig_stdDevErrsi = *val_stdDevErrsi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_stdDevErrsi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_stdDevErrsi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_stdDevErrsi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_stdDevErrsi<<4) & 0xF0) | ((sig_stdDevErrsi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_stdDevErrsi>>4) & 0x7F;
      if(this->stdDevErrs[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t stdDevErrs_lengthT = *(inbuffer + offset++);
      if(stdDevErrs_lengthT > stdDevErrs_length)
        this->stdDevErrs = (float*)realloc(this->stdDevErrs, stdDevErrs_lengthT * sizeof(float));
      offset += 3;
      stdDevErrs_length = stdDevErrs_lengthT;
      for( uint8_t i = 0; i < stdDevErrs_length; i++){
      uint32_t * val_st_stdDevErrs = (uint32_t*) &(this->st_stdDevErrs);
      offset += 3;
      *val_st_stdDevErrs = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_stdDevErrs |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_stdDevErrs |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_stdDevErrs |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_stdDevErrs = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_stdDevErrs |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_stdDevErrs !=0)
        *val_st_stdDevErrs |= ((exp_st_stdDevErrs)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_stdDevErrs = -this->st_stdDevErrs;
        memcpy( &(this->stdDevErrs[i]), &(this->st_stdDevErrs), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return CALIBRATE; };
    const char * getMD5(){ return "cd6d27af348dbd9b7530b010497f18b0"; };

  };

  class calibrate {
    public:
    typedef calibrateRequest Request;
    typedef calibrateResponse Response;
  };

}
#endif
