#ifndef _ROS_ardrone_autonomy_navdata_rc_references_h
#define _ROS_ardrone_autonomy_navdata_rc_references_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_rc_references : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float drone_time;
      uint16_t tag;
      uint16_t size;
      int32_t rc_ref_pitch;
      int32_t rc_ref_roll;
      int32_t rc_ref_yaw;
      int32_t rc_ref_gaz;
      int32_t rc_ref_ag;

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
      } u_rc_ref_pitch;
      u_rc_ref_pitch.real = this->rc_ref_pitch;
      *(outbuffer + offset + 0) = (u_rc_ref_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rc_ref_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rc_ref_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rc_ref_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rc_ref_pitch);
      union {
        int32_t real;
        uint32_t base;
      } u_rc_ref_roll;
      u_rc_ref_roll.real = this->rc_ref_roll;
      *(outbuffer + offset + 0) = (u_rc_ref_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rc_ref_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rc_ref_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rc_ref_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rc_ref_roll);
      union {
        int32_t real;
        uint32_t base;
      } u_rc_ref_yaw;
      u_rc_ref_yaw.real = this->rc_ref_yaw;
      *(outbuffer + offset + 0) = (u_rc_ref_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rc_ref_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rc_ref_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rc_ref_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rc_ref_yaw);
      union {
        int32_t real;
        uint32_t base;
      } u_rc_ref_gaz;
      u_rc_ref_gaz.real = this->rc_ref_gaz;
      *(outbuffer + offset + 0) = (u_rc_ref_gaz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rc_ref_gaz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rc_ref_gaz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rc_ref_gaz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rc_ref_gaz);
      union {
        int32_t real;
        uint32_t base;
      } u_rc_ref_ag;
      u_rc_ref_ag.real = this->rc_ref_ag;
      *(outbuffer + offset + 0) = (u_rc_ref_ag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rc_ref_ag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rc_ref_ag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rc_ref_ag.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rc_ref_ag);
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
      } u_rc_ref_pitch;
      u_rc_ref_pitch.base = 0;
      u_rc_ref_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rc_ref_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rc_ref_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rc_ref_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rc_ref_pitch = u_rc_ref_pitch.real;
      offset += sizeof(this->rc_ref_pitch);
      union {
        int32_t real;
        uint32_t base;
      } u_rc_ref_roll;
      u_rc_ref_roll.base = 0;
      u_rc_ref_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rc_ref_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rc_ref_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rc_ref_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rc_ref_roll = u_rc_ref_roll.real;
      offset += sizeof(this->rc_ref_roll);
      union {
        int32_t real;
        uint32_t base;
      } u_rc_ref_yaw;
      u_rc_ref_yaw.base = 0;
      u_rc_ref_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rc_ref_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rc_ref_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rc_ref_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rc_ref_yaw = u_rc_ref_yaw.real;
      offset += sizeof(this->rc_ref_yaw);
      union {
        int32_t real;
        uint32_t base;
      } u_rc_ref_gaz;
      u_rc_ref_gaz.base = 0;
      u_rc_ref_gaz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rc_ref_gaz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rc_ref_gaz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rc_ref_gaz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rc_ref_gaz = u_rc_ref_gaz.real;
      offset += sizeof(this->rc_ref_gaz);
      union {
        int32_t real;
        uint32_t base;
      } u_rc_ref_ag;
      u_rc_ref_ag.base = 0;
      u_rc_ref_ag.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rc_ref_ag.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rc_ref_ag.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rc_ref_ag.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rc_ref_ag = u_rc_ref_ag.real;
      offset += sizeof(this->rc_ref_ag);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_rc_references"; };
    const char * getMD5(){ return "57eebe7ce3b678ed3cfbdcf4646ffe93"; };

  };

}
#endif