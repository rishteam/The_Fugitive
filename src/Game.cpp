#include <iostream>
#include "Game.h"
#include "Player.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_NAME "The_Fugitive"
#define MOVE_UNIT 10

void Game::setwindow()
{
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
}

void Game::run()
{
    setwindow();
    Player player1(50, 50, 100, 100), player2(500, 500, 100, 100);
    player1.set_sprite_src("assets/player.png", 50, 50);
    player2.set_sprite_src("assets/player.png", 50, 50);

    while(window.isOpen())
    {
        window.clear();
        if (player1.iscoll(player2))
        {
            std::cout << "is Collision" << '\n';
        }
        else
        {
            std::cout << "is not Collision" << '\n';
        }

        player1.debug(window);
        player1.update();
        player1.draw(window);
        player2.debug(window);
        player2.update();
        player2.draw(window);
        handleEvent();
        window.display();
    }
}

void Game::handleEvent()
{
    sf::Event event;
    switch (event.type)
    {
        case sf::Event::Closed:
            window.close();
            break;
    }
}