#ifndef _ROS_jsk_gui_msgs_DeviceSensor_h
#define _ROS_jsk_gui_msgs_DeviceSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

  class DeviceSensor : public ros::Msg
  {
    public:
      float temperature;
      float relative_humidity;
      float light;
      float pressure;
      float proximity;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_temperature = (int32_t *) &(this->temperature);
      int32_t exp_temperature = (((*val_temperature)>>23)&255);
      if(exp_temperature != 0)
        exp_temperature += 1023-127;
      int32_t sig_temperature = *val_temperature;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_temperature<<5) & 0xff;
      *(outbuffer + offset++) = (sig_temperature>>3) & 0xff;
      *(outbuffer + offset++) = (sig_temperature>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_temperature<<4) & 0xF0) | ((sig_temperature>>19)&0x0F);
      *(outbuffer + offset++) = (exp_temperature>>4) & 0x7F;
      if(this->temperature < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_relative_humidity = (int32_t *) &(this->relative_humidity);
      int32_t exp_relative_humidity = (((*val_relative_humidity)>>23)&255);
      if(exp_relative_humidity != 0)
        exp_relative_humidity += 1023-127;
      int32_t sig_relative_humidity = *val_relative_humidity;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_relative_humidity<<5) & 0xff;
      *(outbuffer + offset++) = (sig_relative_humidity>>3) & 0xff;
      *(outbuffer + offset++) = (sig_relative_humidity>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_relative_humidity<<4) & 0xF0) | ((sig_relative_humidity>>19)&0x0F);
      *(outbuffer + offset++) = (exp_relative_humidity>>4) & 0x7F;
      if(this->relative_humidity < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_light = (int32_t *) &(this->light);
      int32_t exp_light = (((*val_light)>>23)&255);
      if(exp_light != 0)
        exp_light += 1023-127;
      int32_t sig_light = *val_light;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_light<<5) & 0xff;
      *(outbuffer + offset++) = (sig_light>>3) & 0xff;
      *(outbuffer + offset++) = (sig_light>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_light<<4) & 0xF0) | ((sig_light>>19)&0x0F);
      *(outbuffer + offset++) = (exp_light>>4) & 0x7F;
      if(this->light < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_pressure = (int32_t *) &(this->pressure);
      int32_t exp_pressure = (((*val_pressure)>>23)&255);
      if(exp_pressure != 0)
        exp_pressure += 1023-127;
      int32_t sig_pressure = *val_pressure;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_pressure<<5) & 0xff;
      *(outbuffer + offset++) = (sig_pressure>>3) & 0xff;
      *(outbuffer + offset++) = (sig_pressure>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_pressure<<4) & 0xF0) | ((sig_pressure>>19)&0x0F);
      *(outbuffer + offset++) = (exp_pressure>>4) & 0x7F;
      if(this->pressure < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_proximity = (int32_t *) &(this->proximity);
      int32_t exp_proximity = (((*val_proximity)>>23)&255);
      if(exp_proximity != 0)
        exp_proximity += 1023-127;
      int32_t sig_proximity = *val_proximity;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_proximity<<5) & 0xff;
      *(outbuffer + offset++) = (sig_proximity>>3) & 0xff;
      *(outbuffer + offset++) = (sig_proximity>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_proximity<<4) & 0xF0) | ((sig_proximity>>19)&0x0F);
      *(outbuffer + offset++) = (exp_proximity>>4) & 0x7F;
      if(this->proximity < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_temperature = (uint32_t*) &(this->temperature);
      offset += 3;
      *val_temperature = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_temperature |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_temperature |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_temperature |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_temperature = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_temperature |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_temperature !=0)
        *val_temperature |= ((exp_temperature)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->temperature = -this->temperature;
      uint32_t * val_relative_humidity = (uint32_t*) &(this->relative_humidity);
      offset += 3;
      *val_relative_humidity = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_relative_humidity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_relative_humidity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_relative_humidity |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_relative_humidity = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_relative_humidity |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_relative_humidity !=0)
        *val_relative_humidity |= ((exp_relative_humidity)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->relative_humidity = -this->relative_humidity;
      uint32_t * val_light = (uint32_t*) &(this->light);
      offset += 3;
      *val_light = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_light |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_light |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_light |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_light = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_light |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_light !=0)
        *val_light |= ((exp_light)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->light = -this->light;
      uint32_t * val_pressure = (uint32_t*) &(this->pressure);
      offset += 3;
      *val_pressure = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_pressure |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_pressure |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_pressure |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_pressure = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_pressure |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_pressure !=0)
        *val_pressure |= ((exp_pressure)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->pressure = -this->pressure;
      uint32_t * val_proximity = (uint32_t*) &(this->proximity);
      offset += 3;
      *val_proximity = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_proximity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_proximity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_proximity |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_proximity = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_proximity |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_proximity !=0)
        *val_proximity |= ((exp_proximity)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->proximity = -this->proximity;
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/DeviceSensor"; };
    const char * getMD5(){ return "d3861ba768b988b4c249337d4dc6552d"; };

  };

}
#endif