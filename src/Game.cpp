#include <iostream>
#include "Game.h"
#include "imgui_include.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_NAME "The_Fugitive"
#define MOVE_UNIT 10

void Game::init()
{
    player1.init(200, 150, 100, 100, 1), player2.init(500, 500, 100, 100, 2);
    player1.set_sprite_src("assets/player.png", 50, 50);
    player2.set_sprite_src("assets/player.png", 50, 50);
}

void Game::imgui()
{
    ImGui::Begin("Player1 Setting");
    ImGui::Text("Player1");
        ImGui::SliderFloat("player1_center_x", (float *)&player1.imgui_x, 0.0f, 1280.0f, "%.0f");
        ImGui::SliderFloat("player1_center_y", (float *)&player1.imgui_y, 0.0f, 720.0f, "%.0f");
        player1.set_x((int)player1.imgui_x);
        player1.set_y((int)player1.imgui_y);
    ImGui::End();
}


void Game::run(sf::RenderWindow &window)
{
    player1.storePos();
    player2.storePos();
    handleEvent(window, player1, MOVE_UNIT);
    handleEvent(window, player2, MOVE_UNIT);
    edge_detect();

    if (player1.iscoll(player2))
    {
        player1.releasePos();
        player2.releasePos();
    }

    player1.update();
    player1.update_imgui_parameter();
    player1.debug(window);
    player1.draw(window);

    player2.update();
    player2.update_imgui_parameter();
    player2.debug(window);
    player2.draw(window);

}

void Game::edge_detect()
{
    // //out of edge range
    if (player1.get_x() - player1.get_width()/2 <= 0 ||
        player1.get_x() + player1.get_width()/2 >= WINDOW_WIDTH ||
        player1.get_y() - player1.get_height()/2 <= 0 ||
        player1.get_y() + player1.get_height()/2 >= WINDOW_HEIGHT)
    {
        player1.releasePos();
    }
    if (player2.get_x() - player2.get_width()/2  <= 0 ||
        player2.get_x() + player2.get_width()/2  >= WINDOW_WIDTH ||
        player2.get_y() - player2.get_height()/2 <= 0 ||
        player2.get_y() + player2.get_height()/2 >= WINDOW_HEIGHT)
    {
        player2.releasePos();
    }
}

void Game::handleEvent(sf::RenderWindow &window, Player &player, int move_unit)
{
    switch(player.getid())
    {
        case 1:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                player.move_up(move_unit);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player.move_down(move_unit);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                player.move_left(move_unit);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player.move_right(move_unit);
            }
            break;
        case 2:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                player.move_up(move_unit);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                player.move_down(move_unit);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                player.move_left(move_unit);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player.move_right(move_unit);
            }
            break;
    }
}