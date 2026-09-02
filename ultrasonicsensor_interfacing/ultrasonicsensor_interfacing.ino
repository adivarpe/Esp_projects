#define trigpin 4
#define echopin 2

void setup() {
  Serial.begin(115200);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(2,OUTPUT);
}

void loop() {

  // Make sure trigger is LOW
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  // Send 10 microsecond pulse
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  // Measure echo time
  long duration = pulseIn(echopin, HIGH);

  // Calculate distance
  float distance = duration / 58.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);

  if (distance>10)
  {
   digitalWrite(2,HIGH);
  }
  else 
  {
    digitalWrite(2,LOW);
  }
}