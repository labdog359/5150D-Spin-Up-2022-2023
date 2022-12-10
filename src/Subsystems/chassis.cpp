#include "../include/Subsystems/chassis.h"

competition driverControlComeptition;

bool isHolding = false;

void Chassis::setVoltage(double lVoltage, double rVoltage) {
  frontLeft.spin(fwd, lVoltage, voltageUnits::volt);
  backLeft.spin(fwd, lVoltage, voltageUnits::volt);
  frontRight.spin(fwd, rVoltage, voltageUnits::volt);
  backRight.spin(fwd, rVoltage, voltageUnits::volt);
}

void Chassis::setBraketype(brakeType brake) {
  setVoltage(0, 0);
  frontLeft.setBrake(brake);
  backLeft.setBrake(brake);
  frontRight.setBrake(brake);
  backRight.setBrake(brake);
}

// resets the rotation of every drive base
// motor
void Chassis::reset() {
  frontLeft.resetRotation();
  backLeft.resetRotation();
  frontRight.resetRotation();
  backRight.resetRotation();
}

// DEFINES A AREA WHERE CONTROLLER WILL NOT ACCEPT INPUT
int deadzone = 10;

// DEFINES A BOOLEAN TO HELP SWITCH CONTROLS
bool isArcade = true;

// CREATES AN OBJECT
Chassis controls;

void Chassis::chassisControlArcade() {
  while (1) {
     
    // creates to intergers because the joystick values
    // are only intergers, makes code a bit easier to read
    int leftJoystickVal = 0, rightJoystickVal = 0;

    // ALLOWS FOR CONTROLS TO BE TUNED TO DRIVER'S PREFRENCE
    double sensitivity = 1;
    double turn = 0, power = 0;
    double lOutput = 0, rOutput = 0;

    // makes code a bit easier to read
    leftJoystickVal = Controller1.Axis4.value();
    rightJoystickVal = Controller1.Axis2.value();

    // assigns values by calculating for each side
    // of chassis acording to driver prefernce.
    // use 10.58 because 127(max controller val)
    // divided by 12(max motor voltage) = 10.58
    // allows for linear controll
    turn = (leftJoystickVal * sensitivity) / 10.58;
    power = (rightJoystickVal * sensitivity) / 10.58;

    // assigns to each side
    lOutput = turn + power;
    // turn is negative in one an not another beacuse allows
    // to turn
    rOutput = -turn + power;

    // APPLIES POWER TO THE MOTOR FROM OBJECT
    controls.setVoltage(lOutput, rOutput);

    // CHECKS IF THE CONTROLS ARE MOVING IF NOT
    // SET MOTORS TO BRAKE
    if (Controller1.Axis3.value() < deadzone ||
        Controller1.Axis4.value() < deadzone ||
        Controller1.Axis2.value() < deadzone) {
      //controls.setBraketype(brake);
    }

    // prevents this thread from taking all resources
    this_thread::sleep_for(25);
  }
}

void Chassis::chassisControlArcadeAgressive() {
  float driveConstant = 12 / sqrt(127);
  double sensitivity = 1;
  float outputR, outputL;
  int turn, power;

  Chassis ChassisDrive;
  
  while (1) {
    if(abs(Controller1.Axis4.value()) > sensitivity || abs(Controller1.Axis2.value()) > sensitivity){

      turn = Controller1.Axis4.value();
      power = Controller1.Axis2.value();


        outputR = (abs(power)/power) * sqrt((abs(power)/power) * power) * driveConstant -
                  (abs(turn)/turn) * sqrt((abs(turn)/turn) * turn) * driveConstant;

        outputL = (abs(power)/power) * sqrt((abs(power)/power) * power) * driveConstant +
                  (abs(turn)/turn) * sqrt((abs(turn)/turn) * turn) * driveConstant;
        ChassisDrive.setVoltage(outputL, outputR);

    }
    else {
      ChassisDrive.setBraketype(brake);
    }
  }
}