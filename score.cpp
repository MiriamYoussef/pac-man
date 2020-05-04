#include "score.h"
score::score(string fonttxt)
{
    pacmanscore = 0;
    font.loadFromFile(fonttxt);
    Score.setFont(font);
    Score.setFillColor(Color::White);
    Score.setCharacterSize(20);
    Score.setPosition(50, 50);
}
