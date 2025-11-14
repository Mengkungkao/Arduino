#include<SoftwareSerial.h>
int joyX=0;
int joyY=1;
int vx,vy;

void setup() {
  Serial.begin(9600);
}

void loop() {
  vx=analogRead(joyX);
  Serial.println(vx);
  vy=analogRead(joyY);
  Serial.println(vy);

}
