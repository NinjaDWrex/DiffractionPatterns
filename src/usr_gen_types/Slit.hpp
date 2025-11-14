/*Kerem Yaprak
 *Photon based double slit simulation
 *11/11/2025
 */
#pragma once
#include "raylib.h"

class LightRay;

class Slit{
  private:
    float MaxDist(LightRay *ray);
  public:
    Vector2 Pos1;
    Vector2 Pos2;
    bool CheckIfPassed(LightRay *ray);
};
