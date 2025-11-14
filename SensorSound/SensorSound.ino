int ss = 2;
int led = 13;

void setup() {
  pinMode(ss, INPUT);  
  pinMode(led, OUTPUT);
}

void loop() {
  if(digitalRead(ss)== 1){
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
   
  }
}
