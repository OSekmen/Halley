//polymorphe controller lees functies maken.

#include "Controller.h"
#include <arduino.h>

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
    int flag = 1;
    unsigned long time = 0;
    unsigned long prevtime = 0;
    int throttle = getThrottle();
    while (flag == 0)
    {
        while (throttle == getThrottle() && throttle > 700 && flag == 0)
        {
            time = millis();
            prevtime = time;
            Serial.print("time - prevtime=  ");Serial.println(time - prevtime);

            while (time - prevtime < 1000)
            {
                Serial.println("Time Loop");
                if (throttle != getThrottle())
                {
                    prevtime = millis();
                    Serial.println("Reset");
                }
                Serial.println("BREAAAK");
                time = millis();
            }
            Serial.println("Skip");
            maxThrottle = throttle;
            flag = 1;
            Serial.println(throttle);
        }
        throttle = getThrottle();
    }
    Serial.println(maxThrottle);
}
