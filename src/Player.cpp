#include "Player.h"
#include "Command.h"


Player::Player(int x, int y, int w, int h){
    center_x = x;
    center_y = y;
    width = w;
    height = h;
    inputhandler = new InputHandler();
}

void Player::init(int x, int y, int w, int h, int id_)
{
    center_x = x;
    center_y = y;
    width = w;
    height = h;
    id = id_;
    inputhandler = new InputHandler();
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

InputHandler::InputHandler()
{
    Up_Command = new UpCommand();
    Down_Command = new DownCommand();
    Left_Command = new LeftCommand();
    Right_Command = new RightCommand();
}

InputHandler::~InputHandler()
{
    delete Up_Command;
    delete Down_Command;
    delete Left_Command;
    delete Right_Command;
}

// use command pattern
Command *InputHandler::handleInput(int id)
{
    switch (id)
    {
        case 1:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                return Up_Command;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                return Down_Command;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                return Left_Command;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                return Right_Command;
            break;
        case 2:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                return Up_Command;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                return Down_Command;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                return Left_Command;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                return Right_Command;
            break;
    }
    return nullptr;
}

void Player::handle_input()
{
    Command *cmd = inputhandler->handleInput(this->getid());
    if (cmd)
        cmd->execute(*this);
}
