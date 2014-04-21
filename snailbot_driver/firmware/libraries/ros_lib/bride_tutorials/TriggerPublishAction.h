#ifndef _ROS_bride_tutorials_TriggerPublishAction_h
#define _ROS_bride_tutorials_TriggerPublishAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "bride_tutorials/TriggerPublishActionGoal.h"
#include "bride_tutorials/TriggerPublishActionResult.h"
#include "bride_tutorials/TriggerPublishActionFeedback.h"

namespace bride_tutorials
{

  class TriggerPublishAction : public ros::Msg
  {
    public:
      bride_tutorials::TriggerPublishActionGoal action_goal;
      bride_tutorials::TriggerPublishActionResult action_result;
      bride_tutorials::TriggerPublishActionFeedback action_feedback;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "bride_tutorials/TriggerPublishAction"; };
    const char * getMD5(){ return "125b6c5b3d3654bddadf2855b275822e"; };

  };

}
#endif