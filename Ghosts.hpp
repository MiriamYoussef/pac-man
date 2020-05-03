
#include<iostream>
#include<iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include"Player.h"
using namespace std;
using namespace sf;


#include <stdio.h>

class Ghost
{
private:
    int row, column;
    Texture texture;
public:
    Ghost();
    Ghost(int, int, string);
    void Normal_mode();
    void Fright_mode();
    void DrawOnWindow(RenderWindow&);
    RectangleShape ghosts;

};

#endif /* Ghosts_hpp */
