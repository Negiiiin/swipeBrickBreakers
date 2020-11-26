#ifndef __BRICK__
#define __BRICK__

#include "../src/rsdl.hpp"
#include "myString.hpp"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include "Database.hpp"
//#include "textInput.hpp"

#define FONT_FREESANS "example/assets/OpenSans.ttf"
#define BRICKWIDTH 114
#define BRICKHEIGHT 60

class Brick
{
public:
	Brick(int _x, int _y, int _resistance);
	int returnx(){return x;}
	int returny(){return y;}
	int returnResistance(){return resistance;}
	int returnResistancE(){return resistance-1;}
private:
	int x;
	int y;
	int resistance;
	int brickWidth;
	int brickHeight;
	int score;
};

#endif