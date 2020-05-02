
#include<iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#ifndef Ghosts_hpp
#define Ghosts_hpp
#include <stdio.h>

class Ghost
{
private:
    int row, column;
    RectangleShape shape;
    Texture texture;
public:
    Ghost(int, int, string);
    void Normal_mode();
    void Fright_mode();
    void DrawOnWindow (RenderWindow&);

};
#endif /* Ghosts_hpp */
