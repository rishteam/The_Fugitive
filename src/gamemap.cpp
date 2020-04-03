#include "gamemap.h"

GameMap::GameMap(){
	for(int i = 0 ; i < 16 ; i++ )
		for(int j = 0 ; j < 9 ; j++ )
			m_table[i][j] = Obj::NONE;

	for(int i = 0 ; i < 16 ; i++ ){
		for(int j = 0 ; j < 9 ; j++ ){
			m_rock[i][j] = Rock(i*80,j*80,80,80);
			m_rock[i][j].set_sprite_src("assets/rock.png",80,80);
			m_plane[i][j] = Plane(i*80,j*80,80,80);
			m_plane[i][j] .set_sprite_src("assets/plane.png",80,80);
			m_hole[i][j] = Hole(i*80,j*80,80,80);
			m_hole[i][j].set_sprite_src("assets/hole.png",80,80);
			m_key[i][j] = Key(i*80,j*80,80,80);
			m_key[i][j].set_sprite_src("assets/key.png",80,80);
		}
	}

	// for(auto i : m_rock)
	// 	i.set_sprite_src("assets/rock.png",80,80);
	// for(auto i : m_plane)
	// 	i.set_sprite_src("assets/plane.png",80,80);
	// for(auto i : m_hole)
	// 	i.set_sprite_src("assets/hole.png",80,80);
	// for(auto i : m_key)
	// 	i.set_sprite_src("assets/key.png",80,80);

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

void GameMap::setHole(int i, int j){
	m_table[i][j] = Obj::HOLE;
}

void GameMap::setKey(int i, int j){
	m_table[i][j] = Obj::KEY;
}


void GameMap::update(){

}

void GameMap::draw(sf::RenderWindow &window){

	for(int i = 0 ; i < 16 ; i++ ){
		for(int j = 0 ; j < 9 ; j++ ){
			if( m_table[i][j] == Obj::ROCK ){
				m_rock[i][j].update();
				m_rock[i][j].draw(window);
			}
			if( m_table[i][j] == Obj::PLANE ){
				m_plane[i][j].update();
				m_plane[i][j].draw(window);
			}
			if( m_table[i][j] == Obj::HOLE ){
				m_hole[i][j].update();
				m_hole[i][j].draw(window);
			}
			if( m_table[i][j] == Obj::KEY ){
				m_plane[i][j].update();
				m_key[i][j].update();
				m_plane[i][j].draw(window);
				m_key[i][j].draw(window);
			}
		}
	}

	
}
