#include "Sounds.h"
#include "Player.h"

Sounds::Sounds()
{
	buffer.loadFromFile("dot.wav");
	s.setBuffer(buffer);
}

void Sounds::set_Sounds(string soundfile)
{
	buffer.loadFromFile(soundfile);
	s.setBuffer(buffer);
}