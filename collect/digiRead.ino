int RECEIVE_PIN = 2;

void setup() {
    Serial.begin(9600);
    pinMode(RECEIVE_PIN, INPUT);
}

void loop() {
  int counter = 0;
  int bit = digitalRead(RECEIVE_PIN);
  if(bit == LOW) Serial.println(bit);
}
