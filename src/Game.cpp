#include <iostream>
#include "Game.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_NAME "The_Fugitive"
#define MOVE_UNIT 10

void Game::run(sf::RenderWindow &window, sf::Event &event)
{
    Player player1(50, 50, 100, 100), player2(500, 500, 100, 100);
    player1.set_sprite_src("assets/player.png", 50, 50);
    player2.set_sprite_src("assets/player.png", 50, 50);

    handleEvent(window, event);
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
    player2.handleInput(event, MOVE_UNIT, 2);
    // player1.handleInput(event, MOVE_UNIT, 1);
    player2.debug(window);
    player2.update();
    player2.draw(window);

}

void Game::handleEvent(sf::RenderWindow &window, sf::Event event)
{
    switch (event.type)
    {
        case sf::Event::Closed:
            window.close();
            break;
    }
}