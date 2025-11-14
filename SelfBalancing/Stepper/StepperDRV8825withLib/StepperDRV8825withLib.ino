#include <AccelStepper.h>

/*Example sketch to control a stepper motor with DRV8825 stepper motor driver, AccelStepper library and Arduino: continuous rotation. More info: https://www.makerguides.com */
// Include the AccelStepper library:
#include <accelstepper.h>
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin1 2
#define stepPin1 3
#define dirPin2 4
#define stepPin2 5
#define motorInterfaceType1 1
#define motorInterfaceType2 1
// Create a new instance of the AccelStepper class:
AccelStepper stepper1 = AccelStepper(motorInterfaceType1, stepPin1, dirPin2);
AccelStepper stepper2 = AccelStepper(motorInterfaceType2, stepPin2, dirPin2);
void setup() {
  // Set the maximum speed in steps per second:
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
}
void loop() {
  // Set the speed in steps per second:
  stepper1.setSpeed(500);
  stepper2.setSpeed(500);
  // Step the motor with a constant speed as set by setSpeed():
  stepper1.runSpeed();
  stepper2.runSpeed();
  
}
