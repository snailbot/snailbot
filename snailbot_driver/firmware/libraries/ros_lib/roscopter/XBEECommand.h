#ifndef _ROS_SERVICE_XBEECommand_h
#define _ROS_SERVICE_XBEECommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscopter
{

static const char XBEECOMMAND[] = "roscopter/XBEECommand";

  class XBEECommandRequest : public ros::Msg
  {
    public:
      int8_t command;
      enum { STARTMISSION =  1 };
      enum { MISSIONFINISHED =  2 };
      enum { FAILSAFE =  3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command = u_command.real;
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return XBEECOMMAND; };
    const char * getMD5(){ return "4092736087ba4328fa7dc96a85fda7a6"; };

  };

  class XBEECommandResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return XBEECOMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class XBEECommand {
    public:
    typedef XBEECommandRequest Request;
    typedef XBEECommandResponse Response;
  };

}
#endif
