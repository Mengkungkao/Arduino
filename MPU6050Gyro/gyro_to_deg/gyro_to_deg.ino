#include <Servo.h>

#include <MPU6050_ESP_arrowdot.h>

#include <MPU6050.h>




#include <Wire.h>


#include <math.h>

MPU6050_ESP mpu;

int16_t accY, accZ;
float accAngle;
Servo myservo;
void setup() {  
  myservo.attach(8);
  myservo.writeMicroseconds(100);  
  Serial.begin(9600);
  mpu.begin();
}

void loop() { 
  mpu.update(); 
  accZ = mpu.getAccZ();
  accY = mpu.getAccY();
   
  accAngle = atan2(accY, accZ)*RAD_TO_DEG;
//  
  if(isnan(accAngle));
  else
    Serial.println(accAngle);
    myservo.write(accAngle);
}
