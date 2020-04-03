#include "obj.h"

Rock::Rock(int x, int y, int w, int h){
	center_x = x;
	center_y = y;
	width = w;
	height = h;
	set_sprite_src("assets/rock.png",80,80);
}

Plane::Plane(int x, int y, int w, int h){
	center_x = x;
	center_y = y;
	width = w;
	height = h;
	set_sprite_src("assets/plane.png",80,80);
}

Hole::Hole(int x, int y, int w, int h){
	center_x = x;
	center_y = y;
	width = w;
	height = h;
	set_sprite_src("assets/hole.png",80,80);
}

Key::Key(int x, int y, int w, int h){
	center_x = x;
	center_y = y;
	width = w;
	height = h;
	set_sprite_src("assets/key.png",80,80);
}