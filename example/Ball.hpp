#ifndef __BALL__
#define __BALL__

#include "../src/rsdl.hpp"
#include "myString.hpp"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include "Database.hpp"

class Ball{
private:
	int ballX;
	int ballY;
	int vx;
	int vy;
public:
	Ball();
	void move();
	void drawBall();
	
};

#endif