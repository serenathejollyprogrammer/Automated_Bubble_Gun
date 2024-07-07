#include <Servo.h>

Servo myservo;

const int trigPin = 6;
const int echoPin = 7;
const int servoPin = 8;


float duration, distance;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);
  pinMode(servoPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.print(distance, 3);
  Serial.println("cm");
  delay(100);
  if (distance < 30) {
    if (myservo.read() != 120) {
      for (int angle=myservo.read(); angle<121;angle++) {
      myservo.write(angle);
      delay(10);
    }
    }
  }
  else {
    if (myservo.read() != 30) {
      for (int angle=myservo.read(); angle>=30; angle--) {
        myservo.write(angle);
        delay(10);
      }
    }
  }
  }

