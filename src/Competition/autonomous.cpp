#include "../include/Competition/autonomous.h"

void Autonomous::pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Screen.print("Wait...");

  launcher.close();

  IMU.calibrate();

  while (IMU.isCalibrating()) {
    wait(5, msec);
  }
  Brain.Screen.clearScreen();
}

void Autonomous::autonomous(void) {

  /*PID test, test1;

  test.errorMargin = .5;
  test.integralBound = 50;

  test.acceleration = .3;

  test.kp = 0.01455;
  test.ki = 0.0295; // 0.02;
  test.kd = 0.04; // 0.03;

  //test.move(24, 12);
  //test.move(24, 12);
  //test.move(-48, 12);

  test1.errorMargin = .1;
  test1.integralBound = 50;

  test1.acceleration = .3;

  test1.kp = 0.11;
  test1.ki = 0.05; // 0.02;
  test1.kd = 0.001; // 0.03;

  test1.turn(90, 12);*/

  /*Indexer autoIndex;

  autoIndex.setVoltage(12);

  SmrtDrive.driveFor(fwd, 2, distanceUnits::in);

  Optical.setLight(ledState::on);

  wait(1, sec);

  while(Optical.color() != vex::blue){
    SmrtDrive.driveFor(fwd, .5, distanceUnits::in);

  }

  //wait(.5, sec);

  autoIndex.setVoltage(0);

  SmrtDrive.driveFor(reverse, 3, distanceUnits::in);*/

  // wipes the auton selector from the
  // screen
  /*Brain.Screen.clearScreen();

  Indexer autoIndex;

  autoIndex.setVoltage(12);

  SmrtDrive.driveFor(fwd, 2, distanceUnits::in);

  Optical.setLight(ledState::on);

  wait(1, sec);

  while(Optical.color() != vex::blue){
    SmrtDrive.driveFor(fwd, .5, distanceUnits::in);

  }

  //wait(.5, sec);

  autoIndex.setVoltage(0);

  SmrtDrive.driveFor(reverse, 3, distanceUnits::in);

  PID test;

  test.errorMargin = 1;
  test.integralBound = 200;

  test.acceleration = 1;

  test.kp = 0.015;
  test.ki = 0;//0.015;
  test.kd = 0;//0.006;

  test.move(24, 12);
  //est.move(12, 12);
  //test.move(-24, 12);*/

  /*SmrtDrive.setTurnVelocity(10, pct);
  SmrtDrive.turn(left);

  while(IMU.angle() < 80 || IMU.angle() > 90){
    wait(50, msec);
  }

  autoChassis.setBraketype(hold);

  autoFlywheel.velocitySet(3000);

  wait(3, sec);

  autoIndex.setVoltage(12);

  for(int i = 0; i < 5; i++){
    autoChassis.setVoltage(12, 12);
    wait(.25, sec);
    autoChassis.setBraketype(hold);
    autoChassis.setVoltage(-12, -12);
    wait(.25, sec);

    //SmrtDrive.driveFor(fwd, 3, distanceUnits::in);
    //SmrtDrive.driveFor(reverse, 3, distanceUnits::in);
  }

  autoChassis.setBraketype(hold);


  wait(5, sec);

  autoIndex.setVoltage(0);
  autoFlywheel.velocitySet(0);*/

  /*SmrtDrive.driveFor(fwd, 1, distanceUnits::in);

  index_Roller.setMaxTorque(100, pct);
  index_Roller.spin(fwd, 12, volt);
  wait(1, sec);
  index_Roller.spin(fwd, 0, volt);



  SmrtDrive.driveFor(reverse, 1, distanceUnits::in);*/

  PID flywheelpid;

  flywheelpid.errorMargin = .1;
  flywheelpid.integralBound = 50;

  flywheelpid.acceleration = .3;

  flywheelpid.kp = 0.010;
  flywheelpid.ki = 0.0;//055;//0.05; // 0.02;
  flywheelpid.kd = 0.0;//025;//1; //0.2; // 0.03;

  //flywheelpid.flywheelPID(2400, 12, .05);

  Flywheel fw;
  fw.setVoltage(10.5);

  Routes route;

  // one of these will run when selected
  // on the autonomous selector
  switch (autonToRun) {
  case 0:
    //route.skills();
    break;

  case 1:
    route.leftRollerRed();
    break;

  case 2:
    route.rightRollerRed();
    break;

  case 3:
    route.leftRollerBlue();

    break;

  case 4:
    route.rightRollerBlue();
    break;
  }
}