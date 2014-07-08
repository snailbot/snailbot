#ifndef _ROS_SERVICE_APMCommand_h
#define _ROS_SERVICE_APMCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscopter
{

static const char APMCOMMAND[] = "roscopter/APMCommand";

  class APMCommandRequest : public ros::Msg
  {
    public:
      uint8_t command;
      enum { CMD_LAUNCH =  1 };
      enum { CMD_LAND =  2 };
      enum { CMD_ARM =  3 };
      enum { CMD_DISARM =  4 };
      enum { CMD_SET_MANUAL =  5 };
      enum { CMD_SET_HOLD =  6 };
      enum { CMD_SET_STABILIZE =  7 };
      enum { CMD_SET_ALT_HOLD =  8 };
      enum { CMD_SET_AUTO =  9 };
      enum { CMD_SET_LOITER =  10 };
      enum { CMD_SET_LAND =  11 };
      enum { RETURN_RC_CONTROL =  12 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return APMCOMMAND; };
    const char * getMD5(){ return "5fed6e2518fbd616c0121cc1328eefae"; };

  };

  class APMCommandResponse : public ros::Msg
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

    const char * getType(){ return APMCOMMAND; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class APMCommand {
    public:
    typedef APMCommandRequest Request;
    typedef APMCommandResponse Response;
  };

}
#endif
