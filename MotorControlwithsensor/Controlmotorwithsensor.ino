
int buzzer = 11;
int sA0 = A0;
int enA = 10;
int in1 = 9;
int in2 = 8;
const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(sA0, INPUT);
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
void loop() {
    // subtract the last reading:
    total = total - readings[readIndex];
    // read from the sensor:
    int analogSensor = analogRead(sA0);
    // add the reading to the total:
    total = total + readings[readIndex];
    // advance to the next position in the array:
    readIndex = readIndex + 1;
    // if we're at the end of the array...
    if (readIndex >= numReadings) {
      // ...wrap around to the beginning:
      readIndex = 0;
    }
    // calculate the average:
    average = total / numReadings;
    // send it to the computer as ASCII digits
    Serial.print("Pin A0: ");
    Serial.println(analogSensor);
 
    Serial.println(average);
    delay(500);        // delay in between reads for stability
    
    // Checks if it has reached the value
    if (analogSensor >= 200) {
      tone(buzzer, 1000, 200);
      // turn on motor A
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enA, map(average, 200, 900, 50, 255));
    }
    else {
      noTone(buzzer);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enA, 0);
    }
    delay(100);
  }
