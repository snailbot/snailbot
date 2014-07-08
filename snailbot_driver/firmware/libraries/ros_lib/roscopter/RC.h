#ifndef _ROS_roscopter_RC_h
#define _ROS_roscopter_RC_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscopter
{

  class RC : public ros::Msg
  {
    public:
      uint32_t channel[8];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned char * channel_val = (unsigned char *) this->channel;
      for( uint8_t i = 0; i < 8; i++){
      *(outbuffer + offset + 0) = (this->channel[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channel[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channel[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channel[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channel[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t * channel_val = (uint8_t*) this->channel;
      for( uint8_t i = 0; i < 8; i++){
      this->channel[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->channel[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->channel[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->channel[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->channel[i]);
      }
     return offset;
    }

    const char * getType(){ return "roscopter/RC"; };
    const char * getMD5(){ return "a40d8c478f8d8fdeb5a2f988302e5696"; };

  };

}
#endif