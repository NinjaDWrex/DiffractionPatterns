/*Kerem Yaprak
 *Photon based double slit simulation
 *11/11/2025
 */
#pragma once
#include "raylib.h"
#include "line.hpp"

class LightRay;
class Slit{
  private:
    float MaxDist(Photon *photon);
    Line slitRep;
  public:
    bool CheckIfPassed(Photon *photon);
};
