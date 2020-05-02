//
//  Player.hpp
//  SFMLproject
//
//  Created by Yasmina Halbouny on 4/27/20.
//  Copyright © 2020 Yasmina Halbouny. All rights reserved.
//



#ifndef Player_hpp
#define Player_hpp
#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
using namespace std;
using namespace sf;

class Player
{
private:

    int row, column;
    Texture right, left, up,down;
    RectangleShape shape;

public:
    Player(int initialrow, int initialcol,string rightimage, string leftimage, string upimage, string downimage);
    void DrawOnWindow (RenderWindow&);
    void Move(char direction, int [][28]);
    int GetRow ();
    int GetColumn ();
};
#endif /* Player_hpp */
