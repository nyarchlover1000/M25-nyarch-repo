#include "MecanumRobot.h"
const int trigPin = 7;
const int echoPin = 8;

MecanumRobot robot(4, 3, 6, 5, 10, 9, 12, 11);

int turnCount = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
  robot.begin();
  robot.setTurnTime(600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
   long duration;
  float distance;
   digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  if (turnCount >= 1) {
    robot.forwardStart();
    delay(3200);
    robot.stop();
    delay(100000);
  }

  //read echo pin time
  duration = pulseIn(echoPin, HIGH);

  //time to distance
  distance = duration * 0.034 / 2;

  //print the result
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");


  if (distance > 10) {
robot.forwardStart();
delay(100);
} else {
  robot.stop();
  delay(100);
  robot.right(150);
  delay(1000);
       long duration;
   digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    if(distance <= 10) {
    robot.left(300);
    delay(1000);
    turnCount = turnCount + 1;
  } else {
    robot.forwardStart();
  }
  }
}


