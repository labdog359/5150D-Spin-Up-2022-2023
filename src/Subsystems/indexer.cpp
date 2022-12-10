#include "../include/Subsystems/indexer.h"

void Indexer::setVoltage(double voltage) {
  index_Roller.spin(fwd, fabs(voltage), volt);
}

void Indexer::shoot(double shots) {
  if (shots < 1) {
  } else {
    for (int i = 1; i <= shots; i++) {
      pistonIndex.set(!pistonIndex.value());
      wait(200, msec);
      pistonIndex.set(!pistonIndex.value());
      wait(2, sec);
    }
  }
}

void Indexer::indexTrigger() {
  while (1) {
    if (Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing()) {
      pistonIndex.set(!pistonIndex.value());
      wait(200, msec);
      pistonIndex.set(!pistonIndex.value());
    }

    this_thread::sleep_for(25);
  }
}