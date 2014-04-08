#ifndef _ROS_SERVICE_SendWaypointList_h
#define _ROS_SERVICE_SendWaypointList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "roscopter/Waypoint.h"

namespace roscopter
{

static const char SENDWAYPOINTLIST[] = "roscopter/SendWaypointList";

  class SendWaypointListRequest : public ros::Msg
  {
    public:
      uint8_t waypoints_length;
      roscopter::Waypoint st_waypoints;
      roscopter::Waypoint * waypoints;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = waypoints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < waypoints_length; i++){
      offset += this->waypoints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t waypoints_lengthT = *(inbuffer + offset++);
      if(waypoints_lengthT > waypoints_length)
        this->waypoints = (roscopter::Waypoint*)realloc(this->waypoints, waypoints_lengthT * sizeof(roscopter::Waypoint));
      offset += 3;
      waypoints_length = waypoints_lengthT;
      for( uint8_t i = 0; i < waypoints_length; i++){
      offset += this->st_waypoints.deserialize(inbuffer + offset);
        memcpy( &(this->waypoints[i]), &(this->st_waypoints), sizeof(roscopter::Waypoint));
      }
     return offset;
    }

    const char * getType(){ return SENDWAYPOINTLIST; };
    const char * getMD5(){ return "55f6e3d4649782ff855bc4699f0b61df"; };

  };

  class SendWaypointListResponse : public ros::Msg
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

    const char * getType(){ return SENDWAYPOINTLIST; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SendWaypointList {
    public:
    typedef SendWaypointListRequest Request;
    typedef SendWaypointListResponse Response;
  };

}
#endif
