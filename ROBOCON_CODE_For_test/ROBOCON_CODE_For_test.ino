#include "calculation.h"
#define MAXSPEED 255
#define MINSPEED -255

const byte M1_pin_A = 3;
const byte M1_pin_B = 2;
const byte M2_pin_A = 5;
const byte M2_pin_B = 4;
const byte M3_pin_A = 10;
const byte M3_pin_B = 9;
const byte M4_pin_A = 12;
const byte M4_pin_B = 11;

const byte Encoder1_pin_A = 38;
const byte Encoder1_pin_B = 40;
const byte Encoder2_pin_A = 42;
const byte Encoder2_pin_B = 44;
const byte Encoder3_pin_A = 46;
const byte Encoder3_pin_B = 48;
const byte Encoder4_pin_A = 50;
const byte Encoder4_pin_B = 52;

float position_x=0.00;
float position_y=0.00;
float R=0.00;
float Omega = 0.00;
float Vx=10.00;
float Vy=10.00;


float velocity_M1=0.00;
float velocity_M2=0.00;
float velocity_M3=0.00;
float velocity_M4=0.00;

struct TIMER_STRUCT{
  unsigned long last_time_1;
  unsigned long last_time_2;
  unsigned long last_time_3;
  unsigned long last_time_4;
  unsigned long last_count_1;
  unsigned long last_count_2;
  unsigned long last_count_3;
  unsigned long last_count_4;
  volatile int count_1;
  volatile int count_2;
  volatile int count_3;
  volatile int count_4;
  int encoder_counter_1;
  int encoder_counter_2;
  int encoder_counter_3;
  int encoder_counter_4;
};

struct RPM_MOTOR{
  float motor_1;
  float motor_2;
  float motor_3;
  float motor_4;
};
struct gain_pid{
  float Kp[4];
  float Ki[4];
  float Kd[4];
  float setPoint[4];
};
gain_pid gain={
/* adjust PID gain for M1*/
gain.Kp[0]=10.0,
gain.Ki[0]=0.10,
gain.Kd[0]=0.0,
gain.setPoint[0]=0.0,
/* adjust PID gain for M2*/
gain.Kp[1]=10.0,
gain.Ki[1]=0.10,
gain.Kd[1]=0.0,
gain.setPoint[1]=0.0,
/* adjust PID gain for M3*/
gain.Kp[2]=0.0,
gain.Ki[2]=0.0,
gain.Kd[2]=0.0,
gain.setPoint[2]=0.0,
/* adjust PID gain for M4*/
gain.Kp[3]=0.0,
gain.Ki[3]=0.0,
gain.Kd[3]=0.0,
gain.setPoint[1]=0.0
};

RPM_MOTOR rpm;
TIMER_STRUCT encoder;

class pid_controller{ 
 public:
 struct PID{
  float error[4];
  float pre_error[4];
  float p[4];
  float i[4];
  float d[4];
  unsigned long current_time_pid[4];
  unsigned long last_time_pid[4];
  long elapse_time[4];
  float output[4];  
};
PID pid;
float calculate_pid_M1(){
  pid.current_time_pid[0] = millis();
  pid.elapse_time[0] = pid.current_time_pid[0] - pid.last_time_pid[0];
  pid.pre_error[0] = rpm.motor_1;
  gain.setPoint[0] = velocity_M1;
  pid.error[0] = gain.setPoint[0] - pid.pre_error[0];
  pid.p[0] = gain.Kp[0] * pid.error[0];
  pid.i[0] = gain.Ki[0] + (pid.error[0] * pid.elapse_time[0]);
  pid.d[0] = (pid.error[0]-pid.pre_error[0])/pid.elapse_time[0];
  pid.output[0] = constrain (pid.p[0] + pid.i[0]*gain.Ki[0] + pid.d[0]*gain.Kd[0],MINSPEED,MAXSPEED);
  pid.last_time_pid[0] = pid.current_time_pid[0];
  pid.pre_error[0]=pid.error[0];
  return pid.output[0];
}
float calculate_pid_M2(){
  pid.current_time_pid[1] = millis();
  pid.elapse_time[1] = pid.current_time_pid[1] - pid.last_time_pid[1];
  pid.pre_error[1] = rpm.motor_2;
  gain.setPoint[1] = velocity_M2;
  pid.error[1] = gain.setPoint[1] - pid.pre_error[1];
  pid.p[1] = gain.Kp[1] * pid.error[1];
  pid.i[1] = gain.Ki[1] + (pid.error[1] * pid.elapse_time[1]);
  pid.d[1] = (pid.error[1]-pid.pre_error[1])/pid.elapse_time[1];
  pid.output[1] = constrain (pid.p[1] + pid.i[1]*gain.Ki[1] + pid.d[1]*gain.Kd[1],MINSPEED,MAXSPEED);
  pid.last_time_pid[1] = pid.current_time_pid[1];
  pid.pre_error[1]=pid.error[1];
  return pid.output[1];
}
float calculate_pid_M3(){
  pid.current_time_pid[2] = millis();
  pid.elapse_time[2] = pid.current_time_pid[2] - pid.last_time_pid[2];
  pid.pre_error[2] = rpm.motor_3;
  gain.setPoint[2] = velocity_M3;
  pid.error[2] = gain.setPoint[2] - pid.pre_error[2];
  pid.p[2] = gain.Kp[2] * pid.error[2];
  pid.i[2] = gain.Ki[2] + (pid.error[2] * pid.elapse_time[2]);
  pid.d[2] = (pid.error[2]-pid.pre_error[2])/pid.elapse_time[2];
  pid.output[2] = constrain (pid.p[2] + pid.i[2]*gain.Ki[2] + pid.d[2]*gain.Kd[2],MINSPEED,MAXSPEED);
  pid.last_time_pid[2] = pid.current_time_pid[2];
  pid.pre_error[2]=pid.error[2];
  return pid.output[2];
}
float calculate_pid_M4(){
  pid.current_time_pid[3] = millis();
  pid.elapse_time[3] = pid.current_time_pid[3] - pid.last_time_pid[3];
  pid.pre_error[3] = rpm.motor_4;
  gain.setPoint[3] = velocity_M4;
  pid.error[3] = gain.setPoint[3] - pid.pre_error[3];
  pid.p[3] = gain.Kp[3] * pid.error[3];
  pid.i[3] = gain.Ki[3] + (pid.error[3] * pid.elapse_time[3]);
  pid.d[3] = (pid.error[3]-pid.pre_error[3])/pid.elapse_time[3];
  pid.output[3] = constrain (pid.p[3] + pid.i[3]*gain.Ki[3] + pid.d[3]*gain.Kd[3],MINSPEED,MAXSPEED);
  pid.last_time_pid[3] = pid.current_time_pid[3];
  pid.pre_error[3]=pid.error[3];
  return pid.output[3];
}
};
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
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
  pid_controller compute;
  attachInterrupt(digitalPinToInterrupt(Encoder1_pin_A), encoder_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder1_pin_B), encoder_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder2_pin_A), encoder_2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder2_pin_B), encoder_2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder3_pin_A), encoder_3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder3_pin_B), encoder_3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder4_pin_A), encoder_4, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Encoder4_pin_B), encoder_4, CHANGE);
  readEncoder(); 
  velocity_M1 = calculateV1(Vx, Vy, Omega, R);
  velocity_M2 = calculateV2(Vx, Vy, Omega, R);
  velocity_M3 = calculateV3(Vx, Vy, Omega, R);
  velocity_M4 = calculateV4(Vx, Vy, Omega, R);
  float speed_M1 = compute.calculate_pid_M1();
  float speed_M2 = compute.calculate_pid_M2();
  float speed_M3 = compute.calculate_pid_M3();
  float speed_M4 = compute.calculate_pid_M4();
  
}
void encoder_1(){
  encoder.count_1++;
}
void encoder_2(){
  encoder.count_2++;
}
void encoder_3(){
  encoder.count_3++;
}
void encoder_4(){
  encoder.count_4++;
}
