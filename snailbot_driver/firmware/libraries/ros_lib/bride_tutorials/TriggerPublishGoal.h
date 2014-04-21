#ifndef _ROS_bride_tutorials_TriggerPublishGoal_h
#define _ROS_bride_tutorials_TriggerPublishGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bride_tutorials
{

  class TriggerPublishGoal : public ros::Msg
  {
    public:
      uint32_t test;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->test >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->test >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->test >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->test >> (8 * 3)) & 0xFF;
      offset += sizeof(this->test);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->test =  ((uint32_t) (*(inbuffer + offset)));
      this->test |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->test |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->test |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->test);
     return offset;
    }

    const char * getType(){ return "bride_tutorials/TriggerPublishGoal"; };
    const char * getMD5(){ return "b66fa90afc91116f90d9ebb7313af521"; };

  };

}
#endif