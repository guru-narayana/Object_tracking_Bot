#include <AFMotor.h>

#include <Wire.h>
#define SLAVE_ADDRESS 0x04
int number = 0;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    number = Wire.read();
    int s = 90;
     if (number == 1)   // front
     {
    motor1.run(FORWARD);
    motor1.setSpeed(s); 
    delay(1);
    motor2.run(FORWARD);
    motor2.setSpeed(s); 
    delay(1);
    motor3.run(BACKWARD);
    motor3.setSpeed(s);
    delay(1); 
    motor4.run(BACKWARD);
    motor4.setSpeed(s);
    delay(1);
    }
     if (number ==2) // back
    {
    motor1.run(BACKWARD);
    motor1.setSpeed(s); 
    delay(1);
    motor2.run(BACKWARD);
    motor2.setSpeed(s);
    delay(1); 
    motor3.run(FORWARD);
    motor3.setSpeed(s);
    delay(1); 
    motor4.run(FORWARD);
    motor4.setSpeed(s);
    delay(1);
  
  }

    if (number == 3) //right
  {
    motor1.run(FORWARD);
    motor1.setSpeed(s);
    delay(1); 
    motor2.run(FORWARD);
    motor2.setSpeed(s);
    delay(1); 
    motor3.run(FORWARD);
    motor3.setSpeed(s);
    delay(1); 
    motor4.run(FORWARD);
    motor4.setSpeed(s);
    delay(1);
  }
  if (number == 4) //left
  {
  motor1.run(BACKWARD);
  motor1.setSpeed(s);
  delay(1); 
  motor2.run(BACKWARD);
  motor2.setSpeed(s);
  delay(1); 
  motor3.run(BACKWARD);
  motor3.setSpeed(s);
  delay(1); 
  motor4.run(BACKWARD);
  motor4.setSpeed(s);
  delay(1);

  }
   if (number == 0) //stop
  {
  motor1.run(BACKWARD);
  motor1.setSpeed(0);
  delay(1); 
  motor2.run(BACKWARD);
  motor2.setSpeed(0);
  delay(1); 
  motor3.run(BACKWARD);
  motor3.setSpeed(0);
  delay(1); 
  motor4.run(BACKWARD);
  motor4.setSpeed(0);
  delay(1);

  }
}
}
void loop(){}
