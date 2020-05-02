//
//  Ghosts.hpp
//  SFMLproject
//
//  Created by Yasmina Halbouny on 4/27/20.
//  Copyright © 2020 Yasmina Halbouny. All rights reserved.
//
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
