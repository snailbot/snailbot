#ifndef _ROS_rocon_interaction_msgs_RemoconStatus_h
#define _ROS_rocon_interaction_msgs_RemoconStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/PlatformInfo.h"

namespace rocon_interaction_msgs
{

  class RemoconStatus : public ros::Msg
  {
    public:
      rocon_std_msgs::PlatformInfo platform_info;
      char * uuid;
      bool running_app;
      int32_t hash;
      char * version;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->platform_info.serialize(outbuffer + offset);
      uint32_t length_uuid = strlen( (const char*) this->uuid);
      memcpy(outbuffer + offset, &length_uuid, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uuid, length_uuid);
      offset += length_uuid;
      union {
        bool real;
        uint8_t base;
      } u_running_app;
      u_running_app.real = this->running_app;
      *(outbuffer + offset + 0) = (u_running_app.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->running_app);
      union {
        int32_t real;
        uint32_t base;
      } u_hash;
      u_hash.real = this->hash;
      *(outbuffer + offset + 0) = (u_hash.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hash.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hash.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hash.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hash);
      uint32_t length_version = strlen( (const char*) this->version);
      memcpy(outbuffer + offset, &length_version, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->platform_info.deserialize(inbuffer + offset);
      uint32_t length_uuid;
      memcpy(&length_uuid, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uuid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uuid-1]=0;
      this->uuid = (char *)(inbuffer + offset-1);
      offset += length_uuid;
      union {
        bool real;
        uint8_t base;
      } u_running_app;
      u_running_app.base = 0;
      u_running_app.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->running_app = u_running_app.real;
      offset += sizeof(this->running_app);
      union {
        int32_t real;
        uint32_t base;
      } u_hash;
      u_hash.base = 0;
      u_hash.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hash.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hash.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hash.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hash = u_hash.real;
      offset += sizeof(this->hash);
      uint32_t length_version;
      memcpy(&length_version, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
     return offset;
    }

    const char * getType(){ return "rocon_interaction_msgs/RemoconStatus"; };
    const char * getMD5(){ return "0f9e0cb24dc73c1b1b1abd41a05afebb"; };

  };

}
#endif