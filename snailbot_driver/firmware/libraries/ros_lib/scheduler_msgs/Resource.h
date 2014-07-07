#ifndef _ROS_scheduler_msgs_Resource_h
#define _ROS_scheduler_msgs_Resource_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "rocon_std_msgs/Remapping.h"

namespace scheduler_msgs
{

  class Resource : public ros::Msg
  {
    public:
      char * rapp;
      uuid_msgs::UniqueID id;
      char * uri;
      uint8_t remappings_length;
      rocon_std_msgs::Remapping st_remappings;
      rocon_std_msgs::Remapping * remappings;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_rapp = strlen( (const char*) this->rapp);
      memcpy(outbuffer + offset, &length_rapp, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rapp, length_rapp);
      offset += length_rapp;
      offset += this->id.serialize(outbuffer + offset);
      uint32_t length_uri = strlen( (const char*) this->uri);
      memcpy(outbuffer + offset, &length_uri, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      *(outbuffer + offset++) = remappings_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < remappings_length; i++){
      offset += this->remappings[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_rapp;
      memcpy(&length_rapp, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rapp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rapp-1]=0;
      this->rapp = (char *)(inbuffer + offset-1);
      offset += length_rapp;
      offset += this->id.deserialize(inbuffer + offset);
      uint32_t length_uri;
      memcpy(&length_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
      uint8_t remappings_lengthT = *(inbuffer + offset++);
      if(remappings_lengthT > remappings_length)
        this->remappings = (rocon_std_msgs::Remapping*)realloc(this->remappings, remappings_lengthT * sizeof(rocon_std_msgs::Remapping));
      offset += 3;
      remappings_length = remappings_lengthT;
      for( uint8_t i = 0; i < remappings_length; i++){
      offset += this->st_remappings.deserialize(inbuffer + offset);
        memcpy( &(this->remappings[i]), &(this->st_remappings), sizeof(rocon_std_msgs::Remapping));
      }
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/Resource"; };
    const char * getMD5(){ return "1234649cb96e9fac93f446b07c558b23"; };

  };

}
#endif