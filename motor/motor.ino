


#include <AccelStepper.h>           // Load the AccelStepper library
#include <stepper>
#define motorPin1  8                // IN1 pin on the ULN2003A driver
#define motorPin2  9                // IN2 pin on the ULN2003A driver
#define motorPin3  10               // IN3 pin on the ULN2003A driver
#define motorPin4  11               // IN4 pin on the ULN2003A driver

int stepsPerRevolution = 64;        // steps per revolution
float degreePerRevolution = 5.625;  // degree per revolution


 * AccelStepper::FULL2WIRE (2) means: 2 wire stepper (2 pins needed). 
 * AccelStepper::FULL3WIRE (3) means: 3 wire stepper, like a harddisk motor (3 pins needed). 
 * AccelStepper::FULL4WIRE (4) means: 4 wire stepper (4 pins needed). 
 * AccelStepper::HALF3WIRE (6) means: 3 wire half stepper, like a harddisk motor (3 pins needed) 
 * AccelStepper::HALF4WIRE (8) means: 4 wire half stepper (4 pins needed) 
 *
 * AccelStepper uses AccelStepper::FULL4WIRE (4 pins needed) by default.
 
AccelStepper stepper(AccelStepper::HALF4WIRE, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  Serial.begin(9600);               // initialise the serial monitor

  stepper.setMaxSpeed(1000.0);      // set the max motor speed
  stepper.setAcceleration(100.0);   // set the acceleration
  stepper.setSpeed(200);            // set the current speed

  stepper.moveTo(degToSteps(90));   // order the motor to rotate 90 degrees forward

}

void loop() {
  stepper.run();                    // start moving the motor
}

/*
 * Converts degrees to steps
 * 
 * 28BYJ-48 motor has 5.625 degrees per step
 * 360 degrees / 5.625 = 64 steps per revolution
 * 
 * Example with degToSteps(45):
 * (64 / 5.625) * 45 = 512 steps
 */
float degToSteps(float deg) {
  return (stepsPerRevolution / degreePerRevolution) * deg;
}