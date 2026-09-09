
#define BLYNK_TEMPLATE_ID "TMPL3dc0zH3L9"
 #define BLYNK_TEMPLATE_NAME "Smart Dustbin1" 
 #define BLYNK_AUTH_TOKEN "MDd7Y9wyGY16nPuxPwGdR5ngcFYCQLwm"
 #include <ESP32Servo.h>
#include <WiFi.h>
 #include <BlynkSimpleEsp32.h>


char ssid[] = "Redmi"; 
char pass[] = "244466666";

#define trig1 2
#define echo1 4

#define trig2 18
#define echo2 19

#define servoPin 13

Servo myServo;


void setup() {
  Serial.begin(115200);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  myServo.attach(servoPin);
  myServo.write(0);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  // Sensor 1
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  long duration1 = pulseIn(echo1, HIGH);
  float distance1 = duration1 / 58.0;

  delay(50);

  // Sensor 2
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  long duration2 = pulseIn(echo2, HIGH);
  float distance2 = duration2 / 58.0;

  int fillLevel = map(distance2, 30, 10, 0, 100);
fillLevel = constrain(fillLevel, 0, 100);

Blynk.virtualWrite(V1, fillLevel);

  Serial.print("Sensor 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Serial.print("Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Servo control
  if (distance1 < 40) {
    myServo.write(130);
    Serial.println("servo connected");
    delay(3000);
  }
  else {
    myServo.write(0);
    Serial.println("servo notconnected");
  }

  if (fillLevel >= 90) {
  Blynk.virtualWrite(V0, "DUSTBIN FULL");
  Serial.println("DUSTBIN FULL");
}
else if (fillLevel >= 60) {
  Blynk.virtualWrite(V0, "DUSTBIN IS GETTING FULL SOON");
  Serial.println("DUSTBIN IS GETTING FULL SOON");
}
else {
  Blynk.virtualWrite(V0, "DUSTBIN NOT FULL");
  Serial.println("DUSTBIN NOT FULL");
}
          Serial.println("----------------------");

  delay(500);
}