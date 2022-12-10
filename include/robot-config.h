using namespace vex;

// this entire file globilizes the objects 
// in the robot-config.cpp file

// global definition of the brain
extern brain Brain;

// CONTROLLER(S)
extern controller Controller1;
extern controller Controller2;

// INERTIAL SENSONRS
extern inertial IMU;

// CHASSIS MOTORS
extern motor frontLeft;
extern motor backLeft;
extern motor frontRight;
extern motor backRight;

extern motor flywheel1;
extern motor flywheel2;

extern motor intake;

extern motor index_Roller;

extern optical Optical;

extern smartdrive SmrtDrive;

extern pneumatics launcher;

extern pneumatics pistonIndex;

// TRACKING WHEELS
extern rotation lTracking;
extern rotation rTracking;
extern rotation sTracking;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
