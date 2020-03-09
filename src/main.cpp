#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../inc/Player.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MOVE_UNIT 10
#define GAME_NAME "The_Fugitive"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
    Player player1(50, 50, 100, 100), player2(500, 500, 100, 100);
    player1.set_sprite_src("assets/player.png", 50, 50);
    player2.set_sprite_src("assets/player.png", 50, 50);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
        }

        window.clear();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Left)
                {
                    player2.move_left(MOVE_UNIT);
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    player2.move_right(MOVE_UNIT);
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    player2.move_up(MOVE_UNIT);
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    player2.move_down(MOVE_UNIT);
                }
                else if (event.key.code == sf::Keyboard::A)
                {
                    player1.move_left(MOVE_UNIT);
                }
                else if (event.key.code == sf::Keyboard::D)
                {
                    player1.move_right(MOVE_UNIT);
                }
                else if (event.key.code == sf::Keyboard::W)
                {
                    player1.move_up(MOVE_UNIT);
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    player1.move_down(MOVE_UNIT);
                }
        }

        if (player1.coll(player2))
        {
            std::cout << "Collision" << '\n';
        }
        else
        {
            std::cout << "NOT Collision" << '\n';
        }
        player1.debug(window);
        player1.update();
        player1.draw(window);
        player2.debug(window);
        player2.update();
        player2.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
