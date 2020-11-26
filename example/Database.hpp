#ifndef __DATABASE__
#define __DATABASE__

#include "../src/rsdl.hpp"
#include "myString.hpp"
#include "Brick.hpp"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#define FONT_FREESANS "example/assets/OpenSans.ttf"

using namespace std;

class Database{
public:
	string returnUsername(){return username;}
	int returnHighScore(){return highScore;}
	
private:
	string username;
	int highScore;
	vector<map <int, int> > brickCoordinates;
	
};

#endif