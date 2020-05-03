

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
    Texture right, left, up, down;

public:
    Player();
    Player(int initialrow, int initialcol, string rightimage, string leftimage, string upimage, string downimage);
    void DrawOnWindow(RenderWindow&);
    void Move(char direction, int[34][28]);
    int GetRow();
    int GetColumn();
    RectangleShape pac;

};
 
#endif /* Player_hpp */
