#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#include "Game.h"
#include "imgui_include.h"
#include "gamemap.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(1280, 720), "MapTest");
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);

	GameMap testMap;
	GameMap GM;
	Game game;
	game.init();

	sf::Clock deltaClock;

	bool isEditorMap = true;

	if( isEditorMap == false ){

		int select[16][9];
		auto F = freopen("level.map", "r", stdin);

		for(int j = 0 ; j < 9 ; j++ ){
			for(int i = 0 ; i < 16 ; i++ ){
				std::cin >> select[i][j];
				if( select[i][j] == 0 )
					GM.setPlane(i,j);
				else if( select[i][j] == 1 )
					GM.setRock(i,j);
				else if( select[i][j] == 2 )
					GM.setHole(i,j);
				else if( select[i][j] == 3 )
					GM.setKey(i,j);
				else if( select[i][j] == 4 )
					GM.setNone(i,j);
			}
		}

		fclose(F);
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		ImGui::SFML::Update(window, deltaClock.restart());
		game.imgui();

		if( isEditorMap ){

			// map editor
			static int select[16][9];
			ImGui::Begin("Save Map");
			if( ImGui::Button("SAVE") ){
				auto F = freopen("level.map", "w", stdout);
				for(int j = 0 ; j < 9 ; j++ ){
					for(int i = 0 ; i < 16 ; i++ ){
						printf("%d%c",select[i][j],i==15?'\n':' ');
					}
				}
				fclose(F);
			}
			ImGui::End();
			ImGui::Begin("Map");
			for(int i = 0 ; i < 16 ; i++ ){
				for(int j = 0 ; j < 9 ; j++ ){
					ImGui::PushID(i*16+j);
					ImGui::Text("%d %d",i,j);
					ImGui::RadioButton("Plane", &select[i][j],0);ImGui::SameLine();
					ImGui::RadioButton("Rock", &select[i][j],1);ImGui::SameLine();
					ImGui::RadioButton("Hole", &select[i][j],2);ImGui::SameLine();
					ImGui::RadioButton("Key", &select[i][j],3);ImGui::SameLine();
					ImGui::RadioButton("None", &select[i][j],4);

					if( select[i][j] == 0 )
						testMap.setPlane(i,j);
					else if( select[i][j] == 1 )
						testMap.setRock(i,j);
					else if( select[i][j] == 2 )
						testMap.setHole(i,j);
					else if( select[i][j] == 3 )
						testMap.setKey(i,j);
					else if( select[i][j] == 4 )
						testMap.setNone(i,j);

					ImGui::PopID();
				}
			}
			ImGui::End();
			// end map editor

		}

		window.clear();
		if( isEditorMap ){
			testMap.update();
			testMap.draw(window);
		}else{
			GM.update();
			GM.draw(window);
		}
		game.run(window);
		ImGui::SFML::Render(window);
		window.display();
	}

	return EXIT_SUCCESS;
}

