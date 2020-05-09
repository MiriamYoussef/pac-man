#include "Ghosts.h"

Ghost::Ghost()
{

}


void Ghost::Set_Ghost(int initialcol, int initialrow, string imagename)
{
    ghosts.setPosition(40 + 40 * initialcol, 40 + 40 * initialrow);
    row = initialrow;
    column = initialcol;
    ghosts.setSize(Vector2f(40, 40));
    texture.loadFromFile(imagename);
    ghosts.setTexture(&texture);
}

void Ghost::Moverand(int arr[34][28])
{
    srand(time(NULL));
    
    char direction;
    int m = rand() % 4 ;

      //use same function but add here a rand function to assign value to direction 
      //do not pass direction as a funtion parameter
    //if (ghosts.getGlobalBounds().intersects())
    if (m == 1)
    {

        //(tolower(direction) == 'u');
        if (arr[row - 1][column] != -1 )
        {
            ghosts.move(Vector2f(0, -40));
            row--;
        }
    }
    else if (m == 2)
    {
        //(tolower(direction) == 'd');

        if (arr[row + 1][column] != -1 && arr[row + 1][column] != -2)
        {
            ghosts.move(Vector2f(0, 40));
            row++;
        }

    }
    else if (m == 3)
    {

        //(tolower(direction) == 'l');
    
          if (arr[row][column - 1] != -1 )
          {
              ghosts.move(Vector2f(-40, 0));
              column--;
          }
          if (arr[row][column] == 143 || arr[row][column] == 126)
          {
              row = 16;
              column = 27;
              ghosts.setPosition(40 + 40 * column, 40 + 40 * row);
          }
    } 
      else if (m==4)
      {
       // (tolower(direction) == 'r');
      
          if (arr[row][column + 1] != -1)
          {
              ghosts.move(Vector2f(40, 0));
              column++;
          }
          if (arr[row][column] == 143 || arr[row][column] == 126)
          {
              row = 16;
              column = 0;
              ghosts.setPosition(40 + 40 * column, 40 + 40 * row);
          }
      }
    
}

void Ghost::DrawOnWindow(RenderWindow& window)
{
    window.draw(ghosts);
}
void Ghost::Normal_mode()
{

}