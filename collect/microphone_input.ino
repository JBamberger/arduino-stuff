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
