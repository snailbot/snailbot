#ifndef _ROS_bride_tutorials_TriggerPublishActionResult_h
#define _ROS_bride_tutorials_TriggerPublishActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "bride_tutorials/TriggerPublishResult.h"

namespace bride_tutorials
{

  class TriggerPublishActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      bride_tutorials::TriggerPublishResult result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "bride_tutorials/TriggerPublishActionResult"; };
    const char * getMD5(){ return "1eb06eeff08fa7ea874431638cb52332"; };

  };

}
#endif