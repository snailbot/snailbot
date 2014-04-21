#ifndef _ROS_bride_tutorials_TriggerPublishActionGoal_h
#define _ROS_bride_tutorials_TriggerPublishActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "bride_tutorials/TriggerPublishGoal.h"

namespace bride_tutorials
{

  class TriggerPublishActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      bride_tutorials::TriggerPublishGoal goal;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "bride_tutorials/TriggerPublishActionGoal"; };
    const char * getMD5(){ return "ed0f1d742c325d7948ac6c1381ccc804"; };

  };

}
#endif