#ifndef _ROS_SERVICE_SendWaypoint_h
#define _ROS_SERVICE_SendWaypoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "roscopter/Waypoint.h"

namespace roscopter
{

static const char SENDWAYPOINT[] = "roscopter/SendWaypoint";

  class SendWaypointRequest : public ros::Msg
  {
    public:
      roscopter::Waypoint waypoint;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->waypoint.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->waypoint.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SENDWAYPOINT; };
    const char * getMD5(){ return "d5e91ece00199d55c16efd2c9c4801c9"; };

  };

  class SendWaypointResponse : public ros::Msg
  {
    public:
      bool result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return SENDWAYPOINT; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SendWaypoint {
    public:
    typedef SendWaypointRequest Request;
    typedef SendWaypointResponse Response;
  };

}
#endif
