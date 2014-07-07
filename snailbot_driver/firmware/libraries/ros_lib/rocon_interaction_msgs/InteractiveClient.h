#ifndef _ROS_rocon_interaction_msgs_InteractiveClient_h
#define _ROS_rocon_interaction_msgs_InteractiveClient_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "rocon_std_msgs/PlatformInfo.h"

namespace rocon_interaction_msgs
{

  class InteractiveClient : public ros::Msg
  {
    public:
      char * name;
      uuid_msgs::UniqueID id;
      rocon_std_msgs::PlatformInfo platform_info;
      char * app_name;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->id.serialize(outbuffer + offset);
      offset += this->platform_info.serialize(outbuffer + offset);
      uint32_t length_app_name = strlen( (const char*) this->app_name);
      memcpy(outbuffer + offset, &length_app_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->app_name, length_app_name);
      offset += length_app_name;
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
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->platform_info.deserialize(inbuffer + offset);
      uint32_t length_app_name;
      memcpy(&length_app_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_app_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_app_name-1]=0;
      this->app_name = (char *)(inbuffer + offset-1);
      offset += length_app_name;
     return offset;
    }

    const char * getType(){ return "rocon_interaction_msgs/InteractiveClient"; };
    const char * getMD5(){ return "e103f6807ca2041db1549ac3a7d3787f"; };

  };

}
#endif