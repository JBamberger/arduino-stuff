#include <SoftwareSerial.h>

SoftwareSerial btSerial(3, 2);

void setup() {
  btSerial.begin(38400);
  Serial.begin(38400);
}

void loop() {
  if(btSerial.available()) {
    byte a=btSerial.read();
    Serial.write(a);
  }
  
  if(Serial.available()) {
    byte a=Serial.read();
    btSerial.write(a);
  }
}
