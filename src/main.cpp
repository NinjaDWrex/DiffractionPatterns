#include "raylib.h"
int main(){
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 450;
  const int PADDING = 10;
  const Color BACK_COLOR = {28,28,69,255};
  const char *INFO_TXT = "WOW YOU CAN DRAW A CIRCLE, NEXT LETS USE THIS AS AN AUDIO SOURCE!!";
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello world");
  SetTargetFPS(120);
  while (!WindowShouldClose()){
    //update stuff
    // update drawing
    BeginDrawing();
    DrawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, {255,0,0,255});
    DrawText(INFO_TXT, SCREEN_WIDTH/2 - (MeasureText(INFO_TXT,12)/2), (SCREEN_HEIGHT/2) + (20 + PADDING), 12, {255,255,255,255});
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
