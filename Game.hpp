//
//  Game.hpp
//  SFMLproject
//
//  Created by Yasmina Halbouny on 4/28/20.
//  Copyright © 2020 Yasmina Halbouny. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include"Board.hpp"
#include "Player.hpp"
#include  "Ghosts.hpp"
struct Lives
{
    int lives=3;
    
};
struct Score
{
    int score=0;
};
class Game
{
private:
    
public:
    bool pellet(int, int);
    bool powerpellet(int, int);
    bool checkifEaten(int, int, int, int);
    void computeLives();
    void frightmode();
    void Start();
    void End();
    void displayLives();
    void displayScore();
    Game();
};

#endif /* Game_hpp */
