
void setup() {

  pinMode(6, OUTPUT);
}

void loop() {
  int i = 0;
  for( i=0; i>=0; i=i+10){
    analogWrite(6, i);
    delay(100);
  }
  
}  
