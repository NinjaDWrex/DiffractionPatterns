/*Kerem Yaprak
 *Physics Photon Double slit simulation
 *11/11/2025
 */
#include "Slit.hpp"
#include "Ray.hpp"
#include "raymath.h"
#include "raylibAddons.hpp"
#include <algorithm>

float Slit::MaxDist(LightRay *ray){
  float Dist1 = Vector2Distance(ray->ParentSource->centerPos, Pos1);
  float Dist2 = Vector2Distance(ray->ParentSource->centerPos, Pos2);
  return std::max(Dist1,Dist2);
}

/* checking for wether the ray has passed the slit
 * to do this, we must draw a straight line from the photon to the photon source
 * then we can check if the slit and this line intersect
 */
bool Slit::CheckIfPassed(LightRay *ray){
  // basic easy check
  if (ray->DistanceTravelled >= MaxDist(ray)){
    return true;
  }
  // lets now make a line for between the photon to the wave source
  Line photonToSource = Line()
}
