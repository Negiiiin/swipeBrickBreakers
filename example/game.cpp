#include "../src/rsdl.hpp"
#include "myString.hpp"
#include "game.hpp"
#include <string.h>

Game::Game(): inputString(100, 100, 30)
{
  win = new Window(WINDOW_WIDTH, WINDOW_HEIGTH, "Text Input");
  enterPressed = false;
}

void Game::drawMenu()
{
  win->clear();
  win->draw_bg(IMG_WHITE, 0, 0);
  win->fill_rect(100, 100, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
  win->fill_rect(100, 300, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
  win->fill_rect(100, 500, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
  win->fill_rect(100, 700, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
  win->show_text("New Game", 190, 125, BLACK, FONT_FREESANS , 40);
  win->show_text("Scoreboard", 185, 325, BLACK, FONT_FREESANS , 40);
  win->show_text("Edit Username", 155, 525, BLACK, FONT_FREESANS , 40);
  win->show_text("Exit", 260, 725, BLACK, FONT_FREESANS , 40);
}

void Game::ProcessMenu()
{
  char pressedChar;
  int x = 90;
  int y = 90;
  drawMenu();
  win->draw_rect(x, y, 420, 140, YELLOW);
  win->update_screen();
  while(true)
  {
    lastEvent = win->pollForEvent();
    Delay(10);
    win->draw_rect(x, y, 420, 140, YELLOW);
    if(lastEvent.type() == KEY_PRESS)
    {
      pressedChar = lastEvent.pressedKey();
      if(pressedChar == UP && y != 90)
      {
        y -= 200;
        win->clear();
        drawMenu();
        win->draw_rect(x, y, 420, 140, YELLOW);
        win->update_screen();
      }
      if(pressedChar == DOWN && y != 690)
      {
        y+= 200;
        win->clear();
        drawMenu();
        win->draw_rect(x, y, 420, 140, YELLOW);
        win->update_screen();
      }
      if(pressedChar == RETURN && y == 690)break;
      if(pressedChar == RETURN && y == 290)
      {
        showScoreboard();
        win->draw_rect(x, y, 420, 140, YELLOW);
        win->clear();
        drawMenu();
        win->draw_rect(x, y, 420, 140, YELLOW);
        win->update_screen();
      }
      if(pressedChar == RETURN && y == 90)
      {
        showNewGame();
        win->draw_rect(x, y, 420, 140, YELLOW);
        win->clear();
        drawMenu();
        win->draw_rect(x, y, 420, 140, YELLOW);
        win->update_screen();
        //*******************************************
      }
      if(pressedChar == RETURN && y == 490)
      {
        drawEnterUsername();
        win->draw_rect(x, y, 420, 140, YELLOW);
        win->clear();
        drawMenu();
        win->draw_rect(x, y, 420, 140, YELLOW);
        win->update_screen();
      }
    }
  }
}

void Game::printHighScores()
{
  for (int i = 0; i < databases.size() || i < 5; ++i)
  {
      win->show_text(databases[i].returnUsername(), 150, 730, BLACK, FONT_FREESANS , 40); //********************
      win->show_text(databases[i].returnUsername(), 150, 730, BLACK, FONT_FREESANS , 40); //********************
  }
}

void Game::showScoreboard()
{
  win->clear();
  win->draw_bg(IMG_WHITE, 0, 0);
  if(databases.size() == 0)
  {
    win->fill_rect(100, 100, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
    win->fill_rect(100, 500, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
    win->show_text("No Records", 190, 125, BLACK, FONT_FREESANS , 40);
    win->show_text("Menu", 250, 530, BLACK, FONT_FREESANS , 40);
    win->draw_rect(90, 490, 420, 140, YELLOW);
    win->update_screen();
    char pressedChar;
    while(true)
    {
      lastEvent = win->pollForEvent();
      Delay(10);
      if(lastEvent.type() == KEY_PRESS){
        pressedChar = lastEvent.pressedKey();
        if(pressedChar == RETURN)
        {
          drawMenu();
          win->update_screen();
          return;
        }
      }
    }
  }
  else
  {
    win->fill_rect(60, 60, 480, 530, SILVER);
    win->fill_rect(100, 700, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
    win->show_text("Menu", 250, 730, BLACK, FONT_FREESANS , 40);
    win->draw_rect(90, 690, 420, 140, YELLOW);
    win->update_screen();
    char pressedChar;
    while(true)
    {
      lastEvent = win->pollForEvent();
      Delay(10);
      if(lastEvent.type() == KEY_PRESS){
        pressedChar = lastEvent.pressedKey();
        if(pressedChar == RETURN)
        {
          drawMenu();
          win->update_screen();
        }
      }
    }
  }
}

void Game :: drawBricks()
{
  win->clear();
  win->draw_bg(IMG_WHITE, 0, 0);
  win->draw_line(5, 200, 595, 200, BLACK);
  win->draw_line(5, 700, 595, 700, BLACK);
  for (int i = 0; i < numOfBricks; ++i)
  {
    cout << numOfBricks << "\t" << i << "\n";
    win->fill_rect(bricks[i].returnx(), bricks[i].returny(), BRICKWIDTH, BRICKHEIGHT, CYAN);
    win->update_screen();
    Delay(10);
  }
}

void Game :: drawNewGameBG()
{
  bool checkScore = true;
  win->clear();
  win->draw_bg(IMG_WHITE, 0, 0);
  win->draw_line(5, 200, 595, 200, BLACK);
  win->draw_line(5, 700, 595, 700, BLACK);
  drawBricks();
  win->show_text("Name: ", 40, 40, BLACK, FONT_FREESANS, 30);
  win->show_text(currentUsername, 150, 40, BLACK, FONT_FREESANS, 30);
  win->show_text("Score: ", 40, 65, BLACK, FONT_FREESANS, 30);
  win->update_screen();
}

bool Game :: checkBrick(int x, int y)
{
  for (int i = 0; i < bricks.size(); ++i)
  {
    if((x >= bricks[i].returnx() && x <= (bricks[i].returnx() + BRICKWIDTH))&&(y >= bricks[i].returny() && y <= (bricks[i].returny() + BRICKHEIGHT)))
      {
        win->draw_png(IMG_BALL, x, 200, 30, 30);
        win->update_screen();
        bricks[i].returnResistance() == bricks[i].returnResistancE();
        if(bricks[i].returnResistance() == 0)
        {
          bricks.erase(bricks.begin()+i);
          return true;
        }
      }
    return false;
  }
}



void Game :: showNewGame()
{
  if(currentUsername == "")drawEnterUsername();
  win->clear();
  float vx;
  float vy;
  vx = 10;
  vy = 20;
  int x = 300;
  int y = 640;
  drawNewGameBG();
  win->draw_png(IMG_BALL, x, y, 30, 30);
  win->update_screen();
  float mouse_x_location;
  float mouse_y_location;
  while(true)
  {
    bool checkMouse = false;
    bool checkKey = false;
    lastEvent = win->pollForEvent();
    Delay(10);
    if(lastEvent.type() == LCLICK)
    {
      while(true)
      {
        lastEvent = win->pollForEvent();
        if(lastEvent.type() == LRELEASE)
          {
            break;
          }
        if(!(lastEvent.mouseX() == -1 || lastEvent.mouseY() == -1))
        {
          mouse_x_location = lastEvent.mouseX();
          mouse_y_location = lastEvent.mouseY();
        }
        float angle = atan (mouse_y_location / (mouse_x_location)) * 180 / PI;
        cout << mouse_x_location << endl;
        win->clear();
        drawNewGameBG();
        win->update_screen();
        Delay(10);
        win->draw_png(IMG_ARROW, 300, 655, 35, 20, angle);
        win->draw_png(IMG_BALL, x, 670, 35, 35);
        win->update_screen();
        checkMouse = true;
      }
    }
    float angleKey = 90.0;
    if (lastEvent.type() == KEY_PRESS)
    {
      while(true)
      {
        lastEvent = win->pollForEvent();
        if(lastEvent.pressedKey() == RETURN)
        {
          break;
        }
        char pressedChar;
        pressedChar = lastEvent.pressedKey();
        if(pressedChar == RIGHT && angleKey != 179)angleKey++;
        if(pressedChar == LEFT && angleKey != 1)angleKey--;
        win->clear();
        drawNewGameBG();
        win->update_screen();
        Delay(10);
        win->draw_png(IMG_ARROW, 300, 655, 35, 20, angleKey);
        win->draw_png(IMG_BALL, x, 670, 35, 35);
        win->update_screen();
        checkKey = true;
      }
    }
    if(checkMouse)
    {
      vx = mouse_x_location / sqrt((mouse_y_location)*(mouse_y_location) + (mouse_x_location)*(mouse_x_location));
      vy = mouse_y_location / sqrt((mouse_y_location)*(mouse_y_location) + (mouse_x_location)*(mouse_x_location));
      break;
    }
    if(checkKey)
    {
      vx = cos(angleKey*PI/180);
      vy = sin(angleKey*PI/180);
      break;
    }
  }
  while(true)
  {
    win->clear();
    x += - vx * 30;
    y += - vy * 30;
    if(y > 670)
    { 
      y = 670;
      win->clear();
      win->update_screen();
      drawNewGameBG();
      win->update_screen();
      win->draw_png(IMG_BALL, x, 670, 30, 30);
      win->update_screen();
      break;
    }
    if(x < 30 || x > 570 || y <200)
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
      if (y < 200)
      {
        win->clear();
        win->update_screen();
        drawNewGameBG();
        win->update_screen();
        win->draw_png(IMG_BALL, x, 200, 30, 30);
        win->update_screen();
        y = 2 * 200 -y;
        vy = -vy;
      }
    }
    Delay(200);
    win->clear();
    win->update_screen();
    drawNewGameBG();
    win->update_screen();
    win->draw_png(IMG_BALL, x, y, 30, 30);
    win->update_screen();
    if(checkBrick(x, y))
    {
      win->clear();
      drawNewGameBG();
      drawBricks();
      win->update_screen();
      break;
    }
  }
}


void Game::drawShowingString(string input, int x, int y)
{
  win->clear();
  win->draw_bg(IMG_WHITE, 0, 0);
  win->fill_rect(100, 500, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
  win->fill_rect(100, 700, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
  win->show_text("Enter Username", 90, 155, BLACK, FONT_FREESANS , 30);
  win->show_text("Save", 260, 530, BLACK, FONT_FREESANS , 30);
  win->show_text("Cancel", 240, 730, BLACK, FONT_FREESANS , 30);
  win->draw_rect(x, y, 420, 140, YELLOW);
  win->show_text(input, 200, 200, BLACK, FONT_FREESANS, 20);
  win->update_screen();
}

void Game :: drawEnterUsername()
{
  win->clear();
  win->draw_bg(IMG_WHITE, 0, 0);
  win->fill_rect(100, 500, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
  win->fill_rect(100, 700, TEXT_INPUT_WIDTH, TEXT_INPUT_HEIGHT, CYAN);
  win->show_text("Save", 260, 530, BLACK, FONT_FREESANS , 30);
  win->show_text("Cancel", 240, 730, BLACK, FONT_FREESANS , 30);
  win->show_text("Enter Username", 90, 155, BLACK, FONT_FREESANS , 30);
  win->update_screen();
  string name = getString();
  win->update_screen();
}

string Game :: getString()
{
  int x = 90;
  int y = 490;
  string result = "";
  char pressedChar;
  while(true)
    {
      lastEvent = win->pollForEvent();
      Delay(10);
      if(lastEvent.type() == KEY_PRESS){
        pressedChar = lastEvent.pressedKey();
        if(pressedChar == RETURN)
        {
          if(y == 690)
          {
            currentUsername = "";
            return "";
          }
          currentUsername = result;
          return result;
        }
        else if(pressedChar == DOWN && y == 490)
        {
          y += 200;
          drawShowingString(result, x, y);
        }
        else if(pressedChar == UP && y == 690)
        {
          y -= 200;
          drawShowingString(result, x, y);
        }
        else if(pressedChar == BACK_SPACE)
        {
          if(result.size() > 1)
            result.erase(result.size()-1);
          if(result.size() == 1)
            result == "";
          drawShowingString(result, x, y);
        }
        else
        {
          if(!(pressedChar == DOWN || pressedChar == UP))
          result.push_back(pressedChar);
          drawShowingString(result, x, y);
        }
      }
    }
}

