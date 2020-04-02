#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{
public:
    Game() = default;

    void setwindow();
    void run();
    void handleEvent();

private:
    sf::RenderWindow window;
};