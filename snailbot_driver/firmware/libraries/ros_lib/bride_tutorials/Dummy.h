#ifndef _ROS_bride_tutorials_Dummy_h
#define _ROS_bride_tutorials_Dummy_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace bride_tutorials
{

  class Dummy : public ros::Msg
  {
    public:
      std_msgs::String test;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->test.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->test.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "bride_tutorials/Dummy"; };
    const char * getMD5(){ return "32d3b9460cad5e978182329b07548806"; };

  };

}
#endif