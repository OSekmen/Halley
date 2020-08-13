#include <Servo.h>
#include <arduino.h>
#include "lib\Flap.h"
#include "lib\Flap.cpp"

#define THROTTLE_PIN A0
#define ROLL_PIN A3
#define YAW_PIN A2
#define PITCH_PIN A1

#define SERVO_1 9
#define SERVO_2 6
#define SERVO_3 5
#define SERVO_4 3

Flap Flap1(45, 135, SERVO_1);
Flap Flap2(45, 135, SERVO_2);
Flap Flap3(45, 135, SERVO_3);
Flap Flap4(45, 135, SERVO_4);

int throttle;
int roll;
int yaw;
int pitch;

void setup()
{
  Serial.begin(9600);
  pinMode(THROTTLE_PIN, INPUT);
  pinMode(ROLL_PIN, INPUT);
  pinMode(YAW_PIN, INPUT);
  pinMode(PITCH_PIN, INPUT);
  pinMode(SERVO_1, OUTPUT);
  pinMode(SERVO_2, OUTPUT);
  pinMode(SERVO_3, OUTPUT);
  pinMode(SERVO_4, OUTPUT);
  Flap1.servoBegin();
  Flap2.servoBegin();
  Flap3.servoBegin();
  Flap4.servoBegin();
}

void loop()
{
  throttle = analogRead(THROTTLE_PIN);
  roll = analogRead(ROLL_PIN);
  yaw = analogRead(YAW_PIN);
  pitch = analogRead(PITCH_PIN);
  Serial.print("throttle: ");
  Serial.print(throttle);
  Serial.print("  roll: ");
  Serial.print(roll);
  Serial.print("  yaw: ");
  Serial.print(yaw);
  Serial.print("  pitch: ");
  Serial.println(pitch);


  Flap1.drive(yaw, 0, 715);
  Flap2.drive(pitch, 0, 715);
  Flap3.drive(yaw, 0, 715);
  Flap4.drive(pitch, 0, 715);
  Serial.print(Flap1.getPos());
  Serial.print("   ");
  Serial.println(Flap3.getPos());
  delay(1);
}