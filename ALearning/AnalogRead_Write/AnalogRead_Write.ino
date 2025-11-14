#define Led 3
float v;
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  v=analogRead(A0);
  Serial.println(v*5/1023);
  analogWrite(Led,map(v,0,1023,0,255));
  

}
