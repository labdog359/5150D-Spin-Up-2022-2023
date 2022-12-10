#include "vex.h"
#include "../include/Utils/conversions.h"

using namespace vex;

class Odometry { 
  private:

  inline static double sl, sr, ss;

  void static odomStartThreeEncoder();

  void static odomStartOneEncoder();

  inline static vex::rotation trackLeft = rotation(NULL);
  inline static vex::rotation trackRight = rotation(NULL);
  inline static vex::rotation trackSide = rotation(NULL);

  inline static vex::motor motorLeft = motor(NULL);
  inline static vex::motor motorRight = motor(NULL);

  public:

  void static odomBasic();

  void static odomOneEncoder(vex::motor left, vex::motor right, vex::rotation side);

  void static odomBasicStart();

  void threeEncoderOdom(vex::rotation left, vex::rotation right, vex::rotation side);

  inline static Conversions odomConversions; 

  inline static double x, y, theta;
  inline static double xOffset, yOffset; 
  
  Odometry(double spaceRight, double spaceLeft, double spaceSide){
    sr = spaceRight;
    sl = spaceLeft;
    ss = spaceSide;
  }

};
