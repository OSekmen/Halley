#include <Servo.h>
Servo myservo;
char buffer[6];
#define THROTTLE_PIN A0
#define ROLL_PIN A3
#define YAW_PIN A2
#define PITCH_PIN A1

int pos = 90;
int throttle;
int roll;
int yaw;
int pitch;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  myservo.attach(9);
}

void loop() {
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

  
  //pos = map(pot,0,1024,0,115);
  //#myservo.write(pos);
}
