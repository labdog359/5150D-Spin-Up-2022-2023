#pragma once 

#include "vex.h"
#include "../include/MotionControl/PID.h"
#include "../include/MotionControl/autonRoutes.h"
#include "../include/Utils/selector.h"

namespace Autonomous {
  // what should happen before an autonomous 
  void pre_auton();

  // runs during the 15 second auton period 
  void autonomous(); 
}