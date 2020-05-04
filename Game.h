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
    Texture blue;
    Time sec;
    Time elapsed;
    Clock clock;
    Player player;
    Ghost Pinky;
    Ghost Inky;
    Ghost Clyde;
    Ghost Blinky;
    Board board;
    void LivesConstructor();
    void Display_lives();
    void Display_score();
    void pelleteaten();
    void pacmaneaten();
    void computeLives();
    bool frightmode();
    void checkfrightmode();

public:
    Game();
    void Start();
    void End();
   
};
