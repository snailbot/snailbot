#ifndef _ROS_SERVICE_ToFix_h
#define _ROS_SERVICE_ToFix_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/Point.h"

namespace enu
{

static const char TOFIX[] = "enu/ToFix";

  class ToFixRequest : public ros::Msg
  {
    public:
      sensor_msgs::NavSatFix datum;
      geometry_msgs::Point point;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->datum.serialize(outbuffer + offset);
      offset += this->point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->datum.deserialize(inbuffer + offset);
      offset += this->point.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return TOFIX; };
    const char * getMD5(){ return "3895afeb4fe55c8f0465121433ad3433"; };

  };

  class ToFixResponse : public ros::Msg
  {
    public:
      sensor_msgs::NavSatFix llh;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->llh.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->llh.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return TOFIX; };
    const char * getMD5(){ return "9d0ef44e13c23297afc80f2b6dfc1f59"; };

  };

  class ToFix {
    public:
    typedef ToFixRequest Request;
    typedef ToFixResponse Response;
  };

}
#endif
