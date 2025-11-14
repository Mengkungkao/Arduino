#define MQ2pin (0)

float sensorValue; //variable to store sensor value

void setup() {
 Serial.begin(9600); //variable to store sensor value
 Serial.println("Gas sensor warming up");
 delay(20000); //variable to store sensor value
}

void loop() 
{
  sensorValue = analogRead(MQ2pin); //variable to store sensor value

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue > 200);
  {
    Serial.print("Smoke detected!");
  }
  Serial.println("");
  delay(2000); // wait 2s for next reading
 
}
