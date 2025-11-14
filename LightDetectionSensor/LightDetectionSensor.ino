const float r = 100000;
float val,Rldr,vol,Lux;
void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  val = analogRead(A0);
  vol= (val*5)/1023;
  Rldr=(r*(5-vol)/vol)/1000;
  Lux = 500/Rldr;
  Serial.println(String("Lux=")+String(Lux));
  Serial.println(val);
  analogWrite(3,map(val,0,1023,255,0));
  delay(1000);

}
