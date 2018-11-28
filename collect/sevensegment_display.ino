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

