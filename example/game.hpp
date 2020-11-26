#include "../src/rsdl.hpp"
#include "myString.hpp"
#include <cstdlib>
#include <float.h>
#include <vector>
#include <cmath>
#include <string>
#include "Database.hpp"
#include "Brick.hpp"
#define FONT_FREESANS "example/assets/OpenSans.ttf"

using namespace std;

#define PI 3.14159265

#define BRICKWIDTH 114
#define BRICKHEIGHT 60

#define WINDOW_WIDTH 600    
#define WINDOW_HEIGTH 900
#define WINDOW_TITLE "RSDL Tutorial"

#define BACK_SPACE 8
#define RETURN 13
#define TICK_DURATION 10
#define UP 82
#define DOWN 81
#define RIGHT 79
#define LEFT 80

#define IMG_SQUARE "example/assets/square.png"
#define IMG_BACKGROUND "example/assets/background.jpeg"
#define IMG_WHITE "example/assets/white.jpeg"
#define IMG_BALL "example/assets/ball.png"
#define IMG_ARROW "example/assets/arrow.jpg"

#define TEXT_INPUT_X 100
#define TEXT_INPUT_Y 100
#define TEXT_INPUT_WIDTH 400
#define TEXT_INPUT_HEIGHT 120

class Game
{
  private:
    Window* win;
    string currentUsername;
    Event lastEvent;
    MyString inputString;
    bool enterPressed;
    void getAndProcessInput();
    void processLastEvent();
    void showScoreboard();
    vector<Database> databases;
    vector<Brick> bricks;
    int score;
    int numOfBricks;
  public:
    Window* returnWindow(){return win;}
    void drawEnterUsername();
    void showNewGame();
    Game();
    void printHighScores();
    void display();
    void drawMenu();
    void ProcessMenu();
    string getString();
    void drawShowingString(string input, int x, int y);
    void drawNewGameBG();
    bool checkBrick(int x, int y);
    void drawBricks();
};
