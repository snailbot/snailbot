#ifndef _ROS_jsk_footstep_msgs_PlanFootstepsFeedback_h
#define _ROS_jsk_footstep_msgs_PlanFootstepsFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/FootstepArray.h"

namespace jsk_footstep_msgs
{

  class PlanFootstepsFeedback : public ros::Msg
  {
    public:
      jsk_footstep_msgs::FootstepArray feedback;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/PlanFootstepsFeedback"; };
    const char * getMD5(){ return "4d6b3eec05cb69fcc42319013eb20a28"; };

  };

}
#endif