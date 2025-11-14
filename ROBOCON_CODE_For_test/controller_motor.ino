void control_motor(float SPEED_M1, float SPEED_M2,float SPEED_M3, float SPEED_M4 ){
  float S_M1 = SPEED_M1;
  float S_M2 = SPEED_M2;
  float S_M3 = SPEED_M3;
  float S_M4 = SPEED_M4;

  if ( S_M1 > 0 ){
    analogWrite(M1_pin_A,S_M1);
    analogWrite(M1_pin_B,0);
  }else{
    analogWrite(M1_pin_A,0);
    analogWrite(M1_pin_B,S_M1);
  }
  if ( S_M2 > 0 ){
    analogWrite(M2_pin_A,S_M1);
    analogWrite(M2_pin_B,0);
  }else{
    analogWrite(M2_pin_A,0);
    analogWrite(M2_pin_B,S_M1);
  }
}
