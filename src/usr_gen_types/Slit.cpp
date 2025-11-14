/*Kerem Yaprak
 *Physics Photon Double slit simulation
 *11/11/2025
 */
#include "Slit.hpp"
#include "Ray.hpp"
#include "raymath.h"
#include <algorithm>

float Slit::MaxDist(LightRay *ray){
  float Dist1 = Vector2Distance(ray->ParentSource->centerPos, Pos1);
  float Dist2 = Vector2Distance(ray->ParentSource->centerPos, Pos2);
  return std::max(Dist1,Dist2);
}
bool Slit::CheckIfPassed(LightRay *ray){
  return ray->DistanceTravelled >= MaxDist(ray);
}
