void PID__1() {
  setpoint_minute_1 = map(v_1, 0, 255, 0, 650);
  setpoint_1 = (setpoint_minute_1 / 60); // convert to Round per Second
  current_time_PID_1 = millis();
  eslapedtime_1 = current_time_PID_1 - last_time_PID_1;

  Error_1 = setpoint_1 - RPS_1;
  i_1 = i_1 + (Error_1 * eslapedtime_1);
  d_1 = (Error_1 - last_Error_1) / eslapedtime_1;
  pid_1 = Kp * Error_1 + Ki * i_1 + Kd * d_1;
  pwm_M1 = constrain(pid_1, 0, 255);

  last_Error_1 = Error_1;
  last_time_PID_1 = current_time_PID_1;
}


void PID__2() {
  setpoint_minute_2 = map(v_2, 0, 255, 0, 650);
  setpoint_2 = (setpoint_minute_2 / 60); // convert to Round per Second
  current_time_PID_2 = millis();
  eslapedtime_2 = current_time_PID_2 - last_time_PID_2;

  Error_2 = setpoint_2 - RPS_2;
  i_2 = i_2 + (Error_2 * eslapedtime_2);
  d_2 = (Error_2 - last_Error_2) / eslapedtime_2;
  pid_2 = Kp * Error_2 + Ki * i_2 + Kd * d_2;
  pwm_M2 = constrain(pid_2, 0, 255);

  last_Error_2 = Error_2;
  last_time_PID_2 = current_time_PID_2;
}


void PID__3() {
  setpoint_minute_3 = map(v_3, 0, 255, 0, 650);
  setpoint_3 = (setpoint_minute_3 / 60); // convert to Round per Second
  current_time_PID_3 = millis();
  eslapedtime_3 = current_time_PID_3 - last_time_PID_3;

  Error_3 = setpoint_3 - RPS_3;
  i_3 = i_3 + (Error_3 * eslapedtime_3);
  d_3 = (Error_3 - last_Error_3) / eslapedtime_3;
  pid_3 = Kp * Error_3 + Ki * i_3 + Kd * d_3;
  pwm_M3 = constrain(pid_3, 0, 255);

  last_Error_3 = Error_3;
  last_time_PID_3 = current_time_PID_3;
}


void PID__4() {
  setpoint_minute_4 = map(v_4, 0, 255, 0, 650);
  setpoint_4 = (setpoint_minute_4 / 60); // convert to Round per Second
  current_time_PID_4 = millis();
  eslapedtime_4 = current_time_PID_4 - last_time_PID_4;

  Error_4 = setpoint_4 - RPS_4;
  i_4 = i_4 + (Error_4 * eslapedtime_4);
  d_4 = (Error_4 - last_Error_4) / eslapedtime_4;
  pid_4 = Kp * Error_4 + Ki * i_4 + Kd * d_4;
  pwm_M4 = constrain(pid_4, 0, 255);

  last_Error_4 = Error_4;
  last_time_PID_4 = current_time_PID_4;
}



void RPM__1() {

  T_1 = millis() - last_time_1;
  if (T_1 >= 100) {
    count_second_1 = count_1 - last_count_1;
    RPS_1 = (count_second_1 * 10) / 540;             // round per Second
    RPM_1 = (RPS_1 * 60);                              //convert to round per minute
    last_count_1 = count_1;
    last_time_1 = millis();
  }

}


void RPM__2() {

  T_2 = millis() - last_time_2;
  if (T_2 >= 100) {
    count_second_2 = count_2 - last_count_2;
    RPS_2 = (count_second_2 * 10) / 540;             // round per Second
    RPM_2 = (RPS_2 * 60);                              //convert to round per minute
    last_count_2 = count_2;
    last_time_2 = millis();
  }

}


void RPM__3() {

  T_3 = millis() - last_time_3;
  if (T_3 >= 100) {
    count_second_3 = count_3 - last_count_3;
    RPS_3 = (count_second_3 * 10) / 540;             // round per Second
    RPM_3 = (RPS_3 * 60);                              //convert to round per minute
    last_count_3 = count_3;
    last_time_3 = millis();
  }

}


void RPM__4() {

  T_4 = millis() - last_time_4;
  if (T_4 >= 100) {
    count_second_4 = count_4 - last_count_4;
    RPS_4 = (count_second_4 * 10) / 540;             // round per Second
    RPM_4 = (RPS_4 * 60);                              //convert to round per minute
    last_count_4 = count_4;
    last_time_4 = millis();
  }

}
