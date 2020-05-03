

#include "Player.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include "Board.h"
#include<fstream> 
using namespace std;
using namespace sf;

Player::Player()
{

}

Player::Player(int initialrow, int initialcol, string rightimage, string leftimage, string upimage, string downimage)
{
    row = initialrow;
    column = initialcol;
    pac.setSize(Vector2f(40, 40));
    pac.setPosition(40 + 40 * initialcol, 40 + 40 * initialrow);
    right.loadFromFile(rightimage);
    left.loadFromFile(leftimage);
    up.loadFromFile(upimage);
    down.loadFromFile(downimage);
    pac.setTexture(&left);
}

void Player::DrawOnWindow(RenderWindow& window)
{
    window.draw(pac);
}
void Player::Move(char direction, int arr[34][28])
{
    if (tolower(direction) == 'u')
    {
        pac.setTexture(&up);
        if (arr[row - 1][column] != 1)
        {
            pac.move(0, -40);
            row--;
        }
    }
    else if (tolower(direction) == 'd')
    {
        pac.setTexture(&down);
        if (arr[row + 1][column] != 1)
        {
            pac.move(0, 40);
            row++;
        }

    }
    else if (tolower(direction) == 'l')
    {
        pac.setTexture(&left);
        if (arr[row][column - 1] != 1)
        {
            pac.move(-40, 0);
            column--;
        }
        if (arr[row][column] == 4)
        {
            row = 16;
            column = 27;
            pac.setPosition(40 + 40 * column, 40 + 40 * row);
        }
    }
    else if (tolower(direction) == 'r')
    {
        pac.setTexture(&right);
        if (arr[row][column + 1] != 1)
        {
            pac.move(40, 0);
            column++;
        }
        if (arr[row][column] == 4)
        {
            row = 16;
            column = 0;
            pac.setPosition(40 + 40 * column, 40 + 40 * row);
        }
    }
}

int Player::GetRow()
{
    return row;
}
int Player::GetColumn()
{
    return column;
}
