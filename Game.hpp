
#ifndef Game_hpp
#define Game_hpp
#include "Board.h"
#include "Player.h"
#include "Ghosts.h"
#include "sstream"

class Game
{
private:
    const int rows = 34;
    const int cols = 28;
    int arr[34][28];
    int pacmanlives;
    RectangleShape life1, life2, life3;
    Texture transparent, life;
    RenderWindow window;
    Text scoretext, highscoretext, livestext, starttext, endtext, scorenumbers, highscorenumbers;
    Font font;
    int score;
    int highscore;
    Player pacman;
    Board board;
    Ghost ghost;
    void LivesConstructor();
    void Display_lives();
    void Display_score();
    void pelleteaten(int arr[24][38]);
    void pacmaneaten(int arr[24][38]);
    void computeLives();
    bool frightmode();

public:
    Game();
    void Start();
    void End();
    
};
#endif 
