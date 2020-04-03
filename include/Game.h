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
    void catch_event(sf::Event &e);
    sf::Event get_event();
    void run(sf::RenderWindow &window);
    void edge_detect();
    void handleEvent(sf::RenderWindow &window, Player &player, int move_unit);
private:
    Player player1, player2;
    sf::Event event;
};