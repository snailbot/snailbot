#ifndef _ROS_velodyne_msgs_VelodyneScan_h
#define _ROS_velodyne_msgs_VelodyneScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "velodyne_msgs/VelodynePacket.h"

namespace velodyne_msgs
{

  class VelodyneScan : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t packets_length;
      velodyne_msgs::VelodynePacket st_packets;
      velodyne_msgs::VelodynePacket * packets;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = packets_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < packets_length; i++){
      offset += this->packets[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t packets_lengthT = *(inbuffer + offset++);
      if(packets_lengthT > packets_length)
        this->packets = (velodyne_msgs::VelodynePacket*)realloc(this->packets, packets_lengthT * sizeof(velodyne_msgs::VelodynePacket));
      offset += 3;
      packets_length = packets_lengthT;
      for( uint8_t i = 0; i < packets_length; i++){
      offset += this->st_packets.deserialize(inbuffer + offset);
        memcpy( &(this->packets[i]), &(this->st_packets), sizeof(velodyne_msgs::VelodynePacket));
      }
     return offset;
    }

    const char * getType(){ return "velodyne_msgs/VelodyneScan"; };
    const char * getMD5(){ return "50804fc9533a0e579e6322c04ae70566"; };

  };

}
#endif