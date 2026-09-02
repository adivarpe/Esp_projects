#define BUTTON 4
#define LED 2

void setup() {

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  int state = digitalRead(BUTTON);

  if (state == HIGH) {
    digitalWrite(LED, HIGH);
    Serial.println("high");
  }
  else {
    digitalWrite(LED, LOW);
    Serial.println("low");
  }

}