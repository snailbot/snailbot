#ifndef _ROS_bwi_planning_common_PlannerAtom_h
#define _ROS_bwi_planning_common_PlannerAtom_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bwi_planning_common
{

  class PlannerAtom : public ros::Msg
  {
    public:
      char * name;
      uint8_t value_length;
      char* st_value;
      char* * value;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset++) = value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value_length; i++){
      uint32_t length_valuei = strlen( (const char*) this->value[i]);
      memcpy(outbuffer + offset, &length_valuei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value[i], length_valuei);
      offset += length_valuei;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint8_t value_lengthT = *(inbuffer + offset++);
      if(value_lengthT > value_length)
        this->value = (char**)realloc(this->value, value_lengthT * sizeof(char*));
      offset += 3;
      value_length = value_lengthT;
      for( uint8_t i = 0; i < value_length; i++){
      uint32_t length_st_value;
      memcpy(&length_st_value, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_value-1]=0;
      this->st_value = (char *)(inbuffer + offset-1);
      offset += length_st_value;
        memcpy( &(this->value[i]), &(this->st_value), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "bwi_planning_common/PlannerAtom"; };
    const char * getMD5(){ return "a20c942da620dbf29654f430aa251492"; };

  };

}
#endif