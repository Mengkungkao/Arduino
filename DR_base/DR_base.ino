#include "calculation.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Encoder.h>

Encoder myEnc_x(27, 29);
Encoder myEnc_y(31, 33);
long oldPosition_x  = -999;
long oldPosition_y  = -999;
float X_from_Rotary = 0;
float Y_from_Rotary = 0;
int button ;
float X_base, Y_base;
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <PS2X_lib.h>  //for v1.6

#define PS2_DAT        53  //14    
#define PS2_CMD        51  //15
#define PS2_SEL        49  //16
#define PS2_CLK        47  //17

//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false
PS2X ps2x;
int error = 0;
byte type = 0;
byte vibrate = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////

float poten_adjust_speed = 100; // speed for Auto
float R = 1;

float X = 0;
float Y = 0;
float Omega = 0; //Omega

// calue from joystick
float Vx_j = 0;         //map from 0 to 182
float Vy_j = 0;         //map from 0 to 182
float Omega_j = 0;      // map from 0 to 255

// if we no have motor during testing, please turn off of void count1 2 3 4
//////////////////////////////////////////////////////////////////////////////////////////////////////

int M1_pin_A = 3;
int M1_pin_B = 2;
int M2_pin_A = 5;
int M2_pin_B = 4;
int M3_pin_A = 10;
int M3_pin_B = 9;
int M4_pin_A = 12;
int M4_pin_B = 11;

int Encoder1_pin_A = 38;
int Encoder1_pin_B = 40;
int Encoder2_pin_A = 42;
int Encoder2_pin_B = 44;
int Encoder3_pin_A = 46;
int Encoder3_pin_B = 48;
int Encoder4_pin_A = 50;
int Encoder4_pin_B = 52;

float M, M_j, V, V_j;
int pin_A;
int pin_B;
float M1, M1_j;
float M2, M2_j;
float M3, M3_j;
float M4, M4_j;
float Vx;
float Vy;
float limit;
float Speed;
float v_1 = 0, v_2 = 0, v_3 = 0, v_4 = 0;
int position_motor, position_motor_j;

//////////////////////////////////////////////////////////////////////////////////////////////////////


//PID
long count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
long  last_count_1 = 0, last_count_2 = 0, last_count_3 = 0, last_count_4 = 0;
float setpoint_1 = 0, setpoint_2 = 0, setpoint_3 = 0, setpoint_4 = 0;
float setpoint_minute_1 = 0, setpoint_minute_2 = 0, setpoint_minute_3 = 0, setpoint_minute_4 = 0;
float RPM_1, RPM_2, RPM_3, RPM_4;
float RPS_1, RPS_2, RPS_3, RPS_4;
long last_time_1 = 0, last_time_2 = 0, last_time_3 = 0, last_time_4 = 0;
int T_1 = 0, T_2 = 0, T_3 = 0, T_4 = 0;
float count_second_1 = 0, count_second_2 = 0, count_second_3 = 0, count_second_4 = 0;
float Round_1 = 0, Round_2 = 0, Round_3 = 0, Round_4 = 0;
double last_time_PID_1 = 0, last_time_PID_2 = 0, last_time_PID_3 = 0, last_time_PID_4 = 0;
double current_time_PID_1 = 0, current_time_PID_2 = 0, current_time_PID_3 = 0, current_time_PID_4 = 0;
double eslapedtime_1 = 0, eslapedtime_2 = 0, eslapedtime_3 = 0, eslapedtime_4 = 0;
float Error_1, Error_2, Error_3, Error_4;
float last_Error_1, last_Error_2, last_Error_3, last_Error_4;
float i_1 = 0, i_2 = 0, i_3 = 0, i_4 = 0;
float d_1 = 0, d_2 = 0, d_3 = 0, d_4 = 0;
float Kp = 12, Ki = 0.019, Kd = 0;            // Kp=12, Ki=0.019, Kd=0 (smoother point)
float setpoint_minute_M1, setpoint_minute_M2, setpoint_minute_M3, setpoint_minute_M4;
float pid_1, pid_2, pid_3, pid_4;
float pwm = 0, pwm_M1 = 0, pwm_M2 = 0, pwm_M3 = 0, pwm_M4 = 0;
/////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //////////////////////////////////////////////////////////////////////////////////////////////////////

  delay(300);
  error = ps2x.config_gamepad(pressures, rumble);
  if (error == 0) {
    Serial.print("Found Controller, configured successful ");
    Serial.print("pressures = ");
    if (pressures)
      Serial.println("true ");
    else
      Serial.println("false");
    Serial.print("rumble = ");
    if (rumble)
      Serial.println("true)");
    else
      Serial.println("false");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Note: Go to www.billporter.info for updates and to report bugs.");
  }
  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  //  Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.print("Unknown Controller type found ");
      break;
    case 1:
      Serial.print("DualShock Controller found ");
      break;
    case 2:
      Serial.print("GuitarHero Controller found ");
      break;
    case 3:
      Serial.print("Wireless Sony DualShock Controller found ");
      break;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////////




  pinMode(M1_pin_A, OUTPUT);
  pinMode(M1_pin_B, OUTPUT);
  pinMode(M2_pin_A, OUTPUT);
  pinMode(M2_pin_B, OUTPUT);
  pinMode(M3_pin_A, OUTPUT);
  pinMode(M3_pin_B, OUTPUT);
  pinMode(M4_pin_A, OUTPUT);
  pinMode(M4_pin_B, OUTPUT);

  detachInterrupt(digitalPinToInterrupt(Encoder1_pin_A));
  detachInterrupt(digitalPinToInterrupt(Encoder1_pin_B));
  detachInterrupt(digitalPinToInterrupt(Encoder2_pin_A));
  detachInterrupt(digitalPinToInterrupt(Encoder2_pin_B));
  detachInterrupt(digitalPinToInterrupt(Encoder3_pin_A));
  detachInterrupt(digitalPinToInterrupt(Encoder3_pin_B));
  detachInterrupt(digitalPinToInterrupt(Encoder4_pin_A));
  detachInterrupt(digitalPinToInterrupt(Encoder4_pin_B));



}

void loop() {
  attachInterrupt(digitalPinToInterrupt(Encoder1_pin_A), encoder_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder1_pin_B), encoder_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder2_pin_A), encoder_2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder2_pin_B), encoder_2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder3_pin_A), encoder_3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder3_pin_B), encoder_3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder4_pin_A), encoder_4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder4_pin_B), encoder_4, CHANGE);


  //////////////////////////////////////////////////////////////////////////////////////////////////////

  joystick();

  //////////////////////////////////////////////////////////////////////////////////////////////////////
  long newPosition_x = myEnc_x.read();
  long newPosition_y = myEnc_y.read();

  if (newPosition_x != oldPosition_x) {
    oldPosition_x = newPosition_x;
    X_from_Rotary = newPosition_x * 1.8212 / 1440;
  }
  if (newPosition_y != oldPosition_y) {
    oldPosition_y = newPosition_y;
    Y_from_Rotary = newPosition_y * 1.8212 / 1440;
  }
  Serial.print(X_from_Rotary);
  Serial.print(" ");
  Serial.println(Y_from_Rotary);
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if (button == 1) {
    X_base = 2; //example
    Y_base = 2;
    adjust_position_base();
  }

  position_base();
  quadrant_base();
  //////////////////////////////////////////////////////////////////////////////////////////////////////

  M1 = calculateV1(Vx, Vy, Omega, R);
  M2 = calculateV2(Vx, Vy, Omega, R);
  M3 = calculateV3(Vx, Vy, Omega, R);
  M4 = calculateV4(Vx, Vy, Omega, R);


  M1_j = calculateV1_j(Vx_j, Vy_j, Omega_j, R);
  M2_j = calculateV2_j(Vx_j, Vy_j, Omega_j, R);
  M3_j = calculateV3_j(Vx_j, Vy_j, Omega_j, R);
  M4_j = calculateV4_j(Vx_j, Vy_j, Omega_j, R);
  //////////////////////////////////////////////////////////////////////////////////////////////////////

  Limit();

  RPM__1();
  M = M1;
  M_j = M1_j;
  V_Motor();
  V_Motor_j();
  v_1 = abs(V - V_j);
  PID__1();
  pwm = pwm_M1;
  pin_A = M1_pin_A;
  pin_B = M1_pin_B;
  MOTOR_speed();
  Serial.print("v_1");
  Serial.print(" ");
  Serial.print(RPM_1);
  Serial.print(" ");


  RPM__2();
  M = M2;
  M_j = M2_j;
  V_Motor();
  V_Motor_j();
  v_2 = abs(V - V_j);
  PID__2();
  pwm = pwm_M2;
  pin_A = M2_pin_A;
  pin_B = M2_pin_B;
  MOTOR_speed();
  Serial.print("v_2");
  Serial.print(" ");
  Serial.print(RPM_2);
  Serial.print(" ");

  RPM__3();
  M = M3;
  M_j = M3_j;
  V_Motor();
  V_Motor_j();
  v_3 = abs(V - V_j);
  PID__3();
  pwm = pwm_M3;
  pin_A = M3_pin_A;
  pin_B = M3_pin_B;
  MOTOR_speed();
  Serial.print("v_3");
  Serial.print(" ");
  Serial.print(RPM_3);
  Serial.print(" ");

  RPM__4();
  M = M4;
  M_j = M4_j;
  V_Motor();
  V_Motor_j();
  v_4 = abs(V - V_j);
  PID__4();
  pwm = pwm_M4;
  pin_A = M4_pin_A;
  pin_B = M4_pin_B;
  MOTOR_speed();
  Serial.print("v_4");
  Serial.print(" ");
  Serial.print(RPM_4);
  Serial.print(" ");

  //serial_print();
  Serial.print(X);
  Serial.println(Y);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


void encoder_1() {
  count_1++;                                         // it counts when has Rising
}
void encoder_2() {
  count_2++;
}
void encoder_3() {
  count_3++;                                         // it counts when has Rising
}
void encoder_4() {
  count_4++;
}
