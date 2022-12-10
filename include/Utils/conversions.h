#pragma once

#include "vex.h"

class Conversions {
  public:

  double ticksToInches(double ticks, float wheelDiameter, double ticksPerRev);

  double inchesToTicks(double inches, float wheelDiameter,  double ticksPerRev);

  double ticksToTiles(double ticks, float wheelDiameter,  double ticksPerRev);

  double radsToDegs(double rads);
  
  double degsToRads(double degs);

  double angleWrap(double angle);

  double distanceFormula(double xC, double yC, double xDelta, double yDelta);

};