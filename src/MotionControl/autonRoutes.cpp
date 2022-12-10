#include "../include/MotionControl/autonRoutes.h"

void Routes::leftRollerBlue(){
  Flywheel autoFlywheel; 
  autoFlywheel.gearRatio = 5;

  Roller autoRoller;
  Indexer autoIndex;

  PID linear, turn, flywheelpid;

  linear.errorMargin = .5;
  linear.integralBound = 50;

  linear.acceleration = .3;

  linear.kp = 0.01455;
  linear.ki = 0.0295; // 0.02;
  linear.kd = 0.04; // 0.03;

  turn.errorMargin = .1;
  turn.integralBound = 50;

  turn.acceleration = .3;

  turn.kp = 0.11;
  turn.ki = 0.05; // 0.02;
  turn.kd = 0.001; // 0.03;

  flywheelpid.errorMargin = .1;
  flywheelpid.integralBound = 50;

  flywheelpid.acceleration = .3;

  flywheelpid.kp = 0.0115;
  flywheelpid.ki = 0;//0.05; // 0.02;
  flywheelpid.kd = 0;//1; //0.2; // 0.03;

  autoFlywheel.velocitySet(2450);

  autoRoller.setVoltage(12);

  Optical.setLight(ledState::on);

  SmrtDrive.driveFor(fwd, .75, distanceUnits::in);

  //linear.move(2, 12);

  wait(500, msec);

  while(Optical.color() != vex::blue) {
    this_thread::sleep_for(5);
  }

  autoRoller.setVoltage(0);

  Optical.setLight(ledState::off);

  SmrtDrive.driveFor(fwd, -3, distanceUnits::in);
  //linear.move(-3, 12);

  turn.turn(-19, 12);

  wait(2, sec);

  autoIndex.shoot(1);
  
  SmrtDrive.driveFor(fwd, -2, distanceUnits::in);

  wait(4, sec);

  autoIndex.shoot(1);
}

void Routes::leftRollerRed(){
  Flywheel autoFlywheel; 
  autoFlywheel.gearRatio = 5;

  Roller autoRoller;
  Indexer autoIndex;

  PID linear, turn, flywheelpid;

  linear.errorMargin = .5;
  linear.integralBound = 50;

  linear.acceleration = .3;

  linear.kp = 0.01455;
  linear.ki = 0.0295; // 0.02;
  linear.kd = 0.04; // 0.03;

  turn.errorMargin = .1;
  turn.integralBound = 50;

  turn.acceleration = .3;

  turn.kp = 0.11;
  turn.ki = 0.05; // 0.02;
  turn.kd = 0.001; // 0.03;

  flywheelpid.errorMargin = .1;
  flywheelpid.integralBound = 50;

  flywheelpid.acceleration = .3;

  flywheelpid.kp = 0.0115;
  flywheelpid.ki = 0;//0.05; // 0.02;
  flywheelpid.kd = 0;//1; //0.2; // 0.03;

  //autoFlywheel.velocitySet(2450);
  //autoFlywheel.setVoltage(11.9);

  flywheel1.setVelocity(96.75, pct);
  flywheel2.setVelocity(96.75, pct);

  autoRoller.setVoltage(12);

  Optical.setLight(ledState::on);

  SmrtDrive.driveFor(fwd, .75, distanceUnits::in);

  //linear.move(2, 12);

  wait(500, msec);

  while(Optical.color() != red) {
    this_thread::sleep_for(5);
  }

  autoRoller.setVoltage(0);

  Optical.setLight(ledState::off);

  SmrtDrive.driveFor(fwd, -3, distanceUnits::in);
  //linear.move(-3, 12);

  turn.turn(-20, 12);

  wait(2, sec);

  autoIndex.shoot(1);
  
  //SmrtDrive.driveFor(fwd, -2, distanceUnits::in);

  //wait(4, sec);

  autoIndex.shoot(1);
}

void Routes::rightRollerRed(){
  Flywheel autoFlywheel;
  Indexer autoIndex;

  PID turn;

  turn.errorMargin = .1;
  turn.integralBound = 50;

  turn.acceleration = .3;

  turn.kp = 0.11;
  turn.ki = 0.05; // 0.02;
  turn.kd = 0.001; // 0.03;

  Roller autoRoller;

  autoFlywheel.velocitySet(2800);

  SmrtDrive.driveFor(fwd, 24, distanceUnits::in);

  turn.turn(90, 12);

  SmrtDrive.driveFor(fwd, 4.85, distanceUnits::in);

  autoRoller.setVoltage(12);

  Optical.setLight(ledState::on);

  SmrtDrive.driveFor(fwd, .75, distanceUnits::in);

  //linear.move(2, 12);

  wait(500, msec);

  while(Optical.color() != red) {
    this_thread::sleep_for(5);
  }

  autoRoller.setVoltage(0);

  Optical.setLight(ledState::off);

  SmrtDrive.driveFor(reverse, 4, distanceUnits::in);

  turn.turn(-6, 12);

  wait(6, sec);

  autoIndex.shoot(1);

  wait(4, sec);

  autoIndex.shoot(1);
}

void Routes::rightRollerBlue(){
  Flywheel autoFlywheel;
  Indexer autoIndex;

  PID turn;

  turn.errorMargin = .1;
  turn.integralBound = 50;

  turn.acceleration = .3;

  turn.kp = 0.11;
  turn.ki = 0.05; // 0.02;
  turn.kd = 0.001; // 0.03;

  Roller autoRoller;

  autoFlywheel.velocitySet(2800);

  SmrtDrive.driveFor(fwd, 24, distanceUnits::in);

  turn.turn(90, 12);

  SmrtDrive.driveFor(fwd, 4.85, distanceUnits::in);

  autoRoller.setVoltage(12);

  Optical.setLight(ledState::on);

  SmrtDrive.driveFor(fwd, .75, distanceUnits::in);

  //linear.move(2, 12);

  wait(500, msec);

  while(Optical.color() != blue) {
    this_thread::sleep_for(5);
  }

  autoRoller.setVoltage(0);

  Optical.setLight(ledState::off);

  SmrtDrive.driveFor(reverse, 4, distanceUnits::in);

  turn.turn(-6, 12);

  wait(6, sec);

  autoIndex.shoot(1);

  wait(4, sec);

  autoIndex.shoot(1);
}

void Routes::skills(){
  Indexer autoIndex;
  Chassis autoChassis;

  autoIndex.setVoltage(12);

  SmrtDrive.driveFor(fwd, 2, distanceUnits::in);

  Optical.setLight(ledState::on);

  wait(1, sec);

  while(Optical.color() != red){
    SmrtDrive.driveFor(fwd, .5, distanceUnits::in);

  }

  //wait(.5, sec);

  autoIndex.setVoltage(0);

  SmrtDrive.driveFor(reverse, 10, distanceUnits::in);

  SmrtDrive.setTurnVelocity(10, pct);

  SmrtDrive.turn(left);

  while(IMU.angle() < 45 || IMU.angle() > 55){
    wait(50, msec);
  }

  autoChassis.setBraketype(hold);

  launcher.open();
}

void Routes::setColor(vex::color newColor){
  rollColor = newColor;
}
  