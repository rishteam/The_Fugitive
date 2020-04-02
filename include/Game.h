#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

class Game
{
public:
    Game() = default;
    void run(sf::RenderWindow &window, sf::Event &event);
    void handleEvent(sf::RenderWindow &window, sf::Event event);
};