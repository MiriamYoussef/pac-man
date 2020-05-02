

#include"Player.hpp"
#include"Ghosts.hpp"
#include"Board.hpp"
#include"Game.hpp"
#include<fstream>
const int rows=34;
const int cols=28;
int main()
{
    // Create the main window
    RenderWindow window;
    window.create(VideoMode(1200, 1400), "Pacman Game");

    int arr[rows][cols];
    ifstream inputFile;
    inputFile.open("map.txt");
    if (inputFile.is_open())
    {
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols;j++)
                if (!inputFile.eof())
                    inputFile>>arr[i][j];
    }
    inputFile.close();
    
    Player player(26,14,"pacmanright.png","pacmanleft.png","pacmanup.png","pacmandown.png");
    Ghost Pinky (12,16,"pinkypic.png");
    Ghost Inky (14,16,"inkypic.png");
    Ghost Blinky (16,16,"blinkypic.png");
    Ghost Clyde (13,14,"clydepic.png");
    Board board(arr);
    
    Event e;
    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
            
            else if (e.type == Event::KeyPressed)
            {
                switch (e.key.code)
                {
                 case Keyboard::Up:
                    player.Move('U', arr);
                    break;
                case Keyboard::Down:
                    player.Move('D', arr);
                    break;
                case Keyboard::Right:
                    player.Move('R', arr);
                    break;
                case Keyboard::Left:
                    player.Move('L', arr);
                    break;
                
                }
            }
        }
        window.clear();
       
        board.drawonwindow(window,rows,cols);
            
        player.DrawOnWindow(window);
        Pinky.DrawOnWindow(window);
        Clyde.DrawOnWindow(window);
        Inky.DrawOnWindow(window);
        Blinky.DrawOnWindow(window);
        window.display();
            
        }
            
    
    return 0;
}
