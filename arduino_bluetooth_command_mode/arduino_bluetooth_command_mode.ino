void setup() {
  Serial1.begin(38400);
  Serial.begin(38400);
}

void loop() {
  if(Serial1.available()) {
    byte a=Serial1.read();
    Serial.write(a);
  }
  
  if(Serial.available()) {
    byte a=Serial.read();
    Serial1.write(a);
  }
}
