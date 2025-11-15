#pragma once
#include "raylib.h"
#include "WavelengthToRGB.hpp"

class PhotonSource {
  private:
    float waveLength;
    float radius;
    Color CalcColour() const {
      int red_part;
      int green_part;
      int blue_part;
      WavelengthToRGB converter;
      converter.Convert(waveLength, 1.0, 255);
      red_part = converter.GetRed();
      green_part = converter.GetGreen();
      blue_part = converter.GetBlue();
      return {static_cast<unsigned char>(red_part),static_cast<unsigned char>(green_part),static_cast<unsigned char>(blue_part),255};
    }

  public:
    Vector2 centerPos;
    WaveSource(float wl, Vector2 CenterPos){
      waveLength = wl;
      centerPos = CenterPos;
    }
    void Draw() const {
      DrawCircle(centerPos.x, centerPos.y, radius, CalcColour());
    }
    void Update(){
      //here we can generate the rays when we need to generate them (every time period of rays) and then we also update the position of all of the member rays on the 
    }
};
