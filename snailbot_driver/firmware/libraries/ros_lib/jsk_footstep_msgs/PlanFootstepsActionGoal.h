#ifndef _ROS_jsk_footstep_msgs_PlanFootstepsActionGoal_h
#define _ROS_jsk_footstep_msgs_PlanFootstepsActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "jsk_footstep_msgs/PlanFootstepsGoal.h"

namespace jsk_footstep_msgs
{

  class PlanFootstepsActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      jsk_footstep_msgs::PlanFootstepsGoal goal;

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

    const char * getType(){ return "jsk_footstep_msgs/PlanFootstepsActionGoal"; };
    const char * getMD5(){ return "06dc3199b8be5553c53f9a66d9c9391d"; };

  };

}
#endif