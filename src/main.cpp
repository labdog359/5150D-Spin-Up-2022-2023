#include "../include/Competition/autonomous.h"
#include "../include/Competition/driverOp.h"
#include "../include/MotionControl/PID.h"
#include "../include/Utils/selector.h"

#include "vex.h"

competition Competition;

using namespace vex;

void selectorClickCheck() {
  // checks if robot is in driver or autonomous
  // only runs when robot is not
  while (!Competition.isEnabled()) {

    // checks all 5 buttons wether the've been hit
    // and if they are to select them to make them green
    // and sets up an integer to run in case switch;
    for (int i = 1; i < 5; i++) {

      // checks if the button at index i in array autonButtons has
      // has been clciked on the brain screen
      if (autonButtons[i].isClicked()) {

        // if it has been clicked set the old one black
        autonButtons[autonToRun].buttonColor = vex::black;

        // if it has been clicked set the button to green
        autonButtons[i].buttonColor = vex::green;

        // set this switch case variable to index i
        autonToRun = i;
      }
    }

    this_thread::sleep_for(1);
  }
}

void selectorRender() {
  while (!Competition.isEnabled()) {
    for (int i = 1; i < 5; i++) {
      // finds the index of array autonButtons at index i
      // and displays it
      autonButtons[i].render();
    }

    this_thread::sleep_for(1);
  }
}

int main() {

  lTracking.resetPosition();
  rTracking.resetPosition();
  
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(Autonomous::autonomous);

  Competition.drivercontrol(DriverOp::usercontrol);

  // clears the scren before the autonomous selector
  // is displayed
  Brain.Screen.clearScreen(vex::black);

  Autonomous::pre_auton();

  // gotta fix this
  thread render = thread(&selectorRender);
  thread click = thread(&selectorClickCheck);

  // this while loop starts to display
  // an autonomous selector to the screen
  while (true) {

    // prevents main thread from taking all resources
    this_thread::sleep_for(1);
  }
}