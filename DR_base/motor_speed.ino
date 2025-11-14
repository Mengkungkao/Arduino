void Limit() {
  if (abs(M1) >= abs(M2) && abs(M1) >= abs(M3) && abs(M1) >= abs(M4)) {
    limit = abs(M1);
  }
  if (abs(M2) >= abs(M1) && abs(M2) >= abs(M3) && abs(M2) >= abs(M4)) {
    limit = abs(M2);
  }
  if (abs(M3) >= abs(M2) && abs(M3) >= abs(M1) && abs(M3) >= abs(M4)) {
    limit = abs(M3);
  }
  if (abs(M4) >= abs(M2) && abs(M4) >= abs(M3) && abs(M4) >= abs(M1)) {
    limit = abs(M4);
  }
}


void V_Motor() {            // 1=rijht 0=left 2=stop
  // oposite position
  if (X < 0 && Y < 0) {   // it oposite position when x and y < 0 //
    if (M > 0) {                                                  // is M<0
      V = map(abs(M), 0, limit, 0, poten_adjust_speed);
      position_motor = 2;
    }
    if (M < 0) {                                                  // is M>0
      V = map(abs(M), 0, limit, 0, poten_adjust_speed);
      position_motor = 1;
    }
    if (M == 0) {
      V = map(abs(M), 0, limit, 0, poten_adjust_speed);
      position_motor = 0;

    }
  }

  // real position
  else {
    if (M > 0) {
      V = map(abs(M), 0, limit, 0, poten_adjust_speed);
      position_motor = 1;
    }
    if (M < 0) {
      V = map(abs(M), 0, limit, 0, poten_adjust_speed);
      position_motor = 2;
    }
    if (M == 0) {
      V = map(abs(M), 0, limit, 0, poten_adjust_speed);
      position_motor = 0;
    }
  }
  Serial.print(position_motor);
  Serial.print(" ");

}

void V_Motor_j() {            // 1=right 2=left 0=stop

  if (M_j > 0) {
    V_j = abs(M_j);
    position_motor = 1;
  }
  if (M_j < 0) {
    V_j = abs(M_j);
    position_motor = 2;
  }
  if (M_j == 0) {
    V_j = 0;
    position_motor = position_motor;
  }
  Serial.print(position_motor_j);
  Serial.print(" ");

}

void MOTOR_speed() {
  if (position_motor == 1) {
    analogWrite(pin_A, pwm);
    analogWrite(pin_B, 0);
  }
  if (position_motor == 2) {
    analogWrite(pin_A, 0);
    analogWrite(pin_B, pwm);
  }
  if (position_motor == 0) {
    analogWrite(pin_A, 0);
    analogWrite(pin_B, 0);
  }

  Serial.print(pwm);
  Serial.print(" ");
}
