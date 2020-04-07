#include "obj.h"

Rock::Rock(int x, int y, int w, int h){
	center_x = x;
	center_y = y;
	width = w;
	height = h;
	set_sprite_src("assets/rock.png");
}

Plane::Plane(int x, int y, int w, int h){
	center_x = x;
	center_y = y;
	width = w;
	height = h;
	set_sprite_src("assets/plane.png");
}

Hole::Hole(int x, int y, int w, int h){
	center_x = x;
	center_y = y;
	width = w;
	height = h;
	set_sprite_src("assets/hole.png");
}

Key::Key(int x, int y, int w, int h){
	center_x = x;
	center_y = y;
	width = w;
	height = h;
	set_sprite_src("assets/key.png");
}