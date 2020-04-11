#include <iostream>
#include "Game.h"
#include "imgui_include.h"
#include "gamemap.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_NAME "The_Fugitive"


void Game::init()
{
    player1.init(100, 100, 80, 80, 1);
    player1.set_sprite_src("assets/player.png");
    player1.scale(1.2,0.9);
    player2.init(440, 440, 80, 80, 2);
    player2.set_sprite_src("assets/player2.png");
    player2.scale(1.2, 0.9);
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            select[i][j] = 0;
        }
    }
}

void Game::imgui()
{
    // ImGui::Begin("Player1 Setting");
    // ImGui::Text("Player1");
    //     ImGui::SliderFloat("player1_center_x", (float *)&player1.imgui_x, 0.0f, 1280.0f, "%.0f");
    //     ImGui::SliderFloat("player1_center_y", (float *)&player1.imgui_y, 0.0f, 720.0f, "%.0f");
    //     player1.set_x((int)player1.imgui_x);
    //     player1.set_y((int)player1.imgui_y);
    // ImGui::End();


    //draw map
    ImGui::Begin("Map");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            ImGui::PushID(i * 16 + j);
            ImGui::Text("%d %d", i, j);
            ImGui::RadioButton("Plane", &select[i][j], 0);
            ImGui::SameLine();
            ImGui::RadioButton("Rock", &select[i][j], 1);
            ImGui::SameLine();
            ImGui::RadioButton("Hole", &select[i][j], 2);
            ImGui::SameLine();
            ImGui::RadioButton("Key", &select[i][j], 3);
            ImGui::SameLine();
            ImGui::RadioButton("None", &select[i][j], 4);

            if (select[i][j] == 0)
                testMap.setPlane(i, j);
            else if (select[i][j] == 1)
                testMap.setRock(i, j);
            else if (select[i][j] == 2)
                testMap.setHole(i, j);
            else if (select[i][j] == 3)
                testMap.setKey(i, j);
            else if (select[i][j] == 4)
                testMap.setNone(i, j);

            ImGui::PopID();
        }
    }
    ImGui::End();
}

void Game::map_collision_test(sf::RenderWindow &window)
{
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            // std::cout << i << " " << j << '\n';
            if(i == 2 && j == 2)
            {
                // std::cout << testMap.Get_gameObject(i, j).get_x() << " " << testMap.Get_gameObject(i, j).get_y() << '\n';
                if (player1.iscoll(testMap.Get_gameObject(i, j)))
                {
                    player1.releasePos();
                }
                if (player2.iscoll(testMap.Get_gameObject(i, j)))
                {
                    player2.releasePos();
                }
            }
        }
    }
}


void Game::run(sf::RenderWindow &window)
{
    player1.storePos();
    player2.storePos();
    player1.handle_input();
    player2.handle_input();
    coll_detect();
    map_collision_test(window);

    testMap.draw(window);

    // player1.update_imgui_parameter();
    player1.update();
    player1.debug(window);
    player1.draw(window);

    player2.update();
    // player2.update_imgui_parameter();
    player2.debug(window);
    player2.draw(window);
}


void Game::coll_detect()
{
    if (player1.iscoll(player2))
    {
        printf("player1 colli player2\n");
        player1.releasePos();
    }
    if (player2.iscoll(player1))
    {
        printf("player2 colli player1\n");
        player2.releasePos();
    }

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

