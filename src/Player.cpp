#include "../inc/Player.h"

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

void Player::setSex(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        sex = Sex::MALE;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        sex = Sex::FEMALE;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        sex = Sex::OTHER;
    }
}

Player::Sex Player::getSex()
{
    return sex;
}


