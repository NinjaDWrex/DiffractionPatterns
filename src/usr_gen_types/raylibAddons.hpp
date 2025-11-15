#include "raylib.h"
struct Line {
  Vector2 p1;
  Vector2 p2;
  Line(Vector2 point1, Vector2 point2){
    p1 = point1;
    p2 = point2;
  }
};
