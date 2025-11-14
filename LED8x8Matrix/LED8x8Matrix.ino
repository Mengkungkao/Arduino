 int data[][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0}
};

void setup() {
  for (int i=2; i<=9; i++) {
    pinMode(i, OUTPUT);
    pinMode(i+20, OUTPUT);
    digitalWrite(i, LOW);
    digitalWrite(i+20, HIGH);    
  }

  pinMode(A0, INPUT);
}

void loop() {
  for (int i=0; i<8; i++) {
    if (i==0) {
      digitalWrite(9, LOW);    
    }
    else {
      digitalWrite(i+1, LOW);
    }

    for (int j=0; j<8; j++) {
      if (data[i][j] == 1) {
        digitalWrite(j+22, LOW);
      }
      else {
        digitalWrite(j+22, HIGH);
      }
    }
    digitalWrite(i+2, HIGH);

    delay(analogRead(A0) / 10);
  }
}
