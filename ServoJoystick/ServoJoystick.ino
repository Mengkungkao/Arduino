#include<Servo.h>
#include<SoftwareSerial.h>
Servo s1;
Servo s2;
int joyX=0;
int joyY=1;
int v;

void setup() {
  s1.attach(9);
  s2.attach(10);

}

void loop() {
  v=analogRead(joyX);
  v= map(v,0,1023,60,120);
  s1.write(v);
  v=analogRead(joyY);
  v= map(v,0,1023,120,60);
  s2.write(v);
}
