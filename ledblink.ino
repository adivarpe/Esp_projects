void setup() {
  pinmode(2,OUTPUT);

}

void loop() {
  digitalwrite(2,HIGH);
  delay(1000);
  digitalwrite(2,LOW);
  delay(1000);

}
