//
//  Ghosts.cpp
//  SFMLproject
//
//  Created by Yasmina Halbouny on 4/27/20.
//  Copyright © 2020 Yasmina Halbouny. All rights reserved.
//

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
