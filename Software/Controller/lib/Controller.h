#ifndef _Controller_
#define _Controller_

class Controller
{
public:
    Controller(int ThrottlePin, int YawPin, int PitchPin, int RollPin);
    void begin();
    int getThrottle();
    int getYaw();
    int getPitch();
    int getRoll();
    int maxThrottle=700;
    const int minThrottle=50;
    const int maxYaw=740;
    const int maxPitch=740;
    const int maxRoll=740;

private:
    int ThrottlePin;
    int YawPin;
    int PitchPin;
    int RollPin;
    //int throttle;
    //int roll;
    //int yaw;
    //int pitch;
};

#endif