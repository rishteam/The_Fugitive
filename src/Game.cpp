#include <iostream>
#include "Game.h"
#include "imgui_include.h"
#include "gamemap.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GAME_NAME "The_Fugitive"
#define MOVE_UNIT 10

void Game::init()
{
	player1.init(40, 40, 80, 80, 1);
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

void Game::imgui(sf::RenderWindow &window)
{
	// ImGui::Begin("Player1 Setting");
	// ImGui::Text("Player1");
	//     ImGui::SliderFloat("player1_center_x", (float *)&player1.imgui_x, 0.0f, 1280.0f, "%.0f");
	//     ImGui::SliderFloat("player1_center_y", (float *)&player1.imgui_y, 0.0f, 720.0f, "%.0f");
	//     player1.set_x((int)player1.imgui_x);
	//     player1.set_y((int)player1.imgui_y);
	// ImGui::End();

	//draw map
	sf::Texture testT[5];
	sf::Sprite testS[5];
	testT[0].loadFromFile("assets/rock.png");
	testS[0].setTexture(testT[0]);

	testT[1].loadFromFile("assets/plane.png");
	testS[1].setTexture(testT[1]);

	testT[2].loadFromFile("assets/hole.png");
	testS[2].setTexture(testT[2]);

	testT[3].loadFromFile("assets/key.png");
	testS[3].setTexture(testT[3]);

	ImGui::Begin("test");
	ImGui::Image(testS[0]);
	ImGui::End();
	window.clear();
	testS[0].setPosition(222,222);
	window.draw(testS[0]);


	ImGui::Begin("Map");


	if(ImGui::ImageButton(testS[0],ImVec2(30,30)))
		printf("0\n");
	ImGui::SameLine();
	if(ImGui::ImageButton(testS[1],ImVec2(30,30)))
		printf("1\n");
	ImGui::SameLine();
	if(ImGui::ImageButton(testS[2],ImVec2(30,30)))
		printf("2\n");
	ImGui::SameLine();
	if(ImGui::ImageButton(testS[3],ImVec2(30,30)))
		printf("3\n");

	for (int j = 0; j < 9; j++)
	{
		ImGui::NewLine();
		for (int i = 0; i < 16; i++)
		{
			ImGui::PushID(j * 20 + i);
			
			// if( ImGui::ImageButton(testS[select[i][j]],ImVec2(30,30)) ){
			// 	select[i][j] = (select[i][j]+1)%5;
			// }

			std::string str = std::to_string(select[i][j]);
			char const *Btn = str.c_str();
			if( ImGui::Button(Btn,ImVec2(30,30)) ){
				select[i][j] = (select[i][j]+1)%5;
			}
			
			ImGui::SameLine();
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
	handleEvent(window, player1, MOVE_UNIT);
	handleEvent(window, player2, MOVE_UNIT);
	coll_detect();
	map_collision_test(window);

	testMap.draw(window);

	player1.update_imgui_parameter();
	player1.update();
	player1.debug(window);
	player1.draw(window);

	player2.update();
	player2.update_imgui_parameter();
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