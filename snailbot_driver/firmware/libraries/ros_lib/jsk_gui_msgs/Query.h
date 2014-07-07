#ifndef _ROS_SERVICE_Query_h
#define _ROS_SERVICE_Query_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

static const char QUERY[] = "jsk_gui_msgs/Query";

  class QueryRequest : public ros::Msg
  {
    public:
      int32_t id;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return QUERY; };
    const char * getMD5(){ return "c5e4a7d59c68f74eabcec876a00216aa"; };

  };

  class QueryResponse : public ros::Msg
  {
    public:
      char * res;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_res = strlen( (const char*) this->res);
      memcpy(outbuffer + offset, &length_res, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->res, length_res);
      offset += length_res;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_res;
      memcpy(&length_res, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_res; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_res-1]=0;
      this->res = (char *)(inbuffer + offset-1);
      offset += length_res;
     return offset;
    }

    const char * getType(){ return QUERY; };
    const char * getMD5(){ return "53af918a2a4a2a182c184142fff49b0c"; };

  };

  class Query {
    public:
    typedef QueryRequest Request;
    typedef QueryResponse Response;
  };

}
#endif
