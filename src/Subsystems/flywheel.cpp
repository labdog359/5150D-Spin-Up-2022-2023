#include "../include/Subsystems/flywheel.h" 

void Flywheel::setVoltage(double volts) {
  flywheel1.spin(fwd, volts, voltageUnits::volt);
  flywheel2.spin(fwd, volts, voltageUnits::volt);
}

void Flywheel::setVelocityPct(double percent){
  flywheel1.setVelocity(percent, pct);
  flywheel2.setVelocity(percent, pct);
}

double Flywheel::getVelocity() {
  return ((flywheel1.velocity(rpm) + flywheel2.velocity(rpm)) / 2) * gearRatio;
}

void Flywheel::stop(vex::brakeType typeBrake) {
  setVoltage(0);
  
  flywheel1.setBrake(typeBrake);
  flywheel2.setBrake(typeBrake);
}

void Flywheel::velocitySet(double Velocity) {

  flywheel1.spin(fwd, Velocity/gearRatio, rpm);
  flywheel2.spin(fwd, Velocity/gearRatio, rpm);

}

