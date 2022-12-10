#include "../include/Utils/conversions.h"

double Conversions::ticksToInches(double ticks, float wheelDiameter, double ticksPerRev) {
  return (ticks/ticksPerRev) * (wheelDiameter*M_PI);
}

double Conversions::inchesToTicks(double inches, float wheelDiameter,  double ticksPerRev) {
  return (inches / wheelDiameter * ticksPerRev) * ticksPerRev;
}

double Conversions::ticksToTiles(double ticks, float wheelDiameter,  double ticksPerRev) {
  return ((ticks/ticksPerRev) * (wheelDiameter*M_PI)) / 24;
}

double Conversions::radsToDegs(double rads) {
  return rads * (180/M_PI);
}

double Conversions::degsToRads(double degs) {
  return degs * (M_PI/180);
}

double Conversions::angleWrap(double angle) {
  while (angle < -M_PI){
    angle += 2 * M_PI;
  }
  while(angle > M_PI) {
    angle -= 2 * M_PI;
  }
  return angle; 
}

double Conversions::distanceFormula(double xC, double yC, double xDelta, double yDelta) {
 return hypot(xC - xDelta, yC - yDelta);
}
