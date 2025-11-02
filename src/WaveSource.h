#include "raylib.h"
#include "WavelengthToRGB.h"
class WaveSource {
  private:
    float waveLength;
    Vector2 CenterPos;
    float radius;
    // need an output for where the rays are coming out of.
    Color CalcColour()const{
      int red_part;
      int green_part;
      int blue_part;
      WavelengthToRGB converter;
      converter.Convert(waveLength, 1.0, 255);
      red_part = converter.GetRed();
      green_part = converter.GetGreen();
      blue_part = converter.GetBlue();
      return {red_part,green_part,blue_part,255};
    }
  public:
    WaveSource(float wl, Vector2 CenterPos){
      waveLength = wl;      
    }
    void Draw() const {
      DrawCircle(CenterPos.x, CenterPos.y, radius, CalcColour());
    }
};
