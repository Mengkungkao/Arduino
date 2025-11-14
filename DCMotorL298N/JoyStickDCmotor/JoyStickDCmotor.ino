#include<SoftwareSerial.h>
int enA = 10; int in1 = 9; int in2 = 8;
int enB = 5; int in3 = 7; int in4 = 6;
int joyX=0;
int joyY=1;
int vx,vy;
void setup() {
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  Serial.begin(9600);
}
void demoOne() {
  vx=analogRead(joyX);
  Serial.println(vx);
  vx=map(vx,504,0,0,200);
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  analogWrite(enA, vx);
  vy=analogRead(joyY);
  Serial.println(vy);
  vy=map(vy,510,0,0,200);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enB, vy); 
}
void loop() {
  demoOne();
  delay(100);
}
