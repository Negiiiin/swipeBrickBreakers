#include "../src/rsdl.hpp"
#include "myString.hpp"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include "Brick.hpp"

Brick :: Brick(int _x, int _y, int _resistance)
{
	x = _x;
	y = _y;
	resistance = _resistance;
}
