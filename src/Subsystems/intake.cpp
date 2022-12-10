#include "../include/Subsystems/intake.h"

void IntakeControl::intakeTrigger() {
  while(1) {
    while(Controller1.ButtonL1.pressing() && !Controller1.ButtonR2.pressing()){
      intake.spin(fwd, 12, volt);
      isIndexing = true;
    }
    if(isIndexing){
    intake.spin(fwd, 0, volt);
    intake.setBrake(brake);  
    isIndexing = false;
    }
  }
}