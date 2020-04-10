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
    void imgui(sf::RenderWindow &window);
    void map_collision_test(sf::RenderWindow &window);
    void run(sf::RenderWindow &window);
    void coll_detect();
    void handleEvent(sf::RenderWindow &window, Player &player, int move_unit);

// TODO: Debug
public:
    sf::Texture testT[5];
    sf::Sprite testS[5];
    void initRes()
    {
        testT[1].loadFromFile("assets/rock.png");
        testS[1].setTexture(testT[1]);

        testT[0].loadFromFile("assets/plane.png");
        testS[0].setTexture(testT[0]);

        testT[2].loadFromFile("assets/hole.png");
        testS[2].setTexture(testT[2]);

        testT[3].loadFromFile("assets/key.png");
        testS[3].setTexture(testT[3]);
    }

protected:
    int select[16][9];

private:
    Player player1, player2;
    GameMap testMap;
};