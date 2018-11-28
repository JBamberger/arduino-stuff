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
// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define SEGA 2
#define SEGB 3
#define SEGC 4
#define SEGD 5
#define SEGE 6
#define SEGF 7
#define SEGG 8
#define DOT 9
#define ON LOW
#define OFF HIGH

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.



void setup() {
  pinMode(SEGA, OUTPUT);
  pinMode(SEGB, OUTPUT);
  pinMode(SEGC, OUTPUT);
  pinMode(SEGD, OUTPUT);
  pinMode(SEGE, OUTPUT);
  pinMode(SEGF, OUTPUT);
  pinMode(SEGG, OUTPUT);
  pinMode(DOT, OUTPUT);
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  int distance = uS / US_ROUNDTRIP_CM;
  Serial.print(distance); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");
  mapDistance(distance);
}

void mapDistance(int distance) {
  //writeRawNum(OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
  if(distance <= 10 && distance >=0) {
    writeNumber(distance);
  } else if(distance < 0) {
    return;
  } else if(distance < 20) {
    writeNumber(10);
  } else if(distance < 30) {
    writeNumber(20);
  } else if(distance < 40) {
    writeNumber(30);
  } else if(distance < 50) {
    writeNumber(40);
  } else if(distance < 60) {
    writeNumber(50);
  } else if(distance < 70) {
    writeNumber(60);
  } else if(distance < 80) {
    writeNumber(70);
  } else if(distance < 90) {
    writeNumber(80);
  } else if(distance < 100) {
    writeNumber(90);
  }
}

void writeNumber(int num) {
  switch (num) {
    case 0:
      // a,b,c,d,e,f
      writeRawNum(ON, ON, ON, ON, ON, ON, OFF, OFF);
      break;
    case 1:
      // b,c
      writeRawNum(OFF, ON, ON, OFF, OFF, OFF, OFF, OFF);
      break;
    case 2:
      // a,b,d,e,g
      writeRawNum(ON, ON, OFF, ON, ON, OFF, ON, OFF);
      break;
    case 3:
      // a,b,c,d,g
      writeRawNum(ON, ON, ON, ON, OFF, OFF, ON, OFF);
      break;
    case 4:
      // b,c,f,g
      writeRawNum(OFF, ON, ON, OFF, OFF, ON, ON, OFF);
      break;
    case 5:
      // a,c,d,f,g
      writeRawNum(ON, OFF, ON, ON, OFF, ON, ON, OFF);
      break;
    case 6:
      // a,c,d,e,f,g
      writeRawNum(ON, OFF, ON, ON, ON, ON, ON, OFF);
      break;
    case 7:
      // a,b,c
      writeRawNum(ON, ON, ON, OFF, OFF, OFF, OFF, OFF);
      break;
    case 8:
      // a,b,c,d,e,f,g
      writeRawNum(ON, ON, ON, ON, ON, ON, ON, OFF);
      break;
    case 9:
      // a,b,c,d,f,g
      writeRawNum(ON, ON, ON, ON, OFF, ON, ON, OFF);
      break;
    case 10:
      // b,c
      writeRawNum(OFF, ON, ON, OFF, OFF, OFF, OFF, ON);
      break;
    case 20:
      // a,b,d,e,g
      writeRawNum(ON, ON, OFF, ON, ON, OFF, ON, ON);
      break;
    case 30:
      // a,b,c,d,g
      writeRawNum(ON, ON, ON, ON, OFF, OFF, ON, ON);
      break;
    case 40:
      // b,c,f,g
      writeRawNum(OFF, ON, ON, OFF, OFF, ON, ON, ON);
      break;
    case 50:
      // a,c,d,f,g
      writeRawNum(ON, OFF, ON, ON, OFF, ON, ON, ON);
      break;
    case 60:
      // a,c,d,e,f,g
      writeRawNum(ON, OFF, ON, ON, ON, ON, ON, ON);
      break;
    case 70:
      // a,b,c
      writeRawNum(ON, ON, ON, OFF, OFF, OFF, OFF, ON);
      break;
    case 80:
      // a,b,c,d,e,f,g
      writeRawNum(ON, ON, ON, ON, ON, ON, ON, ON);
      break;
    case 90:
      // a,b,c,d,f,g
      writeRawNum(ON, ON, ON, ON, OFF, ON, ON, ON);
      break;
  }
}

void writeRawNum(int a, int b, int c, int d, int e, int f, int g, int dot) {
  digitalWrite(SEGA, a);
  digitalWrite(SEGB, b);
  digitalWrite(SEGC, c);
  digitalWrite(SEGD, d);
  digitalWrite(SEGE, e);
  digitalWrite(SEGF, f);
  digitalWrite(SEGG, g);
  digitalWrite(DOT, dot);
}








/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

#define triggerPin 2
#define echoPin 3
#define led 13
#define led2 5

void setup() {
  Serial.begin (115200);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  long duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  digitalWrite(led, LOW);
  int del = 500;
  if(distance < 50) {
    del = 250;
  } else if(distance < 20) {
    del = 100;
  } else if(distance < 10) {
    del = 50;
  }
  delay(del);
}
void setup() 
{
  Serial1.begin(38400);
  Serial.begin(38400);
}

void loop() 
{
  if(Serial1.available())
  {
    byte a=Serial1.read();
    Serial.write(a);
  }
  
  if(Serial.available())
  {
    byte a=Serial.read();
    Serial1.write(a);
  }
  
}


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
#include <nRF24L01.h>
#include <printf.h>
#include <Servo.h>
#include <RF24.h>
#include <RF24_config.h>

/*
 * 
Uses the RF24 Library by TMRH2o here:
  https://github.com/TMRh20/RF24
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 7
   4 - CSN to Arduino pin 8
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED
*/

Servo leftServo;
Servo rightServo;
Servo backServo;
Servo tailServo;
Servo motor;


// (Create an instance of a radio, specifying the CE and CS pins. )
RF24 nrf24 (7, 8);
uint8_t addresses[][6] = {"1Node"};
int readingPipeNum = 1;
int channel = 108;
int dataReceived;
int leftServo  = 3;
int rightServo = 5;
int backServo  = 6;
int tailServo  = 9;
int motor      = 10;
byte head, data;

void setup() {
  nrf24.begin();                                         // Start up the physical nRF24L01 Radio
  nrf24.setChannel(channel);                             // Above most Wifi Channels
  nrf24.setPALevel(RF24_PA_MAX);
  nrf24.openReadingPipe(readingPipeNum, addresses[0]);
  //nrf24.openWritingPipe(addresses[0]);
  nrf24.startListening();
  leftServo.attach(leftServo);
  rightServo.attach(rightServo);
  backServo.attach(backServo);
  tailServo.attach(tailServo);
  motor.attach(motor);
  delay(1000);
}


void loop() {
  if (nrf24.available()) {
     nrf24.read(&dataReceived, sizeof(dataReceived));
     data = dataReceived & 0xff;
     head = (dataReceived >> 8) & 0xff;

     switch (head) {
        case 0x01 :/*ping*/
          break;
        case 0x02 :/*pong*/
          break;
        case 0x05 :/*debugvalue*/
          break;
        case 0x0A :/*left*/
          leftServo.write(data);
          break;
        case 0x0B :/*right*/
          rightServo.write(data);
          break;
        case 0x0C :/*back*/
          backServo.write(data);
          break;
        case 0x0D :/*tail*/
          tailServo.write(data);
          break;
        case 0x0E :/*motor*/
          motor.write(data);
          break;
        case 0x63 :/*emergency*/
          break;
        default:
          break;
    }
  }
}
#include <IRLib.h>
 
//Create a receiver object to listen on pin 11
IRrecv My_Receiver(11);
 
//Create a decoder object
IRdecode My_Decoder;

int COUNTER = 0;

void setup()
{
  Serial.begin(9600);
  My_Receiver.enableIRIn(); // Start the receiver
}
 
void loop() {

//Continuously look for results. When you have them pass them to the decoder
  if (My_Receiver.GetResults(&My_Decoder)) {
    Serial.print("Sample nr.");
    Serial.print(COUNTER++);
    Serial.print("\n");
    My_Decoder.decode();    //Decode the data
    My_Decoder.DumpResults(); //Show the results on serial monitor
    My_Receiver.resume();     //Restart the receiver
  }
}
#include <IRremote.h>
int RECEIVE_PIN = 2;
IRrecv irrecv(RECEIVE_PIN);
decode_results results;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.print("0x");
        Serial.println(results.value, HEX);
        delay(50);
        irrecv.resume();// Receive the next value
    }
}
char incomingByte;  // incoming data
int  LED = 13;      // LED pin
 
void setup() {
  //Serial.begin(9600); // initialization
  pinMode(LED, OUTPUT);
  //Serial.println("Press 1 to LED ON or 0 to LED OFF...");
}
 
void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
  /*if (Serial.available() > 0) {  // if the data came
    incomingByte = Serial.read(); // read byte
    if(incomingByte == '0') {
       digitalWrite(LED, LOW);  // if 1, switch LED Off
       Serial.println("LED OFF. Press 1 to LED ON!");  // print message
    }
    if(incomingByte == '1') {
       digitalWrite(LED, HIGH); // if 0, switch LED on
       Serial.println("LED ON. Press 0 to LED OFF!");
    }
  }*/
}



#define FADESPEED 6
#define R 9
#define G 10
#define B 11
#define BT Serial

//status
int R_brightness = 0;
int G_brightness = 0;
int B_brightness = 0;
int effectSpeed = 0;
int effect = 0;
int fadeStatus = 0;
int fadeMode = 1;

void fade(int pin) {
  analogWrite(pin, fadeStatus);
  if(fadeStatus == 255 || fadeStatus == 0) {
    fadeMode = -fadeMode;
  }
  if(fadeMode < 0) {
    fadeStatus++;
  } else {
    fadeStatus--;
  }
}

void crossFade(int pinIn, int pinOut) {
  analogWrite(pinIn, fadeStatus);
  analogWrite(pinOut, 255 - fadeStatus);
  if(fadeStatus == 255 || fadeStatus == 0) {
    fadeMode = -fadeMode;
  }
  if(fadeMode < 0) {
    fadeStatus++;
  } else {
    fadeStatus--;
  }
}

void reset() {
  fadeStatus = 0;
  fadeMode = 1;
}


void setup() {
  BT.begin(38400);
  BT.setTimeout(20);
  //initialize status
}

void loop() {
  if(BT.available()) {
    int data = BT.parseInt();
    if(data == 1) {
      effect = 0;
        R_brightness = BT.parseInt();
        G_brightness = BT.parseInt();
        B_brightness = BT.parseInt();
        setColor(R_brightness, G_brightness, B_brightness);
        //static color
        return;
    }
    
    reset();
    switch(data) {
      case 0:
        //do nothing...
        break;
      case 1: break;
      case 2:
        effectSpeed++;
        break;
      case 3:
        effectSpeed--;
        break;
      case 4:
        effect = 1;
        break;
      case 5:
        effect = 2;
        break;
      case 6:
        effect = 3;
        break;
      case 7:
        effect = 4;
        break;
      case 8:
        effect = 5;
        break;
      case 9:
        effect = 6;
        break;
    }
  
  }
  
  //select mode
  switch(effect) {
    case 0:
      //static color, do nothing...
      break;
    case 1:
      fade(R);
      break;
    case 2:
      fade(G);
      break;
    case 3:
      fade(B);
      break;
    case 4:
      crossFade(R, G);
      //crossFade(G, R);
      break;
    case 5:
      crossFade(B, G);
      //crossFade(G, B);
      break;
    case 6:
      crossFade(R, B);
      //crossFade(B, R);
      break;
  }
  delay(effectSpeed);
}

void setColor(int red, int green, int blue) {
  analogWrite(R, red);
  analogWrite(G, green);
  analogWrite(B, blue);
}

/*void updateLED() {
  analogWrite(R, R_brightness);
  analogWrite(G, G_brightness);
  analogWrite(B, B_brightness);
}

void fadeAll() {
  xFade(R,G,FADESPEED);
  xFade(G,B,FADESPEED);
  xFade(B,R,FADESPEED);
}

void xFade(int pinOut, int pinIn, int fadeSpeed) {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue++) {
    analogWrite(pinIn, fadeValue);
    analogWrite(pinOut, 255 - fadeValue);
    delay(fadeSpeed);
  }
}

void fadeInOut(int pin, int fadeSpeed) {
  fadeIn(pin, fadeSpeed);
  fadeOut(pin, fadeSpeed);
}

void fadeIn(int pin, int fadeSpeed) {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue++) {
    analogWrite(pin, fadeValue);
    delay(fadeSpeed);
  }
}

void fadeOut(int pin, int fadeSpeed) {
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue--) {
    analogWrite(pin, fadeValue);
    delay(fadeSpeed);
  }
}*/
#define PC Serial
#define MIC 0

void setup() {
  // put your setup code here, to run once:
  PC.begin(115200);
}

void loop() {
  PC.println(analogRead(MIC));
  delay(200);
}
int MusicValue = 0;
int MusicPin = 0;

int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup()
{
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
  delay(500);
  
}
void loop()
{
  MusicValue = analogRead(MusicPin);
  MusicValue = map(MusicValue, 0, 255, 0, 255);
  analogWrite(RedPin, MusicValue);
  analogWrite(BluePin, MusicValue);



/*
  if (MusicValue == 0) {
    analogWrite(RedPin,0);
       analogWrite(BluePin,0);
       delay(25);
  }
  if (MusicValue >= 51)
    if (MusicValue <= 105) {{
      analogWrite(RedPin, MusicValue);
      analogWrite(BluePin, 0);
      delay(5);
    }}
  if (MusicValue <= 50)
    if (MusicValue >= 1) {{
      analogWrite(BluePin, MusicValue);
      analogWrite(RedPin, 0);
      delay(5);
     }}
  if (MusicValue >= 106) {
    analogWrite(RedPin, 255);
    analogWrite(BluePin, 255);
    delay(5);
  }*/
}
/*
TMRh20 2014
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */
#include <SPI.h>
#include "RF24.h"
/*************  USER Configuration *****************************/
                                          // Hardware configuration
RF24 radio(7,8);                        // Set up nRF24L01 radio on SPI bus plus pins 7 & 8
/***************************************************************/
const uint64_t pipes[2] = { 0xABCDABCD71LL, 0x544d52687CLL };   // Radio pipe addresses for the 2 nodes to communicate.
byte data[32];                           //Data buffer for testing data transfer speeds
unsigned long counter, rxTimer;          //Counter and timer for keeping track transfer info
unsigned long startTime, stopTime;  
bool TX=1,RX=0,role=0;
void setup(void) {
  Serial.begin(115200);
  radio.begin();                           // Setup and configure rf radio
  radio.setChannel(1);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);
  radio.setAutoAck(1);                     // Ensure autoACK is enabled
  radio.setRetries(2,15);                  // Optionally, increase the delay between retries & # of retries
  
  radio.setCRCLength(RF24_CRC_8);          // Use 8-bit CRC for performance
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);
  
  radio.startListening();                 // Start listening
  radio.printDetails();                   // Dump the configuration of the rf unit for debugging
  
  Serial.println(F("\n\rRF24/examples/Transfer/"));
  Serial.println(F("*** PRESS 'T' to begin transmitting to the other node"));
  
  randomSeed(analogRead(0));              //Seed for random number generation
  
  for(int i=0; i<32; i++){
     data[i] = random(255);               //Load the buffer with random data
  }
  radio.powerUp();                        //Power up the radio
}
void loop(void){
  if(role == TX){
    
    delay(2000);
    
    Serial.println(F("Initiating Basic Data Transfer"));
    
    
    unsigned long cycles = 10000; //Change this to a higher or lower number. 
    
    startTime = millis();
    unsigned long pauseTime = millis();
            
    for(int i=0; i<cycles; i++){        //Loop through a number of cycles
      data[0] = i;                      //Change the first byte of the payload for identification
      if(!radio.writeFast(&data,32)){   //Write to the FIFO buffers        
        counter++;                      //Keep count of failed payloads
      }
      
      //This is only required when NO ACK ( enableAutoAck(0) ) payloads are used
//      if(millis() - pauseTime > 3){
//        pauseTime = millis();
//        radio.txStandBy();          // Need to drop out of TX mode every 4ms if sending a steady stream of multicast data
//        //delayMicroseconds(130);     // This gives the PLL time to sync back up   
//      }
      
    }
    
   stopTime = millis();   
                                         //This should be called to wait for completion and put the radio in standby mode after transmission, returns 0 if data still in FIFO (timed out), 1 if success
   if(!radio.txStandBy()){ counter+=3; } //Standby, block only until FIFO empty or auto-retry timeout. Flush TX FIFO if failed
   //radio.txStandBy(1000);              //Standby, using extended timeout period of 1 second
   
   float numBytes = cycles*32;
   float rate = numBytes / (stopTime - startTime);
    
   Serial.print("Transfer complete at "); Serial.print(rate); Serial.println(" KB/s");
   Serial.print(counter); Serial.print(" of "); Serial.print(cycles); Serial.println(" Packets Failed to Send");
   counter = 0;   
    
   }
  
  
  
if(role == RX){
     while(radio.available()){       
      radio.read(&data,32);
      counter++;
     }
   if(millis() - rxTimer > 1000){
     rxTimer = millis();     
     unsigned long numBytes = counter*32;
     Serial.print(F("Rate: "));
     //Prevent dividing into 0, which will cause issues over a period of time
     Serial.println(numBytes > 0 ? numBytes/1000.0:0);
     Serial.print(F("Payload Count: "));
     Serial.println(counter);
     counter = 0;
   }
  }
  //
  // Change roles
  //
  if ( Serial.available() )
  {
    char c = toupper(Serial.read());
    if ( c == 'T' && role == RX )
    {
      Serial.println(F("*** CHANGING TO TRANSMIT ROLE -- PRESS 'R' TO SWITCH BACK"));
      radio.openWritingPipe(pipes[1]);
      radio.openReadingPipe(1,pipes[0]);
      radio.stopListening();
      role = TX;                  // Become the primary transmitter (ping out)
    }
    else if ( c == 'R' && role == TX )
    {
      radio.openWritingPipe(pipes[0]);
      radio.openReadingPipe(1,pipes[1]); 
      radio.startListening();
      Serial.println(F("*** CHANGING TO RECEIVE ROLE -- PRESS 'T' TO SWITCH BACK"));
      role = RX;                // Become the primary receiver (pong back)
    }
  }
}
/*
  Example for different sending methods
  
  https://github.com/sui77/rc-switch/
  
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(1);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
  
}

void loop() {

  /* See Example: TypeA_WithDIPSwitches */
  mySwitch.switchOn("11111", "10000");
  delay(1000);
  mySwitch.switchOff("11111", "10000");
  delay(1000);

  /* Same switch as above, but using decimal code */
  //mySwitch.send(5393, 24);
  //delay(1000);  
  //mySwitch.send(5396, 24);
  //delay(1000);  

  /* Same switch as above, but using binary code */
  //mySwitch.send("000000000001010100010001");
  //delay(1000);  
  //mySwitch.send("000000000001010100010100");
  //delay(1000);

  /* Same switch as above, but tri-state code */ 
  //mySwitch.sendTriState("00000FFF0F0F");
  //delay(1000);  
  //mySwitch.sendTriState("00000FFF0FF0");
  //delay(1000);

  //delay(20000);
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()) {
    Serial.print(Serial.read());
  }
}
#define SEGA 2
#define SEGB 3
#define SEGC 4
#define SEGD 5
#define SEGE 6
#define SEGF 7
#define SEGG 8
#define DOT 9
#define ON LOW
#define OFF HIGH




void setup() {
  pinMode(SEGA, OUTPUT);
  pinMode(SEGB, OUTPUT);
  pinMode(SEGC, OUTPUT);
  pinMode(SEGD, OUTPUT);
  pinMode(SEGE, OUTPUT);
  pinMode(SEGF, OUTPUT);
  pinMode(SEGG, OUTPUT);
  pinMode(DOT, OUTPUT);
}

void loop() {
  for(int i = 0; i < 10; i++) {
    writeNumber(i);
    delay(1000);
  }
  writeRawNum(ON, ON, ON, ON, ON, ON, ON, ON);
  delay(250);
  writeRawNum(OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
  delay(250);
  writeRawNum(ON, ON, ON, ON, ON, ON, ON, ON);
  delay(250);
  writeRawNum(OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
  delay(1000);
}

void writeNumber(int num) {
  switch (num) {
    case 0:
      // a,b,c,d,e,f
      writeRawNum(ON, ON, ON, ON, ON, ON, OFF, OFF);
      break;
    case 1:
      // b,c
      writeRawNum(OFF, ON, ON, OFF, OFF, OFF, OFF, OFF);
      break;
    case 2:
      // a,b,d,e,g
      writeRawNum(ON, ON, OFF, ON, ON, OFF, ON, OFF);
      break;
    case 3:
      // a,b,c,d,g
      writeRawNum(ON, ON, ON, ON, OFF, OFF, ON, OFF);
      break;
    case 4:
      // b,c,f,g
      writeRawNum(OFF, ON, ON, OFF, OFF, ON, ON, OFF);
      break;
    case 5:
      // a,c,d,f,g
      writeRawNum(ON, OFF, ON, ON, OFF, ON, ON, OFF);
      break;
    case 6:
      // a,c,d,e,f,g
      writeRawNum(ON, OFF, ON, ON, ON, ON, ON, OFF);
      break;
    case 7:
      // a,b,c
      writeRawNum(ON, ON, ON, OFF, OFF, OFF, OFF, OFF);
      break;
    case 8:
      // a,b,c,d,e,f,g
      writeRawNum(ON, ON, ON, ON, ON, ON, ON, OFF);
      break;
    case 9:
      // a,b,c,d,f,g
      writeRawNum(ON, ON, ON, ON, OFF, ON, ON, OFF);
      break;
  }
}

void writeRawNum(int a, int b, int c, int d, int e, int f, int g, int dot) {
  digitalWrite(SEGA, a);
  digitalWrite(SEGB, b);
  digitalWrite(SEGC, c);
  digitalWrite(SEGD, d);
  digitalWrite(SEGE, e);
  digitalWrite(SEGF, f);
  digitalWrite(SEGG, g);
  digitalWrite(DOT, dot);
}

