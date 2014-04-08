#ifndef _ROS_rover5_Motors_h
#define _ROS_rover5_Motors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover5
{

  class Motors : public ros::Msg
  {
    public:
      int16_t leftPWM;
      int16_t rightPWM;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_leftPWM;
      u_leftPWM.real = this->leftPWM;
      *(outbuffer + offset + 0) = (u_leftPWM.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftPWM.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->leftPWM);
      union {
        int16_t real;
        uint16_t base;
      } u_rightPWM;
      u_rightPWM.real = this->rightPWM;
      *(outbuffer + offset + 0) = (u_rightPWM.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightPWM.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rightPWM);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_leftPWM;
      u_leftPWM.base = 0;
      u_leftPWM.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftPWM.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->leftPWM = u_leftPWM.real;
      offset += sizeof(this->leftPWM);
      union {
        int16_t real;
        uint16_t base;
      } u_rightPWM;
      u_rightPWM.base = 0;
      u_rightPWM.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightPWM.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rightPWM = u_rightPWM.real;
      offset += sizeof(this->rightPWM);
     return offset;
    }

    const char * getType(){ return "rover5/Motors"; };
    const char * getMD5(){ return "7b4d9559074fdc67778eaa6cad96710c"; };

  };

}
#endif