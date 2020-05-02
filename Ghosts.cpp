
#include "Ghosts.hpp"
Ghost::Ghost(int initialcol, int initialrow, string imagename)
{
   shape.setPosition(40 + 40 * initialcol, 40 + 40 * initialrow);
   row=initialrow;
   column=initialcol;
   shape.setSize(Vector2f(40,40));
   texture.loadFromFile(imagename);
    shape.setTexture(&texture);
}
void Ghost::Fright_mode()
{
    
}
void Ghost::DrawOnWindow(RenderWindow& window)
{
        window.draw(shape);
}
void Normal_mode()
{
    
}
