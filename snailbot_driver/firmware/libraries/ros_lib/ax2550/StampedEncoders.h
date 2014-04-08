#ifndef _ROS_ax2550_StampedEncoders_h
#define _ROS_ax2550_StampedEncoders_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ax2550/Encoders.h"

namespace ax2550
{

  class StampedEncoders : public ros::Msg
  {
    public:
      std_msgs::Header header;
      ax2550::Encoders encoders;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->encoders.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->encoders.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "ax2550/StampedEncoders"; };
    const char * getMD5(){ return "7c217717e3bf9ebebdee0e043bc42e56"; };

  };

}
#endif