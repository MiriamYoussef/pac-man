#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
using namespace std;
using namespace sf;

#include "Board.h"
#include "Player.h"
#include "Ghosts.h"
#include "Sounds.h"
#include "Graph.h"
#include "sstream"

class Game
{
private:
    const int rows = 34;
    const int cols = 28;
    int arr[34][28];
    int pacmanlives;
    RectangleShape life1, life2, life3;
    Texture transparent, life, blue;
    RenderWindow window;
    Text scoretext, highscoretext, livestext, starttext, key, endtext, scorenumbers, highscorenumbers;
    Font font;
    int score;
    int highscore;
    bool keypressed;
    Time sec, milsec;
    Time elapsed;
    Clock clock;
    Player player;
    Ghost Pinky;
    Ghost Inky;
    Ghost Clyde;
    Ghost Blinky;
    Board board;
    Graph graph;
    Sounds sounds;
    void LivesConstructor();
    void Display_lives();
    void Display_score();
    void pelleteaten();
    void pacmaneaten();
    void computeLives();
    bool frightmode();
    void checkfrightmode();
    void sound();

public:
    Game();
    void Start();
    void End();
   
};