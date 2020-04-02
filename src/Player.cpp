#include "Player.h"
#include <iostream>
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

void Player::handleInput(sf::Event event, int move_unit, int id)
{
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            if(id == 1)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    move_left(move_unit);
                    std::cout << "hit" << '\n';
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    move_right(move_unit);
                    std::cout << "hit" << '\n';
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    move_up(move_unit);
                    std::cout << "hit" << '\n';
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    move_down(move_unit);
                    std::cout << "hit" << '\n';
                }
            }
            if(id == 2)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    move_left(move_unit);
                    std::cout << "hit2" << '\n';
                }
                else if (event.key.code == sf::Keyboard::D)
                {
                    move_right(move_unit);
                    std::cout << "hit2" << '\n';
                }
                else if (event.key.code == sf::Keyboard::W)
                {
                    move_up(move_unit);
                    std::cout << "hit2" << '\n';
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    move_down(move_unit);
                    std::cout << "hit2" << '\n';
                }
            }
    }
}

// void Player::setState()
// {

// }

// Player::State Player::getState()
// {

// }


