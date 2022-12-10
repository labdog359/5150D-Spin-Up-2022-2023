#include "../include/MotionControl/odometry.h"

void bs(){
  
}

void Odometry::odomBasic() {
  double prevRTicks = 0, prevSTicks = 0;
  double tempX, tempY;

  theta = (odomConversions.degsToRads(IMU.rotation()) +
           (odomConversions.degsToRads(lTracking.position(deg)) -
            odomConversions.degsToRads(rTracking.position(deg))) /
               (sl + sr)) /
          2;

  tempX = (2 * sin(theta / 2)) *
          ((sTracking.position(deg) - prevSTicks / theta) + ss);
  tempY = (2 * sin(theta / 2)) *
          (((rTracking.position(deg) - prevRTicks) / theta) + sr);

  prevRTicks = rTracking.position(deg);
  prevSTicks = sTracking.position(deg);

  double avgA = theta + (theta / 2);

  double polarR = sqrt((tempX * tempX) + (tempY * tempY));
  double polarA = atan2(tempY, tempX) - avgA;

  double dX = sin(polarA) * polarR;
  double dY = cos(polarA) * polarR;

  if (std::isnan(dX)) {
    x = 0;
  }
  if (std::isnan(dY)) {
    y = 0;
  } else {
    x = dX;
    y = dY;
  }
  x = (x * (2.75 * M_PI)) / (360) + xOffset;
  y = (y * (2.75 * M_PI)) / (360) + yOffset;
}
