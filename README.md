# JSONString

A class to build JSON strings.

## Dependancies:
Base64 encoder from \<base64.h\>

## Example:

~~~
    JSONString message;

    message.clear()
           .add("Command",1)
           .add("X",50)
           .add("Y",100)
           .add("Text","Some Text")
           .end();

    const char * json = message.getString();
    Serial.println(json);
~~~

## Output:
~~~
{ "Command": 1, "X": 50, "Y": 100, "Text": "Some Text" }
~~~

## TODO:

## Tested on:
ESP32, ESP8266, RP2040

## Author:
Toby Smischny


