#ifndef _ROS_segbot_sensors_RangeArray_h
#define _ROS_segbot_sensors_RangeArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Range.h"

namespace segbot_sensors
{

  class RangeArray : public ros::Msg
  {
    public:
      uint8_t ranges_length;
      sensor_msgs::Range st_ranges;
      sensor_msgs::Range * ranges;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = ranges_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ranges_length; i++){
      offset += this->ranges[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t ranges_lengthT = *(inbuffer + offset++);
      if(ranges_lengthT > ranges_length)
        this->ranges = (sensor_msgs::Range*)realloc(this->ranges, ranges_lengthT * sizeof(sensor_msgs::Range));
      offset += 3;
      ranges_length = ranges_lengthT;
      for( uint8_t i = 0; i < ranges_length; i++){
      offset += this->st_ranges.deserialize(inbuffer + offset);
        memcpy( &(this->ranges[i]), &(this->st_ranges), sizeof(sensor_msgs::Range));
      }
     return offset;
    }

    const char * getType(){ return "segbot_sensors/RangeArray"; };
    const char * getMD5(){ return "b72db098d4ed346ce682a1d5e70d327c"; };

  };

}
#endif