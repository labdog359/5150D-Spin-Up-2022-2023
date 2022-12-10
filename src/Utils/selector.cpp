#include "../include/Utils/selector.h"


int autonToRun = 0;

void screen1(){
  Brain.Screen.setFillColor(196);
    Brain.Screen.drawRectangle(0, 0, 480, 272);
    Brain.Screen.setPenWidth(6);
    Brain.Screen.setPenColor(38);
    Brain.Screen.drawRectangle(12, 12, 456, 208);

}

Button autonButtons[] = {
    Button(0, 0, 0, 0, "", vex::orange, vex::white),
    Button(25, 30, 180, 80, "roller left red", vex::orange, vex::white),
    Button(275, 30, 180, 80, "roller right red", vex::orange, vex::white),
    Button(25, 162, 180, 80, "roller left blue", vex::orange, vex::white),
    Button(275, 162, 180, 80, "roller right blue", vex::orange, vex::white)};


void Button::render() {
  Brain.Screen.drawRectangle(x, y, width, height, buttonColor);

  Brain.Screen.printAt(x + ((width - (text.size() * 10)) / 2), y + (height / 2), false,
                       text.c_str());
}

bool Button::isClicked() {
  if (Brain.Screen.pressing() && Brain.Screen.xPosition() >= x &&
      Brain.Screen.xPosition() <= x + width && Brain.Screen.yPosition() >= y &&
      Brain.Screen.yPosition() <= y + width) {
    return true;
  }
  return false;
}
