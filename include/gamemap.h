#include "obj.h"
#include <vector>

class GameMap{

public:
	GameMap();
	void setNone(int i, int j);
	void setRock(int i, int j);
	void setPlane(int i, int j);
	void setHole(int i, int j);
	void setKey(int i, int j);
	void update();
	void draw(sf::RenderWindow &window);

	void editor(sf::RenderWindow &window);

private:

	enum class Obj{
		NONE,
		ROCK,
		PLANE,
		HOLE,
		KEY
	}m_table[16][9];

	Rock m_rock[16][9];
	Plane m_plane[16][9];
	Hole m_hole[16][9];
	Key m_key[16][9];

};