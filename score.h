#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
using namespace std;
using namespace sf;
#include"Board.h"

class score
{
private:
    Text Score;
    Font font;
public:
    score(string fonttxt);
    int pacmanscore;

};

