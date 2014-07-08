#ifndef _ROS_SERVICE_QuestionDialog_h
#define _ROS_SERVICE_QuestionDialog_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace segbot_gui
{

static const char QUESTIONDIALOG[] = "segbot_gui/QuestionDialog";

  class QuestionDialogRequest : public ros::Msg
  {
    public:
      int32_t type;
      char * message;
      uint8_t options_length;
      char* st_options;
      char* * options;
      float timeout;
      enum { DISPLAY =  0 };
      enum { CHOICE_QUESTION =  1 };
      enum { TEXT_QUESTION =  2 };
      enum { NO_TIMEOUT = 0.0 };
      enum { NO_RESPONSE = -1 };
      enum { TIMED_OUT = -2 };
      enum { TEXT_RESPONSE = -3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_message = strlen( (const char*) this->message);
      memcpy(outbuffer + offset, &length_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      *(outbuffer + offset++) = options_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < options_length; i++){
      uint32_t length_optionsi = strlen( (const char*) this->options[i]);
      memcpy(outbuffer + offset, &length_optionsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->options[i], length_optionsi);
      offset += length_optionsi;
      }
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeout.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeout.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeout.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      uint32_t length_message;
      memcpy(&length_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      uint8_t options_lengthT = *(inbuffer + offset++);
      if(options_lengthT > options_length)
        this->options = (char**)realloc(this->options, options_lengthT * sizeof(char*));
      offset += 3;
      options_length = options_lengthT;
      for( uint8_t i = 0; i < options_length; i++){
      uint32_t length_st_options;
      memcpy(&length_st_options, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_options; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_options-1]=0;
      this->st_options = (char *)(inbuffer + offset-1);
      offset += length_st_options;
        memcpy( &(this->options[i]), &(this->st_options), sizeof(char*));
      }
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
     return offset;
    }

    const char * getType(){ return QUESTIONDIALOG; };
    const char * getMD5(){ return "c4f672e278d59645166675445f52c93a"; };

  };

  class QuestionDialogResponse : public ros::Msg
  {
    public:
      int32_t index;
      char * text;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      uint32_t length_text = strlen( (const char*) this->text);
      memcpy(outbuffer + offset, &length_text, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->index = u_index.real;
      offset += sizeof(this->index);
      uint32_t length_text;
      memcpy(&length_text, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
     return offset;
    }

    const char * getType(){ return QUESTIONDIALOG; };
    const char * getMD5(){ return "0943bcb850cf8c07c6414e5cf489a8f2"; };

  };

  class QuestionDialog {
    public:
    typedef QuestionDialogRequest Request;
    typedef QuestionDialogResponse Response;
  };

}
#endif
