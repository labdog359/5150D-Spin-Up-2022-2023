#pragma once

#include "vex.h"
#include "../include/Subsystems/flywheel.h"
#include "../include/Subsystems/intake.h"
#include "../include/Subsystems/roller.h"
#include "../include/Subsystems/indexer.h"
#include "../include/Subsystems/chassis.h"


class Routes{
  vex::color rollColor = blue;
public:

  void setColor(vex::color newColor);

  void leftRollerBlue();
  void leftRollerRed();

  void rightRollerBlue();
  void rightRollerRed();

  void skills();
};