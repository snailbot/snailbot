#ifndef _ROS_ardrone_autonomy_navdata_games_h
#define _ROS_ardrone_autonomy_navdata_games_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_games : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float drone_time;
      uint16_t tag;
      uint16_t size;
      uint32_t double_tap_counter;
      uint32_t finish_line_counter;

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
      *(outbuffer + offset + 0) = (this->double_tap_counter >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->double_tap_counter >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->double_tap_counter >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->double_tap_counter >> (8 * 3)) & 0xFF;
      offset += sizeof(this->double_tap_counter);
      *(outbuffer + offset + 0) = (this->finish_line_counter >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->finish_line_counter >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->finish_line_counter >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->finish_line_counter >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finish_line_counter);
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
      this->double_tap_counter =  ((uint32_t) (*(inbuffer + offset)));
      this->double_tap_counter |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->double_tap_counter |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->double_tap_counter |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->double_tap_counter);
      this->finish_line_counter =  ((uint32_t) (*(inbuffer + offset)));
      this->finish_line_counter |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->finish_line_counter |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->finish_line_counter |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->finish_line_counter);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_games"; };
    const char * getMD5(){ return "3b3ea3628a5ac44a2ed78d3ac0c1cf49"; };

  };

}
#endif