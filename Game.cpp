#include "Game.h"

Game::Game()
{
    player.Set_Player(26, 14, "pacmanright.png", "pacmanleft.png", "pacmanup.png", "pacmandown.png");
    Pinky.Set_Ghost(12, 16, "pinkypic.png");
     Inky.Set_Ghost(14, 16, "inkypic.png");
     Blinky.Set_Ghost(16, 16, "blinkypic.png");
     Clyde.Set_Ghost(13, 14, "clydepic.png");
   
     blue.loadFromFile("blueghost.png");

     sec = seconds(7.0);
     elapsed = clock.getElapsedTime();

    score = 0;
    highscore = 0;
    pacmanlives = 3;

    window.create(VideoMode(1200, 1400), "Pacman Game");
    ifstream inputFile;
    inputFile.open("map.txt");
    if (inputFile.is_open())
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (!inputFile.eof())
                    inputFile >> arr[i][j];
    }
    inputFile.close();

    transparent.loadFromFile("transparent.png");
    font.loadFromFile("sansation.ttf");

    scoretext.setFont(font);
    scoretext.setString("SCORE");
    scoretext.setCharacterSize(60);
    scoretext.setFillColor(Color::White);
    scoretext.setPosition(40, 40);

    highscoretext.setFont(font);
    highscoretext.setString("HIGHSCORE");
    highscoretext.setCharacterSize(60);
    highscoretext.setFillColor(Color::White);
    highscoretext.setPosition(40 + 40 * 10, 40);

    livestext.setFont(font);
    livestext.setString("LIVES");
    livestext.setCharacterSize(40);
    livestext.setFillColor(Color::White);
    livestext.setPosition(40 + 40 * 2, 40 + 40 * 32);

    starttext.setFont(font);
    starttext.setString("READY?");
    starttext.setCharacterSize(40);
    starttext.setFillColor(Color::White);
    starttext.setPosition(40 + 40 * 13, 40 + 40 * 25);

    endtext.setFont(font);
    endtext.setString("GAME OVER");
    endtext.setCharacterSize(80);
    endtext.setFillColor(Color::White);
    endtext.setPosition(40 + 40, 40 + 40);


}

void Game::LivesConstructor()
{
    life.loadFromFile("pacmanleft.png");
    life1.setSize(Vector2f(40, 40));
    life2.setSize(Vector2f(40, 40));
    life3.setSize(Vector2f(40, 40));
    life1.setPosition(40 + 40 * 1, 40 + 40 * 33);
    life2.setPosition(40 + 40 * 3, 40 + 40 * 33);
    life3.setPosition(40 + 40 * 5, 40 + 40 * 33);
    life1.setTexture(&life);
    life2.setTexture(&life);
    life3.setTexture(&life);
}
void Game::Display_lives()
{
    if (pacmanlives == 3)
    {
        window.draw(life1);
        window.draw(life2);
        window.draw(life3);
    }
    else if (pacmanlives == 2)
    {
        window.draw(life1);
        window.draw(life2);
    }
    else if (pacmanlives == 1)
    {
        window.draw(life1);
    }

}

void Game::Display_score()
{
    stringstream text;
    text << "Score: " << score;
    scoretext.setString(text.str());
    window.draw(scoretext);
}

void Game::Start()
{
   /* Player player(26, 14, "pacmanright.png", "pacmanleft.png", "pacmanup.png", "pacmandown.png");
    Ghost Pinky(12, 16, "pinkypic.png");
    Ghost Inky(14, 16, "inkypic.png");
    Ghost Blinky(16, 16, "blinkypic.png");
    Ghost Clyde(13, 14, "clydepic.png");
    Board board(arr);*/
    board.Set_Board(arr);
    LivesConstructor();
    stringstream ss;

    scorenumbers.setFont(font);
    scorenumbers.setPosition(40 + 40, 40 + 40);
    scorenumbers.setCharacterSize(60);
    scorenumbers.setFillColor(Color::White);


    Event e;
    while (window.isOpen())
    {


        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

            else if (e.type == Event::KeyPressed)
            {
                switch (e.key.code)
                {
                case Keyboard::Up:
                    player.Move('U', arr);
                    break;
                case Keyboard::Down:
                    player.Move('D', arr);
                    break;
                case Keyboard::Right:
                    player.Move('R', arr);
                    break;
                case Keyboard::Left:
                    player.Move('L', arr);
                    break;

                }

            }
            Inky  .Moverand(arr);
            Pinky .Moverand( arr);
            Blinky.Moverand( arr);
            Clyde .Moverand(arr);
        }                 
        pelleteaten();
        pacmaneaten();
        frightmode();
        checkfrightmode();
        window.clear();
        ss << score;
        scorenumbers.setString(ss.str());
        window.draw(scorenumbers);
        board.drawonwindow(window, rows, cols);
        player.DrawOnWindow(window);
        Pinky.DrawOnWindow(window);
        Clyde.DrawOnWindow(window);
        Inky.DrawOnWindow(window);
        Blinky.DrawOnWindow(window);
        window.draw(scoretext);
        //window.draw(highscoretext);
        window.draw(livestext);
        Display_lives();
        Display_score();
        computeLives();
        window.display();
    }

}

void Game::pelleteaten()
{
    for (int i = 0; i < 34; i++) 
    {
        for (int j = 0; j < 28; j++)
        {
            if (player.pac.getGlobalBounds().intersects(board.dot[i][j].getGlobalBounds()) && board.dot[i][j].getFillColor() == Color::White)
            {
                cout << "in pellet";
                board.dot[i][j].setFillColor(Color::Transparent);
                score = score + 10;
                sounds.set_Sounds("dot.wav");
                sounds.s.play();
            }
            else if (player.pac.getGlobalBounds().intersects(board.dot[i][j].getGlobalBounds()) && board.dot[i][j].getFillColor() == Color::Yellow)
            {
                cout << "super pellet";
                board.dot[i][j].setFillColor(Color::Transparent);
                score = score + 50;
                sounds.set_Sounds("dot.wav");
                sounds.s.setBuffer(sounds.buffer);
                sounds.s.play();
            }
            
        }
    }
}

void Game::pacmaneaten(){
    for (int i = 0; i < 34; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            if (player.pac.getGlobalBounds().intersects(Inky.ghosts.getGlobalBounds()) && frightmode() == false)
            {
                pacmanlives--;
                player.Set_Player(26, 14, "pacmanright.png", "pacmanleft.png", "pacmanup.png", "pacmandown.png");
            }
            else if (player.pac.getGlobalBounds().intersects(Pinky.ghosts.getGlobalBounds()) && frightmode() == false)
            {
                pacmanlives--;
                player.Set_Player(26, 14, "pacmanright.png", "pacmanleft.png", "pacmanup.png", "pacmandown.png");
            }
            else if (player.pac.getGlobalBounds().intersects(Clyde.ghosts.getGlobalBounds()) && frightmode() == false)
            {
                pacmanlives--;
                player.Set_Player(26, 14, "pacmanright.png", "pacmanleft.png", "pacmanup.png", "pacmandown.png");
            }
            else if (player.pac.getGlobalBounds().intersects(Blinky.ghosts.getGlobalBounds())  && frightmode() == false)
            {
                pacmanlives--;
                player.Set_Player(26, 14, "pacmanright.png", "pacmanleft.png", "pacmanup.png", "pacmandown.png");
            }
            else if (player.pac.getGlobalBounds().intersects(Blinky.ghosts.getGlobalBounds()) && frightmode() == true)
            {
                score=score+200;
            }
            else if (player.pac.getGlobalBounds().intersects(Inky.ghosts.getGlobalBounds()) && frightmode() == true)
            {
                score = score + 200;
            }
            else if (player.pac.getGlobalBounds().intersects(Pinky.ghosts.getGlobalBounds()) && frightmode() == true)
            {
                score = score + 200;
            }
            else if (player.pac.getGlobalBounds().intersects(Clyde.ghosts.getGlobalBounds()) && frightmode() == true)
            {
                score = score + 200;
            }
            
        }
    }
}

bool Game::frightmode()
{
    for (int i = 0; i < 34; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            if (player.pac.getGlobalBounds().intersects(board.dot[i][j].getGlobalBounds()) && board.dot[i][j].getFillColor() == Color::Yellow)
            {
                return true;
            }
            else 
                return false;
        }
    }
}

void Game::checkfrightmode()
{
    if (frightmode() == true)
    {
        clock.restart();
        while (clock.getElapsedTime() < sec )
        {
            Pinky.ghosts.setTexture(&blue);
            Inky.ghosts.setTexture(&blue);
            Blinky.ghosts.setTexture(&blue);
            Clyde.ghosts.setTexture(&blue);
        }
    }
}

void Game::computeLives()
{
    if (pacmanlives == 0)
        End();
}

void Game::End()
{
    window.draw(endtext);
}
