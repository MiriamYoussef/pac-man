

#include "Player.hpp"
Player::Player(int initialrow, int initialcol, string rightimage, string leftimage, string upimage, string downimage)
{
    row = initialrow;
    column = initialcol;
    shape.setSize(Vector2f(40, 40));
    shape.setPosition(40 + 40 *initialcol , 40 + 40*initialrow );
    right.loadFromFile(rightimage);
    left.loadFromFile(leftimage);
    up.loadFromFile(upimage);
    down.loadFromFile(downimage);
    shape.setTexture(&left);
}
void Player::DrawOnWindow (RenderWindow& window)
{
    window.draw(shape);
}
void Player::Move(char direction, int arr[34][28])
{
    if(tolower(direction)=='u')
    {
        shape.setTexture(&up);
        if (arr[row - 1][column] != 1)
        {
            shape.move(0, -40);
            row--;
        }
    }
    else if(tolower(direction)=='d')
    {
        shape.setTexture(&down);
        if (arr[row + 1][column] != 1)
                {
                    shape.move(0, 40);
                    row++;
                }
       
    }
    else if(tolower(direction)=='l')
    {
        shape.setTexture(&left);
       if (arr[row][column - 1] != 1)
                {
                    shape.move(-40, 0);
                    column--;
                }
        if (arr[row][column]==4)
               {
                   row=16;
                   column=27;
                   shape.setPosition(40+40*column, 40+40*row);
               }
    }
    else if(tolower(direction)=='r')
    {
         shape.setTexture(&right);
        if (arr[row][column + 1] != 1)
                {
                    shape.move(40, 0);
                    column++;
                }
        if (arr[row][column]==4)
        {
            row=16;
            column=0;
            shape.setPosition(40+40*column, 40+40*row);
        }
    }
}

int Player::GetRow ()
{
    return row;
}
int Player::GetColumn ()
{
    return column;
}

