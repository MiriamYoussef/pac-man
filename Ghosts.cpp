
#include "Ghosts.h"

Ghost::Ghost()
{

}

Ghost::Ghost(int initialcol, int initialrow, string imagename)
{
    ghosts.setPosition(40 + 40 * initialcol, 40 + 40 * initialrow);
    row = initialrow;
    column = initialcol;
    ghosts.setSize(Vector2f(40, 40));
    texture.loadFromFile(imagename);
    ghosts.setTexture(&texture);
}



void Ghost::Fright_mode()
{

}


void Ghost::DrawOnWindow(RenderWindow& window)
{
    window.draw(ghosts);
}
void Normal_mode()
{

}
