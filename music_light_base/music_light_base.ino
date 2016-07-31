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
