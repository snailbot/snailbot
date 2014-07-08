#ifndef _ROS_jsk_topic_tools_TopicInfo_h
#define _ROS_jsk_topic_tools_TopicInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_topic_tools
{

  class TopicInfo : public ros::Msg
  {
    public:
      char * topic_name;
      float rate;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic_name = strlen( (const char*) this->topic_name);
      memcpy(outbuffer + offset, &length_topic_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_topic_name);
      offset += length_topic_name;
      int32_t * val_rate = (int32_t *) &(this->rate);
      int32_t exp_rate = (((*val_rate)>>23)&255);
      if(exp_rate != 0)
        exp_rate += 1023-127;
      int32_t sig_rate = *val_rate;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_rate<<5) & 0xff;
      *(outbuffer + offset++) = (sig_rate>>3) & 0xff;
      *(outbuffer + offset++) = (sig_rate>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_rate<<4) & 0xF0) | ((sig_rate>>19)&0x0F);
      *(outbuffer + offset++) = (exp_rate>>4) & 0x7F;
      if(this->rate < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic_name;
      memcpy(&length_topic_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic_name-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
      offset += length_topic_name;
      uint32_t * val_rate = (uint32_t*) &(this->rate);
      offset += 3;
      *val_rate = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_rate |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_rate |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_rate |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_rate = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_rate |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_rate !=0)
        *val_rate |= ((exp_rate)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->rate = -this->rate;
     return offset;
    }

    const char * getType(){ return "jsk_topic_tools/TopicInfo"; };
    const char * getMD5(){ return "78edf14defd72c2fcd29e4fad0165ea9"; };

  };

}
#endif