#pragma once

#include "vex.h" 

using namespace vex;

extern int autonToRun; 

class Button {
public:
  int x, y, width, height;
  std::string text;
  vex::color buttonColor, textColor;

  Button(int x, int y, int width, int height, std::string text,
         vex::color buttonColor, vex::color textColor)
      : x(x), y(y), width(width), height(height), text(text),
        buttonColor{buttonColor}, textColor(textColor) {}

  void render();

  bool isClicked();
};

extern Button autonButtons[];

