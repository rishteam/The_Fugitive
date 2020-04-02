#include "Player.h"

Player::Player(int x, int y, int w, int h){
    center_x = x;
    center_y = y;
    width = w;
    height = h;
}

void Player::init(int x, int y, int w, int h)
{
    center_x = x;
    center_y = y;
    width = w;
    height = h;
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

// void Player::setState()
// {

// }

// Player::State Player::getState()
// {

// }


