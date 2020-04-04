#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

class Game
{
public:
    Game() = default;
    ~Game() = default;
    void init();
    void imgui();
    void run(sf::RenderWindow &window);
    void edge_detect();
    void handleEvent(sf::RenderWindow &window, Player &player, int move_unit);
private:
    Player player1, player2;
};