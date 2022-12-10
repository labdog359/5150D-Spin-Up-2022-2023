/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#pragma once

#include <math.h>
#include <cmath>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ALLOWS FOR PRINTING TO CONSOLE
#include <iostream>

// allows for easier use of arrays
#include <vector>

// ALLOWS FOR MORE POWER!!!
#include <vex_thread.h>

// ALLOWS FOR CONTROLLED THREADS
#include <mutex>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

static bool isIndexing = false;
static bool isIntake = false;
static bool isRed = false;
static bool isRolling = false; 
static vex::color rollerColor;

static double startX, startY; 


#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)