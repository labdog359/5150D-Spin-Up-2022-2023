#pragma once

#include "vex.h"
#include "../include/Subsystems/chassis.h"

using namespace vex;

// class to calculate outputs to do with PID 
class PID {
  public:

  // variables defined to be able to tune 
  // on a case by case basis 
  double kp, ki, kd;
  double errorMargin = 1, integralBound = 1, acceleration = 1;

  // calculates PID for any given sensor value 
  // and target 
  double calculate(double, double *ptr);

  // moves a given amounr of inches, at 
  //a given max voltage 
  void move(double target, double maxVoltage); 

  // turns a given degree, at a given max voltage 
  void turn(double targetDegs, double maxVoltage); 

  void flywheelPID(double Velocity, double maxVoltage, double accel);
};
