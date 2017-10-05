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
