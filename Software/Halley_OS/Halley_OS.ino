#include <Servo.h>
#include <arduino.h>
#include "lib\Halley.h"
#include "lib\Halley.cpp"

#define THROTTLE_PIN 18
#define ROLL_PIN 21
#define PITCH_PIN 20
#define YAW_PIN 19

#define SERVO_1 9
#define SERVO_2 6
#define SERVO_3 5
#define SERVO_4 3

Flap Flap1(45, 135, SERVO_1);
Flap Flap2(63, 145, SERVO_2);
Flap Flap3(40, 130, SERVO_3);
Flap Flap4(45, 135, SERVO_4);
Controller Controller(THROTTLE_PIN, YAW_PIN, PITCH_PIN, ROLL_PIN);

void setup()
{
  Serial.begin(9600);
  Controller.begin();

  Flap1.begin();
  Flap2.begin();
  Flap3.begin();
  Flap4.begin();
}

void loop()
{
  //Flap1.drive(yaw, 0, 715);
  //Flap2.drive(pitch, 0, 715);
  //Flap3.drive(-yaw+715, 0, 715);
  //Flap4.drive(-pitch+715, 0, 715);
}

/*
void printControls(){
  Serial.print("throttle: ");
  Serial.print(throttle);
  Serial.print("  roll: ");
  Serial.print(roll);
  Serial.print("  yaw: ");
  Serial.print(yaw);
  Serial.print("  pitch: ");
  Serial.println(pitch);
  Serial.print("1: ");Serial.println(Flap1.getControlPos());
  Serial.print("2: ");Serial.println(Flap2.getControlPos());
  Serial.print("3: ");Serial.println(Flap3.getControlPos());
  Serial.print("4: ");Serial.println(Flap4.getControlPos());
  Serial.println("\n ----------------------");
}*/
