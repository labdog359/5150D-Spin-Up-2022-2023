#include "../include/Subsystems/roller.h"

void Roller::setVoltage(double volts){
  index_Roller.spin(fwd, fabs(volts), voltageUnits::volt);
}

void Roller::control(){
  while(1){
    while(Controller1.ButtonL2.pressing()){
      setVoltage(12);
    }
    setVoltage(0);
  }
}

void Roller::autoRoller() {

  bool isRolling = false;

  if(isRed){
    rollerColor = vex::red;
  }
  else{
    rollerColor = vex::blue;
  }

  /*while(1){
    while(Optical.isNearObject() && Optical.color() != rollerColor && !isIndexing){
      Optical.setLight(ledState::on);
      Roller::setVoltage(12);
      isRolling = true;
    }
    if(isRolling){
      setVoltage(0);
      Optical.setLight(ledState::off);
      isRolling = false;
    }
  }*/
}