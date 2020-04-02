#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#include "Game.h"
#include "gamemap.h"

int main()
{
    // Start the game loop
    // Game game;
    // while (true)
    // {
    //     game.run();
    // }

	sf::RenderWindow window(sf::VideoMode(1280, 720), "MapTest");
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

	GameMap testMap;
	sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());
		
		// map editor
		ImGui::Begin("Map");
		static int select[16][9];
		for(int i = 0 ; i < 16 ; i++ ){
			for(int j = 0 ; j < 9 ; j++ ){
				ImGui::PushID(i*16+j);
				ImGui::Text("%d %d",i,j);
				ImGui::RadioButton("None", &select[i][j],0);ImGui::SameLine();
				ImGui::RadioButton("Rock", &select[i][j],1);ImGui::SameLine();
				ImGui::RadioButton("Plane", &select[i][j],2);

				if( select[i][j] == 0 )
					testMap.setNone(i,j);
				else if( select[i][j] == 1 )
					testMap.setRock(i,j);
				else if( select[i][j] == 2 )
					testMap.setPlane(i,j);

				ImGui::PopID();
			}
		}
		ImGui::End();
		// end map editor

		testMap.update();
        window.clear();
        testMap.draw(window);
		ImGui::SFML::Render(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
