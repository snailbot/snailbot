#ifndef _ROS_SERVICE_PlannerInterface_h
#define _ROS_SERVICE_PlannerInterface_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "bwi_planning_common/PlannerAtom.h"

namespace bwi_planning_common
{

static const char PLANNERINTERFACE[] = "bwi_planning_common/PlannerInterface";

  class PlannerInterfaceRequest : public ros::Msg
  {
    public:
      bwi_planning_common::PlannerAtom command;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->command.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->command.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PLANNERINTERFACE; };
    const char * getMD5(){ return "3b44d18631c1272d8bcb3e1f37b50d61"; };

  };

  class PlannerInterfaceResponse : public ros::Msg
  {
    public:
      bool success;
      char * status;
      uint8_t observations_length;
      bwi_planning_common::PlannerAtom st_observations;
      bwi_planning_common::PlannerAtom * observations;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status = strlen( (const char*) this->status);
      memcpy(outbuffer + offset, &length_status, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      *(outbuffer + offset++) = observations_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < observations_length; i++){
      offset += this->observations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status;
      memcpy(&length_status, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
      uint8_t observations_lengthT = *(inbuffer + offset++);
      if(observations_lengthT > observations_length)
        this->observations = (bwi_planning_common::PlannerAtom*)realloc(this->observations, observations_lengthT * sizeof(bwi_planning_common::PlannerAtom));
      offset += 3;
      observations_length = observations_lengthT;
      for( uint8_t i = 0; i < observations_length; i++){
      offset += this->st_observations.deserialize(inbuffer + offset);
        memcpy( &(this->observations[i]), &(this->st_observations), sizeof(bwi_planning_common::PlannerAtom));
      }
     return offset;
    }

    const char * getType(){ return PLANNERINTERFACE; };
    const char * getMD5(){ return "4b369ca08113322eccf2b5371446d8fc"; };

  };

  class PlannerInterface {
    public:
    typedef PlannerInterfaceRequest Request;
    typedef PlannerInterfaceResponse Response;
  };

}
#endif
