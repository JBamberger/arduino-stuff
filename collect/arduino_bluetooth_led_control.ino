byte data;  // incoming data
int LED_RED = 2;
int LED_GREEN = 3;
int LED_BLUE = 4;

int brightness = 0;
int fadeAmount = 5;

int red_brightness = 0;
int green_brightness = 0;
int blue_brightness = 0;
int temp = 0;


void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  Serial.begin(38400);  //Arduino to PC
  Serial1.begin(38400); // Arduino to BT-Module
  Serial.println("This Sketch echos all received data back to Serial and Serial1");
}
 
void loop() {
  if(Serial1.available()) {
     temp = Serial1.parseInt();
    Serial.println(temp);
  
    if(temp <= 0) {
    } else {
    temp--;
  
    if(0 <= temp && temp <= 255) {
      red_brightness = temp;
      Serial.print("Red brightness: ");
      Serial.println(red_brightness);
      analogWrite(LED_RED, red_brightness);
    } else if(256 <= temp && temp <= 511) {
      green_brightness = temp -256;
      Serial.print("Green brightness: ");
      Serial.println(green_brightness);
      analogWrite(LED_GREEN, green_brightness);
    } else if(512 <= temp && temp <= 767) {
      blue_brightness = temp -512;
      Serial.print("Blue brightness: ");
      Serial.println(blue_brightness);
      analogWrite(LED_BLUE, blue_brightness);
    }
  }
  
  
  }
  
  
  
  

  /*brightness = brightness + fadeAmount;

  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  delay(20);
  
  if (Serial1.available() > 0) {
    data = Serial1.read();
    
    Serial.write(data);
    Serial1.write(data);
    Serial1.flush();
  }*/
}
