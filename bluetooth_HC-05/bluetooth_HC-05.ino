#include<SoftwareSerial.h>


void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String value = Serial.readStringUntil('\n');

    if (value == "On") {
      digitalWrite(12, HIGH);
      Serial.println("LED: ON");
      

    }
    else if (value == "Off") {
      digitalWrite(12, LOW);
      Serial.println("LED:OFF");
      
    }
  }

}
