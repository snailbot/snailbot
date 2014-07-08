#ifndef _ROS_jsk_footstep_msgs_ExecFootstepsGoal_h
#define _ROS_jsk_footstep_msgs_ExecFootstepsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/FootstepArray.h"

namespace jsk_footstep_msgs
{

  class ExecFootstepsGoal : public ros::Msg
  {
    public:
      jsk_footstep_msgs::FootstepArray footstep;
      uint8_t strategy;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->footstep.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->strategy >> (8 * 0)) & 0xFF;
      offset += sizeof(this->strategy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->footstep.deserialize(inbuffer + offset);
      this->strategy =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->strategy);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/ExecFootstepsGoal"; };
    const char * getMD5(){ return "76dc34a2156d1a4ceb07b9fca9bb3e7b"; };

  };

}
#endif