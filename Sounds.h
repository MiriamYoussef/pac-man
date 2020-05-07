#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include"Player.h"

using namespace std;
using namespace sf;

class Sounds
{

public:
	Sounds();
	void set_Sounds(string soundfile);
	Sound s;
	SoundBuffer buffer;

};

