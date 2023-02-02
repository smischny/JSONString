#include <JSONString.h>
#include <base64.h>

JSONString::JSONString() {
  clear();
}

JSONString & JSONString::clear() {
  jsonString = "{ ";
  return (*this);
}

JSONString &  JSONString::end() {
  //
  // Remove a traililng ", "
  //
  if (jsonString.length() > 2) {
    jsonString = jsonString.substring(0,jsonString.length()-2);
  }
  jsonString += " }";
  return (*this);  
}

String zpad(String &s) {
   return (s);
}

JSONString &  JSONString::addArray(const char *name,const char *value) {

  jsonString += "\"";
  jsonString += name;
  jsonString += "\": [";
  jsonString += value;   // for now don't escape any of the characters in the value
                         // assume it is correctly escaped
  jsonString += "], ";
  
  return (*this);
}

JSONString &  JSONString::add(const char *name,const char *value) {

  jsonString += "\"";
  jsonString += name;
  jsonString += "\": \"";
  while (*value != 0) {
     char c = *value;
     switch (c) {
       case '\n':
         jsonString += "\\n";
         break;
       case '\r':
         jsonString += "\\r";
         break;
       case '\b':
         jsonString += "\\b";
         break;
       case '\t':
         jsonString += "\\t";
         break;
       case '\f':
         jsonString += "\\f";
         break;
       case '"':
         jsonString += "\\\"";
         break;
       case '\\':
         jsonString += "\\\\";
         break;
       default:
         jsonString += c;
         break;
     }
     value++;
  } 
  jsonString += "\", ";
  
  return (*this);
}

String zeros = "000000";
JSONString &  JSONString::addColor(const char *name,uint32_t color) {

  // Convert from R5G6B5 to R8B8G8
  uint32_t r = (color & 0xF800) << 8;
  uint32_t g = (color & 0x07E0) << 5;
  uint32_t b = (color & 0x001F) << 3;
  uint32_t rgbColor = r | b | g;

  jsonString += "\"";
  jsonString += name;
  jsonString += "\": \"#";
  String s = String(rgbColor,HEX);
  if (s.length() < 6) {
      s = zeros.substring(s.length()) + s;
  }
  jsonString += s;
  jsonString += "\", ";

  return (*this);
}

JSONString & JSONString::add(const char *name,boolean value) {
     if (value) {
         return (add(name,1));
     } else {
         return (add(name,0));
     }
}

JSONString & JSONString::add(const char *name,int value) {

  jsonString += "\"";
  jsonString += name;
  jsonString += "\": ";
  jsonString += String(value);
  jsonString += ", ";
  
  return (*this);
}

JSONString & JSONString::addBinnaryArray(const char *name,uint32_t length,const uint8_t *value) {

  jsonString += "\"";
  jsonString += name;
  jsonString += "\": \"";
  jsonString += base64::encode(value,length);
  jsonString += "\", ";

  return (*this);

}

const char * JSONString::getString() {
  return (jsonString.c_str());

}


