//
//  Board.hpp
//  SFMLproject
//
//  Created by Yasmina Halbouny on 4/27/20.
//  Copyright © 2020 Yasmina Halbouny. All rights reserved.
//
#ifndef Board_hpp
#define Board_hpp

#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>

using namespace std;
using namespace sf;

class Board
{
private:
    
    Texture brick, black;
    int row, col;
    //int XB,YB;
    //int XD,YD;
public:
    void drawonwindow(RenderWindow& window, int  rows, int cols);
    Board(int [][28]);
    CircleShape dot[34][28];
    RectangleShape board[34][28];
    Board();
};
#endif /* Board_hpp */
