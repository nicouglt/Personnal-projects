/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp8266-nodemcu-stepper-motor-28byj-48-uln2003/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  Based on Stepper Motor Control - one revolution by Tom Igoe
*/

#include <AccelStepper.h>

const int stepsPerRevolution = 1024;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 5
#define IN2 4
#define IN3 0
#define IN4 2

#define Btn 14
// initialize the stepper library
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

bool stateBtn;

void setup() {
  // initialize the serial port
  pinMode(Btn, INPUT_PULLUP);
  Serial.begin(115200);
  
  // set the speed and acceleration
  stepper.setMaxSpeed(500);
  stepper.setAcceleration(100);
  // set target position
  stepper.moveTo(stepsPerRevolution);
}

void loop() {
  // check current stepper motor position to invert direction

  stateBtn = digitalRead(Btn);

  if (stateBtn == HIGH){
    stateBtn = 1;
  }


  if (stepper.distanceToGo() == 0 && stateBtn == 1){
    stepper.moveTo(-stepper.currentPosition());
    Serial.println("Changing direction");
    stateBtn = 0;
  }
  // move the stepper motor (one step at a time)
  stepper.run();
}