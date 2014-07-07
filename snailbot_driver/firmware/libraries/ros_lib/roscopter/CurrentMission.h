#ifndef _ROS_roscopter_CurrentMission_h
#define _ROS_roscopter_CurrentMission_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace roscopter
{

  class CurrentMission : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t mission_num;
      uint16_t wp_dist;
      int16_t target_bearing;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mission_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mission_num >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mission_num);
      *(outbuffer + offset + 0) = (this->wp_dist >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wp_dist >> (8 * 1)) & 0xFF;
      offset += sizeof(this->wp_dist);
      union {
        int16_t real;
        uint16_t base;
      } u_target_bearing;
      u_target_bearing.real = this->target_bearing;
      *(outbuffer + offset + 0) = (u_target_bearing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_bearing.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->target_bearing);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->mission_num =  ((uint16_t) (*(inbuffer + offset)));
      this->mission_num |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->mission_num);
      this->wp_dist =  ((uint16_t) (*(inbuffer + offset)));
      this->wp_dist |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->wp_dist);
      union {
        int16_t real;
        uint16_t base;
      } u_target_bearing;
      u_target_bearing.base = 0;
      u_target_bearing.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_bearing.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->target_bearing = u_target_bearing.real;
      offset += sizeof(this->target_bearing);
     return offset;
    }

    const char * getType(){ return "roscopter/CurrentMission"; };
    const char * getMD5(){ return "deaf93654547b1e516f7011234618190"; };

  };

}
#endif