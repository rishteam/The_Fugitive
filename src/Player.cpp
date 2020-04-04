#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Player::Player(int x, int y, int w, int h){
    center_x = x;
    center_y = y;
    width = w;
    height = h;
}

void Player::init(int x, int y, int w, int h, int id_)
{
    center_x = x;
    center_y = y;
    width = w;
    height = h;
    id = id_;
}

void Player::storePos()
{
    pre_x = center_x;
    pre_y = center_y;
}

void Player::releasePos()
{
    center_x = pre_x;
    center_y = pre_y;
}

int Player::getid()
{
    return id;
}

void Player::move_left(int dis)
{
    center_x -= dis;
}

void Player::move_right(int dis)
{
    center_x += dis;
}

void Player::move_up(int dis)
{
    center_y -= dis;
}

void Player::move_down(int dis)
{
    center_y += dis;
}

void Player::update_imgui_parameter()
{
    imgui_x = center_x;
    imgui_y = center_y;
}

// void Player::setState()
// {

// }

// Player::State Player::getState()
// {

// }
