byte data;  // incoming data
 
void setup() {
  Serial.begin(38400);  //Arduino to PC
  Serial1.begin(115200); // Arduino to BT-Module
  Serial.println("This Sketch echos all received data back to Serial and Serial1");
}
 
void loop() {
  if (Serial1.available() > 0) {
    data = Serial1.read();
    
    Serial.write(data);
    Serial1.write(data);
    Serial1.flush();
  }
}
