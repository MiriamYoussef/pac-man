
#ifndef Game_hpp
#define Game_hpp
#include "Board.hpp"
#include "Player.hpp"
#include "Ghosts.hpp"
#include "sstream"

class Game
{
private:
    const int rows=34;
    const int cols=28;
    int arr[34][28];
    int pacmanlives;
    RectangleShape life1,life2,life3;
    Texture transparent, life;
    RenderWindow window;
    Text scoretext, highscoretext, livestext, starttext, endtext, scorenumbers, highscorenumbers;
    Font font;
    int score;
    int highscore;
    void LivesConstructor();
    void Display_lives();
    void Display_score();
    bool pellet(int, int);
    bool powerpellet(int, int);
    bool checkifEaten(int, int, int, int);
    void computeLives();
    void frightmode();
 
public:
    Game();
    void Start();
    void End();
};
#endif 
