#include <Servo.h>
#define echoPin 2
#define trigPin 3

// variables
Servo myservo;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);
  delay(1000);
  myservo.write(90);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if(distance <= 30) {
    myservo.write(0);
    delay(3000);
    myservo.write(90);
  }
}
