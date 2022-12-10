#include "../include/Competition/driverOp.h"

competition driverOpCompetition;

double calcRPM;

// checks if a "shift key is pressed"
// allows for double functionality
// of each key
void shiftKey() {

  Roller shiftRoller;

  while (1) {
    while (Controller1.ButtonR2.pressing()) {
      if (Controller1.ButtonL1.pressing() && !isIntake) {
        intake.spin(fwd, -12, volt);
      } else {
        intake.spin(fwd, 0, volt);
        intake.setBrake(hold);
      }
      while (Controller1.ButtonR1.pressing() &&
             Controller2.ButtonA.pressing()) {
        launcher.set(!launcher.value());
        wait(250, msec);
      }
      while (Controller1.ButtonL2.pressing() && !isIndexing) {
        shiftRoller.setVoltage(12);
        isRolling = true;
      }
      if (isRolling && !isIndexing) {
        shiftRoller.setVoltage(0);
        isRolling = false;
      }

      this_thread::sleep_for(25);
    }
    this_thread::sleep_for(25);
  }
}

void flywheelControl() {
  Flywheel mainFlywheel;
  bool runFlywheel = false;

  mainFlywheel.gearRatio = 6;
  while (1) {
    if (Controller1.ButtonA.pressing() && !Controller1.ButtonR2.pressing()) {
      runFlywheel = !runFlywheel;
      wait(200, msec);
    }
    if (runFlywheel) {
      mainFlywheel.velocitySet(2060);

      Brain.Screen.clearLine();
      Brain.Screen.print(mainFlywheel.getVelocity());
    } else if (!runFlywheel) {

      mainFlywheel.stop(coast);
    }
  }
}

void driverThreads::start() {
  // starts threads for driver control

  thread autoRoller(&Roller::autoRoller);
  thread indexControlThread(&Indexer::indexTrigger);
  thread intakeControlThread(&IntakeControl::intakeTrigger);
  thread flywheelControlThread(&flywheelControl);
  thread driveThread(&Chassis::chassisControlArcadeAgressive);
  thread shift(shiftKey);
  thread rollerthread(&Roller::control);
}

// will stop a given thread
void stop(vex::thread Thread) {
  Thread.interrupt();

  Thread.join();
}

void DriverOp::usercontrol(void) {

  // Brain.Screen.clearScreen();

  // creates a driverThreads object
  // starts the driver threads

  // SmrtDrive.setDriveVelocity(100, pct);

  // SmrtDrive.driveFor(fwd, 12, distanceUnits::in);

  // SmrtDrive.driveFor(fwd, 12, distanceUnits::in);

  // SmrtDrive.driveFor(fwd, -24, distanceUnits::in);

  driverThreads driverControl;
  driverControl.start();

  /*Odometry odom = Odometry(2, 2, .75);

  odom.odomBasic();
  Conversions convert;

  odom.xOffset = 0;
  odom.yOffset = 0;*/

  //while (1) {

    /*odom.odomBasic();

    Brain.Screen.setCursor(10, 10);

    Brain.Screen.print("X: ");
    Brain.Screen.print(odom.x);

    Brain.Screen.newLine();

    Brain.Screen.print("Y: ");
    Brain.Screen.print(odom.y);

    std::cout << "x: " << odom.x << std::endl;
    std::cout << "y: " <<odom.y << std::endl;

    calcRPM =  3.23653 * convert.distanceFormula(-52, -52, odom.x, odom.y);

    wait(500, msec);

    Brain.Screen.clearScreen();*/
  //}
}
