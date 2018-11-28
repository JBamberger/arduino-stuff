byte incomingByte;  // incoming data
int  LED = 13;      // LED pin
 
void setup() {
  Serial.begin(38400);  //Arduino to PC
  Serial1.begin(115200); // Arduino to BT-Module
  
  pinMode(LED, OUTPUT);
  Serial.println("Press 1 to LED ON or 0 to LED OFF...");
}
 
void loop() {
  if (Serial1.available() > 0) {
    incomingByte = Serial1.read();
    if(incomingByte == '0') {
       digitalWrite(LED, LOW);
       Serial.println("LED turned OFF");
    }
    if(incomingByte == '1') {
       digitalWrite(LED, HIGH);
       Serial.println("LED turned ON");
    }
    
  }
}
