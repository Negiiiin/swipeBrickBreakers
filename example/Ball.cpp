#include "../src/rsdl.hpp"
#include "myString.hpp"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include "Ball.hpp"

Ball :: Ball()

void Ball :: move(int x, int y, int* vx, int* vy)
{
  int vx;
  int vy;
  vx = 10;
  vy = 20;
  int x = 200;
  int y = 200;
  drawNewGameBG();
  win->draw_png(IMG_BALL, x, y, 30, 30);
  win->update_screen();
  win->update_screen();
  while(true)
  {
    win->clear();
    x += - vx * 2;
    y += - vy * 2;
    if(y > 640)
    { 
      win->clear();
      win->update_screen();
      drawNewGameBG();
      win->update_screen();
      win->draw_png(IMG_BALL, x, 670, 30, 30);
      win->update_screen();
      break;
    }
    if(x < 30 || x > 570 || y <170 || y > 640)
    {
      if (x < 30)
      {
        win->clear();
        win->update_screen();
        drawNewGameBG();
        win->update_screen();
        win->draw_png(IMG_BALL, 0, y, 30, 30);
        win->update_screen();
        x = 2 * 30 -x;
        vx = -vx;
      }
      if (x >= 570)
      {
        win->clear();
        win->update_screen();
        drawNewGameBG();
        win->update_screen();
        win->draw_png(IMG_BALL, 570, y, 30, 30);
        win->update_screen();
        x = 2 * 570 - x;
        vx = -vx;
      }
      if (y < 170)
      {
        win->clear();
        win->update_screen();
        drawNewGameBG();
        win->update_screen();
        win->draw_png(IMG_BALL, x, 170, 30, 30);
        win->update_screen();
        y = 2 * 170 -y;
        vy = -vy;
      }
    }
    Delay(300);
    win->clear();
    win->update_screen();
    drawNewGameBG();
    win->update_screen();
    win->draw_png(IMG_BALL, x, y, 30, 30);
    win->update_screen();
  }
}