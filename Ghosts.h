#include<iostream>
#include<iostream>
#include<time.h>  
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
    void Set_Ghost(int, int, string);
    void Normal_mode();
    //void Fright_mode();
    void DrawOnWindow(RenderWindow&);
    void Moverand(int arr[34][28]);
    RectangleShape ghosts;

};

