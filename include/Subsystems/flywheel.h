#pragma once
#include "vex.h" 

class Flywheel {
public:
  double gearRatio = 1;

  double getVelocity();

  void setVoltage(double volts);

  void stop(vex::brakeType typeBrake);

  void velocitySet(double Velocity);

  void setVelocityPct(double percent);
};