#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
void setup() {

  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void loop()
{
int front = analogRead(A3);
int back = analogRead(A2);
int left = analogRead(A1);
int right = analogRead(A0);
  if (front > 200){
  motor1.run(FORWARD);
  motor1.setSpeed(255); 
  motor2.run(FORWARD);
  motor2.setSpeed(255); 
  motor3.run(BACKWARD);
  motor3.setSpeed(255); 
  motor4.run(BACKWARD);
  motor4.setSpeed(255);
  delay(20);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  delay(20);}
    if (back > 200){
  motor1.run(BACKWARD);
  motor1.setSpeed(255); 
  motor2.run(BACKWARD);
  motor2.setSpeed(255); 
  motor3.run(FORWARD);
  motor3.setSpeed(255); 
  motor4.run(FORWARD);
  motor4.setSpeed(255);
  delay(20);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  delay(20);}
    if (right > 200){
  motor1.run(FORWARD);
  motor1.setSpeed(255); 
  motor2.run(FORWARD);
  motor2.setSpeed(255); 
  motor3.run(FORWARD);
  motor3.setSpeed(255); 
  motor4.run(FORWARD);
  motor4.setSpeed(255);
  delay(20);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  delay(20);}
    if (left > 200){
  motor1.run(BACKWARD);
  motor1.setSpeed(255); 
  motor2.run(BACKWARD);
  motor2.setSpeed(255); 
  motor3.run(BACKWARD);
  motor3.setSpeed(255); 
  motor4.run(BACKWARD);
  motor4.setSpeed(255);
  delay(20);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  delay(20);}

  }