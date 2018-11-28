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








