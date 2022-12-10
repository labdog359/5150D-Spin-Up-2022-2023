#include "../include/purePursuit.h"
#include "../include/MotionControl/odometry.h"
#include "../include/Utils/conversions.h"

void RoboMovement::moveToPoint(double x, double y, double movementSpeed) {
  Conversions convert;

  Odometry pP = Odometry(2.55, 2.55, 2.55);
  // this should be made global. just for testing rn 
  pP.odomBasicStart();

  double distanceToTarget = std::hypot(x - pP.x, y- pP.y);

  double absAngleTarget = atan2(y - pP.y, x - pP.x);

  double relativeAngleTarget = convert.angleWrap(absAngleTarget - pP.theta);

  double relativeXToTarget = cos(relativeAngleTarget) * distanceToTarget;
  double relativeYToTarget = sin(relativeAngleTarget) * distanceToTarget;

  double movementXPow = relativeXToTarget / (fabs(relativeXToTarget) + fabs(relativeYToTarget));
  double movementYPow = relativeYToTarget / (fabs(relativeXToTarget) + fabs(relativeYToTarget));
}