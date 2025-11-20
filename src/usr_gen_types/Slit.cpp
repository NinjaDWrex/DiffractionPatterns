/*Kerem Yaprak
 *Physics Photon Double slit simulation
 *11/11/2025
 */
#include "Slit.hpp"
#include "Ray.hpp"
#include "raymath.h"
#include "raylibAddons.hpp"
#include <algorithm>

bool Intersection(Line line1, Line line2) {
    // Helper function to calculate the determinant
    auto determinant = [](Vector2 p1, Vector2 p2) {
        return p1.x * p2.y - p2.x * p1.y;
    };

    Vector2 p1 = line1.p1;
    Vector2 q1 = line1.p2;
    Vector2 p2 = line2.p1;
    Vector2 q2 = line2.p2;

    // Calculate the determinant
    float d1 = determinant(q1 - p1, p2 - q2);
    if (d1 == 0.0) {
        return false; // Lines are parallel
    }

    float d2 = determinant(p1 - p2, q2 - p2);
    float t1 = d2 / d1;
    float d3 = determinant(q1 - p1, q2 - p2);
    float t2 = d3 / d1;

    // Check if the intersection point lies within both segments
    return (t1 >= 0.0 && t1 <= 1.0) && (t2 >= 0.0 && t2 <= 1.0);
}

float Slit::MaxDist(LightRay *photon){
  float Dist1 = Vector2Distance(photon->ParentSource->centerPos, Pos1);
  float Dist2 = Vector2Distance(phton->ParentSource->centerPos, Pos2);
  return std::max(Dist1,Dist2);
}

/* checking for wether the ray has passed the slit
 * to do this, we must draw a straight line from the photon to the photon source
 * then we can check if the slit and this line intersect
 */
bool Slit::CheckIfPassed(LightRay *photon){
  // basic easy check
  if (ray->DistanceTravelled >= MaxDist(photon)){
    return true;
  }
  if(Intersects(Line(photon->Pos, photon->ParentSource->centerPos)))
}
