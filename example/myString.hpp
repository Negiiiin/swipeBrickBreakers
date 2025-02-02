#ifndef __MY_STRING__
#define __MY_STRING__
#include<string>
#include"../src/rsdl.hpp"

using namespace std;

#define MAX_STRING_LENGTH 10
#define FONT_FREESANS "example/assets/OpenSans.ttf"

class MyString
{
  public:
    MyString(int _x, int _y, int _fontSize);
    string textToDisplay();
    void eraseLastChar();
    void addChar(char c);
    void drawString(Window* win);
  private:
    string inputString;
    int fontSize;
    int x;
    int y;
};
#endif
