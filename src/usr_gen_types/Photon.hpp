#pragma once
#include "../wave_angle_library/src/AngleGen.hpp"
#include "PhotonSource.hpp"
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include "Slit.hpp"

class Photon {
  private:
    Vector2 Velocity;
    int Wavelength;
    Color color;
    bool passed;
    std::vector<Slit> slits;
    Vector2 Vector2Scale(Vector2 vec, int scale){
      Vector2 buf;
      buf.x = vec.x * scale;
      buf.y = vec.y * scale;
      return buf;
    }
    
  public:
    Vector2 Pos;
    PhotonSource *ParentSource;
    float DistanceTravelled;
    Photon(Vector2 startPos, Vector2 startVelocity, int wavelength, Color c, PhotonSource *p){
      Pos = startPos;
      Velocity = startVelocity;
      Wavelength = wavelength;
      color = c;
      ParentSource = p;
      passed = false;
    }
    void Update(float dt){
      Vector2 dd = Vector2Scale(Velocity, dt);
      Pos = Vector2Add(Pos, dd);
      DistanceTravelled += Vector2Length(dd);
    }

    //draw logic
    void Draw() const {
      //lets draw the photons as smaller circles. Give them a colour and draw their "tail" 
    }

    Slit ClosestSlit(){
      float minDist = 999999999f;
      Slit smallest;
      for (auto s : slits){
        float midPointX = (s.slitRep.p1.x + s.slitRep.p2.x) / 2;
        float midPointY = (s.slitRep.p1.y + s.slitRep.p2.y) / 2;
        float dist = Vector2Distance(Pos, {midPointX, midPointY});
        if (minDist > dist) {
            minDist = dist;
            smallest = s;
           }
      }
      return smallest;
    }

    void UpdateVelocity(){
      //check if it has passed the closest slit
      Vector2 closestSlit = ClosestSlit();
      if (closestSlit.CheckIfPassed(this) && !passed){
        float angle = generate_angle();
        Velocity = Vector2Rotate(Velocity, angle);
        passed = true;
       }
    }
};
