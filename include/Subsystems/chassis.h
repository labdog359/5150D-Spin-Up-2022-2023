#pragma once

#include "vex.h"
#include "../include/Competition/driverOp.h"

using namespace vex;

extern bool isHolding;

// class to control chassis
class Chassis {
public:

  void setVoltage(double lVoltage, double rVoltage);

  void setBraketype (brakeType brake);

  // resets all the values to the 6 drive base motors 
  void reset();

  // allows for multithreaded arcade control, using the controller 
  // as input 
  static void chassisControlArcade();
 
  static void chassisControlArcadeAgressive();
};