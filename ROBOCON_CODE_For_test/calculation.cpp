#include "calculation.h"

float calculateV1( float vx, float vy, float omega, float r) {
  return ( vx * 0.7 / r + vy * 0.7 / r + omega );
}

float calculateV2( float vx, float vy, float omega, float r) {
  return ( vx * 0.7 / r + vy * (-0.7) / r + omega );
}

float calculateV3( float vx, float vy, float omega, float r) {
  return ( vx * (-0.7) / r + vy * (-0.7) / r + omega );
}

float calculateV4( float vx, float vy, float omega, float r) {
  return ( vx * (-0.7) / r + vy * 0.7 / r + omega );
}
