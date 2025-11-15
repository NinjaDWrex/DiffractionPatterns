#pragma once
#include "WaveSource.hpp"
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include "Slit.hpp"

class Photon {
  private:
    Vector2 Pos;
    Vector2 Velocity;
    int Wavelength;
    Color color;
    std::vector<Slit> slits;
    Vector2 Vector2Scale(Vector2 vec, int scale){
      Vector2 buf;
      buf.x = vec.x * scale;
      buf.y = vec.y * scale;
      return buf;
    }
    
  public:
    PhotonSource *ParentSource;
    float DistanceTravelled;
    Photon(Vector2 startPos, Vector2 startVelocity, int wavelength, Color c, WaveSource *p){
      Pos = startPos;
      Velocity = startVelocity;
      Wavelength = wavelength;
      color = c;
      ParentSource = p;
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
    void UpdateVelocity(){
      // we can change the value of v using
      /**v =*/
      /* to work out the change to velocity,
       * we need to find when the light ray has passed through the diffraction barrier (the slit)
       */
      /* we want to be able to make a random selection of positions that the wave can "split" into.
       * to do this, we can use a probability distribution linked to angles from the original path.
       * then based off of this, we can make a new ray with this angle.]
       */
    }
};
