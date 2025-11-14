#ifndef CALCULATION_H
#define CALCULATION_H

#include "Arduino.h"
#include "calculation.h"

float calculateV1( float vx, float vy, float omega, float r);
float calculateV2( float vx, float vy, float omega, float r);
float calculateV3( float vx, float vy, float omega, float r);
float calculateV4( float vx, float vy, float omega, float r);


float calculateV1_j( float vx_j, float vy_j, float omega_j, float r);
float calculateV2_j( float vx_j, float vy_j, float omega_j, float r);
float calculateV3_j( float vx_j, float vy_j, float omega_j, float r);
float calculateV4_j( float vx_j, float vy_j, float omega_j, float r);

#endif
