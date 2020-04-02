#include "obj.h"
#include <vector>

class GameMap{

public:
	GameMap();
	void setRock(int i, int j);
	void setPlane(int i, int j);
	void setNone(int i, int j);
	void update();
	void draw(sf::RenderWindow &window);

private:

	enum class Obj{
		NONE,
		ROCK,
		PLANE
	}m_table[16][9];

	std::vector <Rock> m_rock;
	std::vector <Plane> m_plane;

};