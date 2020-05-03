
#include "Board.h"

Board::Board(int arr[34][28])
{
    brick.loadFromFile("bricks.png");
    black.loadFromFile("black.jpeg");

    for (int i = 0; i < 34; i++)
        for (int j = 0; j < 28; j++)
        {
            board[i][j].setPosition(40 + 40 * j, 40 + 40 * i);
            board[i][j].setSize(Vector2f(40, 40));
            dot[i][j].setPosition(40 + 40.5 * j, 40 + 40.5 * i);
            dot[i][j].setRadius(5.0);
            if (arr[i][j] == 1)
            {
                board[i][j].setSize(Vector2f(40, 40));
                board[i][j].setTexture(&brick);
                dot[i][j].setFillColor(Color::Transparent);
            }
            else if (arr[i][j] == 2 || arr[i][j] == 4)
            {
                board[i][j].setTexture(&black);
                dot[i][j].setFillColor(Color::White);
            }
            else if (arr[i][j] == 3)
            {
                board[i][j].setTexture(&black);
                dot[i][j].setRadius(10.0);
                dot[i][j].setFillColor(Color::Yellow);
            }
            else if (arr[i][j] == 0)
            {
                board[i][j].setTexture(&black);
                dot[i][j].setFillColor(Color::Transparent);
            }


        }
}
Board::Board()
{
    row = 34;
    col = 28;
}
void Board::drawonwindow(RenderWindow& window, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            window.draw(board[i][j]);
            window.draw(dot[i][j]);
        }
}
