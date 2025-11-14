#include<SoftwareSerial.h>
int enA = 10; int in1 = 9; int in2 = 8;
int enB = 5; int in3 = 7; int in4 = 6;

void setup() {
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT); 
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  Serial.begin(9600);
    
}
void loop() {
  if (Serial.available() > 0) {
    String value = Serial.readStringUntil('\n');

    if (value == "F") {
      //motor1
      digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
      analogWrite(enA, 200);
      //motor2
      digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
      analogWrite(enB, 200);
      Serial.println("Forward");
      

    }
   
    else if (value == "B") {
      digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
      analogWrite(enA, 200);
      
      digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
      analogWrite(enB, 200); 
      Serial.println("Backward");
      
    }
    else if (value == "L") {
      digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
      analogWrite(enA, 200);
      digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
      analogWrite(enB, 200);
      Serial.println("Right");
     
      
      
    }
    else if (value == "R") {
      digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
      analogWrite(enA, 200);
      digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
      analogWrite(enB, 200);
      Serial.println("Left");
      
      
      
    }
    delay(1000);
  }
  
  else
  {
    digitalWrite(in1, LOW); digitalWrite(in2, LOW);
    digitalWrite(in3, LOW); digitalWrite(in4, LOW);
    
  }
}
