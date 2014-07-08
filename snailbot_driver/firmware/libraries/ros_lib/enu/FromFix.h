#ifndef _ROS_SERVICE_FromFix_h
#define _ROS_SERVICE_FromFix_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/Point.h"

namespace enu
{

static const char FROMFIX[] = "enu/FromFix";

  class FromFixRequest : public ros::Msg
  {
    public:
      sensor_msgs::NavSatFix llh;
      sensor_msgs::NavSatFix datum;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->llh.serialize(outbuffer + offset);
      offset += this->datum.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->llh.deserialize(inbuffer + offset);
      offset += this->datum.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FROMFIX; };
    const char * getMD5(){ return "592b2fb1c3dae6914312f4d61150e699"; };

  };

  class FromFixResponse : public ros::Msg
  {
    public:
      geometry_msgs::Point point;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->point.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FROMFIX; };
    const char * getMD5(){ return "a7c84ff13976aa04656e56e300124444"; };

  };

  class FromFix {
    public:
    typedef FromFixRequest Request;
    typedef FromFixResponse Response;
  };

}
#endif
