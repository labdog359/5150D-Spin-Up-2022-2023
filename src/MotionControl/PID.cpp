#include "../include/MotionControl/PID.h"

// create the timer object to enable for time 
// keeping and calculation of dt
timer Timer;



//********************************************//
//                                            //
//                                            //
//                                            //
//                  TURN PID                  //
//                                            //
//                                            //
//                                            //
//********************************************//


// this method allows you to turn a given amount of degrees 
// at a given max voltage using a PID controller
// this controller allows for percise movement
void PID::turn(double targetDegs, double maxVoltage) {

  // creates the chassisPID object which allows access 
  // to the chassis_Set class, with methods used for the 
  // chassis move method 
  Chassis chassisPID; 

  // variable instantiation

  // error = errorMargin + 1 allows for the while loop to start 
  // then update once it is in the loop
  double error = errorMargin + 1, integral = 0, derivetive = 0; 
  double sensorVal = 0;

  double volCap = 0;

  int sign = 0; 

  // this allows us to get a refrence as to where the position 
  // of the robot is. This is subtracted from the position of the robot 
  // as it updates which allows to get a change in angle without resetting 
  // the IMU which would mess up other code 
  double enterAngle = IMU.rotation(); 

  double prevError = 0, prevTime = 0, dt = 0; 

  double output = 0;

  // checks if the robot has moved, if it hasent 
  // continue, if it has wait and update this variable
  if (fabs(enterAngle -  IMU.rotation()) > 0) {
    wait(100, msec);
    enterAngle = IMU.rotation();
  }

  // checks if the robot position is within 
  // a given range of the target position
  while(fabs(error) > errorMargin) {

    // calculates the diffrence from the robots current 
    // and the position of the robot when it entered the function
    sensorVal = IMU.rotation() - enterAngle;

    std::cout << IMU.rotation() << std::endl;

    // finds the diffrence of the robots current position 
    // and the target position 
    error = targetDegs - sensorVal; 

    // updates the prevError variable
    prevError = error; 

    // updates the intergral variable 
    integral += error; 

    // calculates dt, the amount of time 
    // that has passed 
    dt = (Timer.time() - prevTime) / 1000;

    // figures out how close the robot is to the
    // target position. as the robot get closer 
    // derivetive gets smaller
    derivetive = (error - prevError) / dt;

    // limits integral, if it is outside a 
    // given range integral will be set to 0
    if (fabs(integral) > integralBound){
      integral = 0; 
    }

    // calculates output given all terms, and constants 
    output = (error * kp) + (integral * ki) + (derivetive * kd); 

    // finds wether the output is positive or negative 
    // one side is set to the absoulte value because 
    // would be always positive otherwise 
    sign = fabs(output) / output;

    // if output is greater than a given value 
    // output will be set to that given value
    // and to the correct sign
    if (fabs(output) > maxVoltage)
      output = maxVoltage * sign;

    // volcap is added to acceleration which 
    // has the same sign as output 
    volCap += acceleration * sign;

    // if the voltage cap greater than the 
    // given max voltage set the voltage cap 
    // to the max voltage of the same sign as output 
    if (fabs(volCap) > fabs(maxVoltage)) {
      volCap = maxVoltage * sign;
    }

    // if the output is greater than the voltage cap
    // set it to voltage cap 
    if (fabs(output) > fabs(volCap)) {
      output = volCap;
    }

    // limits that output to be 12 trough -12
    // as that is the max voltage of the motors
    if (fabs(output) > 12 ) {
      output = 12 * sign; 
    }
    
    // applies the voltage to the chassis using 
    // the chassisPID object at the top 
    chassisPID.setVoltage(output, -output);

    // updates prevTime 
    prevTime = Timer.time();

    // waits to allow for the values to update 
    wait(15, msec);
  } 

  // check to see if the function has completed 
  // used for debugging 
  std::cout << "done ;)" << std::endl;

  // stops the chassis when it is done using the 
  // chassisPID object
  chassisPID.setBraketype(hold); 
}


//***************************************//
//                                       //
//                                       //
//                                       //
//                  PID                  //
//                                       //
//                                       //
//                                       //
//************************************** //

// allows for linear motion 
// uses a PID controller to move percisely 
// given a distance in inches, and a max voltage
void PID::move (double target, double maxVoltage) {
  // creates the chassisPID object which allows access 
  // to the chassis_Set class, with methods used for the 
  // chassis move method 
  Chassis chassisPID; 

  //double errorMargin = 5;

  // error = errorMargin + 1 allows for the while loop to start 
  // then update once it is in the loop
  double error = errorMargin + 1, integral = 0, derivetive = 0; 
  double sensorVal = 0;

  double volCap = 0;

  int sign = 0; 

  // variables used to find the the diffence in angle as the robot drives 
  // and correct as it goes 
  // the finds the angle before the robot has started moving 
  double correctionOutput = 0, targetAngle = 0, enterAngle = IMU.rotation(); 

  double prevError = 0, prevTime = 0, dt = 0; 

  // finds the value as the robot enters the method which allows for
  // finding the diffrence in value from where the robot starts to where it 
  // curently is allows us to find the robots local change without resetting the 
  // internal motor encoders 
  double enterVal = (lTracking.position(deg) + rTracking.position(deg)) / 2; 

  // kp constatnt for turning correction 
  double kt = .5; 

  double output = 0;

  
  target = (target / (2.75 * M_PI)) * 360;

  std::cout << "Target: " << target << std::endl;

  //(target * 41.6);
  // target * ((degs per 1 rev) / (wheelDiameter * M_PI))
  //(30000 * target) / (wheelDiameter * M_PI);
  //(((target * (360)) / (wheelDiameter * M_PI)) * (drivenGear/driveGear)); //* (2/3);
  

  std::cout << std::endl;

  // checks if robot is fully stopped then updates enter value if is not 
  if (enterVal - ((lTracking.position(deg) + rTracking.position(deg)) / 2) > 0) {
    wait(100, msec);
    enterVal = (lTracking.position(deg) + rTracking.position(deg)) / 2;
  }
  
  while(fabs(error) > errorMargin) {

    // updates sensor val every run
    sensorVal = ((lTracking.position(deg) + rTracking.position(deg)) / 2) - enterVal;

    // recalculates error with new sensor val
    error = target - sensorVal; 

    // updates prev error 
    prevError = error; 

   // updates the intergral variable 
    integral += error; 

    // calculates dt, the amount of time 
    // that has passed 
    dt = (Timer.time() - prevTime) / 1000;

    // figures out how close the robot is to the
    // target position. as the robot get closer 
    // derivetive gets smaller
    derivetive = (error - prevError) / dt;

    // limits integral, if it is outside a 
    // given range integral will be set to 0
    if (fabs(integral) > integralBound){
      integral = 0; 
    }

    // finds the diffrence in the current angle and 
    // target angel (0)
    // a p loop to correct drifting 
    correctionOutput = (targetAngle - (IMU.rotation() - enterAngle)) * kt;

    // calculates output using all terms, and constants 
    output = (error * kp) + (integral * ki) + (derivetive * kd); 

   // finds wether the output is positive or negative 
    // one side is set to the absoulte value because 
    // would be always positive otherwise 
    sign = fabs(output) / output;

    // if output is greater than a given value 
    // output will be set to that given value
    // and to the correct sign
    if (fabs(output) > maxVoltage)
      output = maxVoltage * sign;

    // volcap is added to acceleration which 
    // has the same sign as output 
    volCap += acceleration * sign;

    // if the voltage cap greater than the 
    // given max voltage set the voltage cap 
    // to the max voltage of the same sign as output 
    if (fabs(volCap) > fabs(maxVoltage)) {
      volCap = maxVoltage * sign;
    }

    // if the output is greater than the voltage cap
    // set it to voltage cap 
    if (fabs(output) > fabs(volCap)) {
      output = volCap;
    }

  
    // outputs the voltage to the chassis with correction 
    // output added and subtracted to each side to allow for turning 
    chassisPID.setVoltage(output + correctionOutput, output - correctionOutput);

    // udates prev time
    prevTime = Timer.time();

    // allows for values to update 
    wait(15, msec);
  } 

  // check to see if method has executed 
  // debugging 
  std::cout << "done ;)" << std::endl;

  // holds the chassis in place 
  // prevents drifting 
  chassisPID.setBraketype(hold); 
}

// calculates PID for any target and any value 
double PID::calculate(double target, double *sensorData) {

  // allows to enter while loop 
  double error = errorMargin + 1;
  double integral = 0, derivetive = 0, dt = 0; 
  double prevError, prevTime = 0;

  double sensor = 0; 

  // is a pointer to allow for updating in througout the 
  // code, updates the memory adress 
  double *output = 0;

  sensorData = &sensor; 

  while(fabs(error) > errorMargin) {

    // finds the diffrence between curent value and 
    // disired value 
    error = target - *sensorData;

    // updates prev error 
    prevError = error;

    // adds integral to error, which is set to the value of
    // integral 
    integral += error;

    // calculates dt, the amount of time 
    // that has passed 
    dt = (Timer.time() - prevTime) / 1000;

    // figures out how close the robot is to the
    // target position. as the robot get closer 
    // derivetive gets smaller
    derivetive = (error - prevError) / dt;

    // limits integral, if it is outside a 
    // given range integral will be set to 0
    if (fabs(integral) > integralBound){
      integral = 0; 
    }

    // calculates output using all terms, and constants     
    *output = (error * kp) + (integral * ki) + (derivetive * kd); 

    // returns the output to be processed 
    return *output; 
  }  

  // returns 0 if nothing happens
  return 0; 
}


void PID::flywheelPID(double Velocity, double maxVoltage, double accel){
  Flywheel flywheelPID;
  flywheelPID.gearRatio = 5;

  double error = errorMargin + 1, integral = 0, derivetive = 0; 
  double sensorVal = 0;

  int sign = 0; 

  double prevError = 0, prevTime = 0, dt = 0; 
  
  double output = 0;
  double prevOutput = 0;
  
  while(1) {

    std::cout << flywheelPID.getVelocity() << std::endl;

    // updates sensor val every run
    sensorVal = flywheelPID.getVelocity();

    // recalculates error with new sensor val
    error = Velocity - sensorVal; 

    // updates prev error 
    prevError = error; 

   // updates the intergral variable 
    integral += error; 

    // calculates dt, the amount of time 
    // that has passed 
    dt = (Timer.time() - prevTime) / 1000;

    // figures out how close the robot is to the
    // target position. as the robot get closer 
    // derivetive gets smaller
    derivetive = (error - prevError) / dt;

    // limits integral, if it is outside a 
    // given range integral will be set to 0
    if (fabs(integral) > integralBound){
      integral = 0; 
    }


    // calculates output using all terms, and constants 
    output = (error * kp) + (integral * ki) + (derivetive * kd); 

   // finds wether the output is positive or negative 
    // one side is set to the absoulte value because 
    // would be always positive otherwise 
    sign = fabs(output) / output;

    if(fabs(output) > maxVoltage)
    output = maxVoltage * sign;

    if(fabs(output - prevOutput) > accel){
      output = prevOutput + (accel * sign);
    }

    flywheelPID.setVoltage(output);

    prevOutput = output;

    // udates prev time
    prevTime = Timer.time();

    // allows for values to update 
    wait(15, msec);
  } 

  // check to see if method has executed 
  // debugging 
  std::cout << "done ;)" << std::endl;
}