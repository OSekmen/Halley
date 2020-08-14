//polymorphe controller lees functies maken.

#include "Halley.h"
#include <arduino.h>

Flap::Flap(int minAngle, int maxAngle, int servoNumber)
{
    this->minAngle = minAngle;
    this->maxAngle = maxAngle;
    this->servoNumber = servoNumber;
}

void Flap::begin()
{
    pinMode(servoNumber, OUTPUT);
    servo.attach(servoNumber);
    servo.write(pos);
}

int Flap::getPos()
{
    return pos;
}

int Flap::getControlPos()
{

    return controlPos;
}

void Flap::drive(int input, int minInputPWM, int maxInputPWM)
{
    pos = map(input, minInputPWM, maxInputPWM, minAngle, maxAngle);
    controlPos = pos - 90;
    if (pos >= minAngle && pos <= maxAngle && pos != 0)
    {
        servo.write(pos);
    }
}

Controller::Controller(int ThrottlePin, int YawPin, int PitchPin, int RollPin)
{
    this->ThrottlePin = ThrottlePin;
    this->YawPin = YawPin;
    this->PitchPin = PitchPin;
    this->RollPin = RollPin;
}

int Controller::getThrottle()
{
    return analogRead(ThrottlePin);
}
int Controller::getYaw()
{
    return analogRead(YawPin);
}
int Controller::getPitch()
{
    return analogRead(PitchPin);
}
int Controller::getRoll()
{
    return analogRead(RollPin);
}

void Controller::begin()
{
    int flag = 0;
    while (flag == 0)
    {
        Serial.println(getPitch());
    }
}
