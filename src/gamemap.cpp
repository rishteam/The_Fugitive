#include "gamemap.h"

GameMap::GameMap(){
	for(int i = 0 ; i < 16 ; i++ )
		for(int j = 0 ; j < 9 ; j++ )
			m_table[i][j] = Obj::NONE;
	m_rock.clear();
	m_plane.clear();
}

void GameMap::setNone(int i, int j){
	m_table[i][j] = Obj::NONE;
}

void GameMap::setRock(int i, int j){
	m_table[i][j] = Obj::ROCK;
}

void GameMap::setPlane(int i, int j){
	m_table[i][j] = Obj::PLANE;
}

void GameMap::update(){
	m_rock.clear();
	m_plane.clear();
	for(int i = 0 ; i < 16 ; i++ ){
		for(int j = 0 ; j < 9 ; j++ ){
			if( m_table[i][j] == Obj::ROCK )
				m_rock.push_back(Rock(i*80,j*80,80,80));
			if( m_table[i][j] == Obj::PLANE )
				m_plane.push_back(Plane(i*80,j*80,80,80));
		}
	}

}

void GameMap::draw(sf::RenderWindow &window){
	for(auto i : m_rock){
		i.set_sprite_src("assets/rock.png",80,80);
		// i.debug(window);
		i.update();
		i.draw(window);
	}
	for(auto i : m_plane){
		i.set_sprite_src("assets/plane.png",80,80);
		// i.debug(window);
		i.update();
		i.draw(window);
	}
}
