#include <Servo.h>
Servo myservo;
char buffer[6];
int pos=90;
int pot;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  myservo.attach(9);
 }

void loop() {
  pot= analogRead(A0);
  pos = map(pot,0,1024,0,115);
  myservo.write(pos);
  //Serial.print("Pot: ");
  //Serial.print(analogRead(A0));
  //Serial.print("  Angle: ");
  //Serial.println(pos);
  }
