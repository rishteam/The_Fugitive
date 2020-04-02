#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <bits/stdc++.h>

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
	static int select[16][9];

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());
		
        if (ImGui::BeginMainMenuBar()){
		    if (ImGui::BeginMenu("File")){   
		        if (ImGui::MenuItem("Quit", "Alt+F4")) break;
		        ImGui::EndMenu();
		    }
		    if (ImGui::BeginMenu("Edit")){   
		        if( ImGui::MenuItem("Save") ){
		            auto F = freopen("testMap.data","w",stdout);
	            	for(int i = 0 ; i < 16 ; i++ ){
	            		for(int j = 0 ; j < 9 ; j++ ){
	            			printf("%d%c",select[i][j],j==8?'\n':',');
	            		}
	            	}
	            	fclose(F);
		        }
		        ImGui::EndMenu();
		    }
		    ImGui::EndMainMenuBar();
		}

		// map editor
		ImGui::Begin("Map");
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
