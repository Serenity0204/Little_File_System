#ifndef SYSTEM_H
#define SYSTEM_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;



enum FONTS
{
    // ADD MORE FONTS HERE
    ARIAL = 0,
};


// Action code for buttons go here
enum ACTION_CODE
{
    INVALID = -1,
    // add more action code for button here
    TEST = 0,
};

// back->0
// mkdir -> 1 + 1 not space == 2
// cd -> 1 + 1 not space == 2
// ls->0 
// touch -> 1 + 1 not space == 2
// rm->0
enum PARSE_KEY
{
    BACK=0,
    MKDIR=1,
    CD=2,
    TOUCH=3,
    LS = 4,
    RM=5,
};

// add more enum here



// windows
// ADD WINDOWS CONFIG VARIABLE HERE
const int WINDOW_HEIGHT = 650;
const int WINDOW_WIDTH = 1200;
const int INPUT_BOX_FONT_SIZE = 24;
const int CMD_FONT_SIZE = 20;
const int HEADER_FONT_SIZE = 35;
const int CHAR_LIMIT = 150;
const int CMD_CHAR_LIMIT = 50;
const int CHAR_DIVIDE = 12;



// system variable config
// ADD SYSTEM  VARIABLE HERE
const sf::Vector2f INPUT_BOX_SIZE = sf::Vector2f(700, 120);
const sf::Vector2f INPUT_BOX_POS = sf::Vector2f(430, 500);
const sf::Vector2f HEADER_SIZE = sf::Vector2f(300, 50);
const sf::Vector2f HEADER_POS = sf::Vector2f(430, 200);

const sf::Vector2f COMMAND_LINE_SIZE = sf::Vector2f(550, 50);
const sf::Vector2f COMMAND_LINE_POS = sf::Vector2f(600, 550);




#endif