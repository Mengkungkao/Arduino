int buzzer = 11;
int sA0 = A0;
int enA = 10;
int in1 = 9;
int in2 = 8;
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(sA0, INPUT);
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  }

void loop() {
    
    int analogSensor = analogRead(sA0);
   
    Serial.print("Pin A0: ");
    Serial.println(analogSensor);
 
    // Checks if it has reached the value
    if (analogSensor >= 50) {
     
      // turn on motor A
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enA, map(analogSensor, 50, 1023, 40, 255));
    }
    else {
    
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enA, 0);
    }
    delay(100);
  }
