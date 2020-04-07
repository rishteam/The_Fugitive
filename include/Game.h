#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "gamemap.h"

class Game
{
public:
    Game() = default;
    ~Game() = default;
    void init();
    void imgui();
    void map_collision_test(sf::RenderWindow &window);
    void run(sf::RenderWindow &window);
    void coll_detect();
    void handleEvent(sf::RenderWindow &window, Player &player, int move_unit);

protected:
    int select[16][9];

private:
    Player player1, player2;
    GameMap testMap;
};