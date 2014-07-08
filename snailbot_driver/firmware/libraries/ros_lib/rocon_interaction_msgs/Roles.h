#ifndef _ROS_rocon_interaction_msgs_Roles_h
#define _ROS_rocon_interaction_msgs_Roles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_interaction_msgs
{

  class Roles : public ros::Msg
  {
    public:
      uint8_t list_length;
      char* st_list;
      char* * list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < list_length; i++){
      uint32_t length_listi = strlen( (const char*) this->list[i]);
      memcpy(outbuffer + offset, &length_listi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->list[i], length_listi);
      offset += length_listi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t list_lengthT = *(inbuffer + offset++);
      if(list_lengthT > list_length)
        this->list = (char**)realloc(this->list, list_lengthT * sizeof(char*));
      offset += 3;
      list_length = list_lengthT;
      for( uint8_t i = 0; i < list_length; i++){
      uint32_t length_st_list;
      memcpy(&length_st_list, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_list-1]=0;
      this->st_list = (char *)(inbuffer + offset-1);
      offset += length_st_list;
        memcpy( &(this->list[i]), &(this->st_list), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "rocon_interaction_msgs/Roles"; };
    const char * getMD5(){ return "8e09fa9aad51508cfdcab3b64f048ce0"; };

  };

}
#endif