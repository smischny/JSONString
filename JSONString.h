#ifndef __JSON_STRING_H__
#define __JSON_STRING_H__

#include <Arduino.h>

class JSONString {
   public:
      JSONString();
      JSONString & clear();
      JSONString & add(const char *name,const char *value);
      JSONString & add(const char *name,int value);
      JSONString & add(const char *name,boolean value);
      JSONString & addColor(const char *name,uint32_t color);
      JSONString & addArray(const char *name,const char *value);
      JSONString & addBinnaryArray(const char *name,uint32_t length,const uint8_t *value);
      JSONString & end();
      const char *getString();
      
   private:
      String jsonString;
};

#endif

