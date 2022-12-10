#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// definition of the controller object 
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

// defines the 4 motors on our drive base 
// calls to the motor object, and instatiates 
// the variables for the constructor
motor frontLeft = motor(PORT12, ratio18_1, true);
motor backLeft = motor(PORT11, ratio18_1, true);
motor frontRight = motor(PORT18, ratio18_1, false);
motor backRight = motor(PORT20, ratio18_1, false);

motor flywheel1 = motor(PORT7, ratio6_1, true);
motor flywheel2 = motor(PORT8, ratio6_1, false);

motor intake = motor(PORT6, ratio18_1, false);

motor index_Roller = motor(PORT10, ratio18_1, false);

motor_group chassisRight = motor_group(frontRight, backRight);
motor_group chassisLeft = motor_group(frontLeft, backLeft);

smartdrive SmrtDrive (chassisRight, chassisLeft, IMU, 12.56, 10.75, 10.25, distanceUnits::in);

// defines the interial object, 
// and states it's plugged in to port 12
inertial IMU = inertial(PORT19);

optical Optical = optical(PORT14);

pneumatics launcher  = pneumatics(Brain.ThreeWirePort.A);

pneumatics pistonIndex = pneumatics(Brain.ThreeWirePort.B);

rotation lTracking = rotation(PORT3, true);
rotation rTracking = rotation(PORT2, false);
rotation sTracking = rotation(PORT21, true);

//Brain.ThreeWirePort.A

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}