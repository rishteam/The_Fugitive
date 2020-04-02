#include "game_object.h"

class Plane : public GameObject{

public:
	Plane() = default;
	Plane(int x,int y,int w, int h);
};

class Rock : public GameObject{

public:
	Rock() = default;
	Rock(int x,int y,int w, int h);
};
