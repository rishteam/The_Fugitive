#include "game_object.h"

class Rock : public GameObject{

public:
	Rock() = default;
	~Rock() = default;
	Rock(int x,int y,int w, int h);
};

class Plane : public GameObject{

public:
	Plane() = default;
	~Plane() = default;
	Plane(int x,int y,int w, int h);
};

class Hole : public GameObject{

public:
	Hole() = default;
	~Hole() = default;
	Hole(int x,int y,int w, int h);
};

class Key : public GameObject{

public:
	Key() = default;
	~Key() = default;
	Key(int x,int y,int w, int h);
};