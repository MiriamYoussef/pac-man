#pragma once
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
    void Set_Board(int[][28]);
    CircleShape dot[34][28];
    RectangleShape board[34][28];
    Board();
};