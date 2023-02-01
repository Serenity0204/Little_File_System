#ifndef ENGINE_H
#define ENGINE_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"
#include "../input_box/input_box.h"
#include "../button/buttons.h"
#include "../header/header.h"
#include "../../app/command_line/command_line.h"
using namespace std;


class Engine 
{
private:
    // sfml private members here
    sf::RenderWindow _window;

    // system setup here
    Buttons _buttons;
    Header _header;
    CommandLine _cmd;
    // private member variables here



    // private helper functions here
    // init
    void _init();
    // update
    void _update_buttons_event(sf::Event& event);

public:
    // constructors and destructors
    Engine();
    ~Engine();
    // game processing
    void input();
    void run();
    void display();
};




#endif