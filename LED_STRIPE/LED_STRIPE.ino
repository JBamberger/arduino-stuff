


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
