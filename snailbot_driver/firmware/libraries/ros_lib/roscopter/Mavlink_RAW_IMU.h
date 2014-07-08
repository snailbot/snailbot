#ifndef _ROS_roscopter_Mavlink_RAW_IMU_h
#define _ROS_roscopter_Mavlink_RAW_IMU_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace roscopter
{

  class Mavlink_RAW_IMU : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint64_t time_usec;
      int32_t xacc;
      int32_t yacc;
      int32_t zacc;
      int32_t xgyro;
      int32_t ygyro;
      int32_t zgyro;
      int32_t xmag;
      int32_t ymag;
      int32_t zmag;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_time_usec;
      u_time_usec.real = this->time_usec;
      *(outbuffer + offset + 0) = (u_time_usec.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_usec.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_usec.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_usec.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_usec);
      union {
        int32_t real;
        uint32_t base;
      } u_xacc;
      u_xacc.real = this->xacc;
      *(outbuffer + offset + 0) = (u_xacc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xacc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xacc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xacc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xacc);
      union {
        int32_t real;
        uint32_t base;
      } u_yacc;
      u_yacc.real = this->yacc;
      *(outbuffer + offset + 0) = (u_yacc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yacc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yacc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yacc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yacc);
      union {
        int32_t real;
        uint32_t base;
      } u_zacc;
      u_zacc.real = this->zacc;
      *(outbuffer + offset + 0) = (u_zacc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zacc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zacc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zacc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zacc);
      union {
        int32_t real;
        uint32_t base;
      } u_xgyro;
      u_xgyro.real = this->xgyro;
      *(outbuffer + offset + 0) = (u_xgyro.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xgyro.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xgyro.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xgyro.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xgyro);
      union {
        int32_t real;
        uint32_t base;
      } u_ygyro;
      u_ygyro.real = this->ygyro;
      *(outbuffer + offset + 0) = (u_ygyro.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ygyro.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ygyro.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ygyro.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ygyro);
      union {
        int32_t real;
        uint32_t base;
      } u_zgyro;
      u_zgyro.real = this->zgyro;
      *(outbuffer + offset + 0) = (u_zgyro.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zgyro.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zgyro.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zgyro.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zgyro);
      union {
        int32_t real;
        uint32_t base;
      } u_xmag;
      u_xmag.real = this->xmag;
      *(outbuffer + offset + 0) = (u_xmag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xmag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xmag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xmag.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xmag);
      union {
        int32_t real;
        uint32_t base;
      } u_ymag;
      u_ymag.real = this->ymag;
      *(outbuffer + offset + 0) = (u_ymag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ymag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ymag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ymag.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ymag);
      union {
        int32_t real;
        uint32_t base;
      } u_zmag;
      u_zmag.real = this->zmag;
      *(outbuffer + offset + 0) = (u_zmag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zmag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zmag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zmag.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zmag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_time_usec;
      u_time_usec.base = 0;
      u_time_usec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_usec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_usec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_usec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time_usec = u_time_usec.real;
      offset += sizeof(this->time_usec);
      union {
        int32_t real;
        uint32_t base;
      } u_xacc;
      u_xacc.base = 0;
      u_xacc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xacc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xacc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xacc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xacc = u_xacc.real;
      offset += sizeof(this->xacc);
      union {
        int32_t real;
        uint32_t base;
      } u_yacc;
      u_yacc.base = 0;
      u_yacc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yacc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yacc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yacc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yacc = u_yacc.real;
      offset += sizeof(this->yacc);
      union {
        int32_t real;
        uint32_t base;
      } u_zacc;
      u_zacc.base = 0;
      u_zacc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zacc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zacc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zacc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zacc = u_zacc.real;
      offset += sizeof(this->zacc);
      union {
        int32_t real;
        uint32_t base;
      } u_xgyro;
      u_xgyro.base = 0;
      u_xgyro.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xgyro.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xgyro.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xgyro.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xgyro = u_xgyro.real;
      offset += sizeof(this->xgyro);
      union {
        int32_t real;
        uint32_t base;
      } u_ygyro;
      u_ygyro.base = 0;
      u_ygyro.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ygyro.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ygyro.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ygyro.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ygyro = u_ygyro.real;
      offset += sizeof(this->ygyro);
      union {
        int32_t real;
        uint32_t base;
      } u_zgyro;
      u_zgyro.base = 0;
      u_zgyro.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zgyro.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zgyro.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zgyro.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zgyro = u_zgyro.real;
      offset += sizeof(this->zgyro);
      union {
        int32_t real;
        uint32_t base;
      } u_xmag;
      u_xmag.base = 0;
      u_xmag.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xmag.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xmag.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xmag.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xmag = u_xmag.real;
      offset += sizeof(this->xmag);
      union {
        int32_t real;
        uint32_t base;
      } u_ymag;
      u_ymag.base = 0;
      u_ymag.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ymag.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ymag.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ymag.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ymag = u_ymag.real;
      offset += sizeof(this->ymag);
      union {
        int32_t real;
        uint32_t base;
      } u_zmag;
      u_zmag.base = 0;
      u_zmag.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zmag.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zmag.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zmag.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zmag = u_zmag.real;
      offset += sizeof(this->zmag);
     return offset;
    }

    const char * getType(){ return "roscopter/Mavlink_RAW_IMU"; };
    const char * getMD5(){ return "f00561d290c2da804223c20d12427677"; };

  };

}
#endif