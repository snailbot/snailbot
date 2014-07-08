#ifndef _ROS_SERVICE_ToENU_h
#define _ROS_SERVICE_ToENU_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/Point.h"

namespace enu
{

static const char TOENU[] = "enu/ToENU";

  class ToENURequest : public ros::Msg
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

    const char * getType(){ return TOENU; };
    const char * getMD5(){ return "592b2fb1c3dae6914312f4d61150e699"; };

  };

  class ToENUResponse : public ros::Msg
  {
    public:
      geometry_msgs::Point enu;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->enu.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->enu.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return TOENU; };
    const char * getMD5(){ return "4062be16f7c9b6baec88f3c98545e83a"; };

  };

  class ToENU {
    public:
    typedef ToENURequest Request;
    typedef ToENUResponse Response;
  };

}
#endif
