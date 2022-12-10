#pragma once 

#include "vex.h"
#include "../include/Subsystems/indexer.h"
#include "../include/Subsystems/chassis.h"
#include "../include/competition/autonomous.h"
#include "../include/MotionControl/odometry.h"
#include "../include/Subsystems/flywheel.h"
#include "../include/Subsystems/intake.h"
#include "../include/Subsystems/roller.h"


namespace DriverOp {

  // what runs during the 1:15 drive 
  // operation
  void usercontrol();
}

class driverThreads {
  public:
  
  // starts threads needed for driving 
  void start(); 

};