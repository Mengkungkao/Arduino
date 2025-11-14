uint32_t PWM_PIN_Rx = 3;
uint32_t PWM_PIN_Ry = 5;
void setup() {
  pinMode(PWM_PIN_Rx,INPUT);
  pinMode(PWM_PIN_Ry,INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(pulseIn(PWM_PIN_Rx,HIGH));
  Serial.print("    ");
  Serial.println(pulseIn(PWM_PIN_Ry, HIGH));
  delay(100);
  
}
