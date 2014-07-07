#ifndef _ROS_roscopter_State_h
#define _ROS_roscopter_State_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscopter
{

  class State : public ros::Msg
  {
    public:
      bool armed;
      bool guided;
      char * mode;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_armed;
      u_armed.real = this->armed;
      *(outbuffer + offset + 0) = (u_armed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->armed);
      union {
        bool real;
        uint8_t base;
      } u_guided;
      u_guided.real = this->guided;
      *(outbuffer + offset + 0) = (u_guided.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->guided);
      uint32_t length_mode = strlen( (const char*) this->mode);
      memcpy(outbuffer + offset, &length_mode, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mode, length_mode);
      offset += length_mode;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_armed;
      u_armed.base = 0;
      u_armed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->armed = u_armed.real;
      offset += sizeof(this->armed);
      union {
        bool real;
        uint8_t base;
      } u_guided;
      u_guided.base = 0;
      u_guided.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->guided = u_guided.real;
      offset += sizeof(this->guided);
      uint32_t length_mode;
      memcpy(&length_mode, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mode-1]=0;
      this->mode = (char *)(inbuffer + offset-1);
      offset += length_mode;
     return offset;
    }

    const char * getType(){ return "roscopter/State"; };
    const char * getMD5(){ return "78271f1d5e63aa48bd71dc911f0524f1"; };

  };

}
#endif