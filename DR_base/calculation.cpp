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



float calculateV1_j( float vx_j, float vy_j, float omega_j, float r) {
  return ( vx_j * 0.7 / r + vy_j * 0.7 / r + omega_j );
}

float calculateV2_j( float vx_j, float vy_j, float omega_j, float r) {
  return ( vx_j * 0.7 / r + vy_j * (-0.7) / r + omega_j );
}

float calculateV3_j( float vx_j, float vy_j, float omega_j, float r) {
  return ( vx_j * (-0.7) / r + vy_j * (-0.7) / r + omega_j );
}

float calculateV4_j( float vx_j, float vy_j, float omega_j, float r) {
  return ( vx_j * (-0.7) / r + vy_j * 0.7 / r + omega_j );
}
