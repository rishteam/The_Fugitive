#include "game_object.h"
#include <SFML/Graphics.hpp>

#ifndef Player_H
#define Player_H

class Command;

class InputHandler
{
public:
    InputHandler();
    ~InputHandler();

    Command *handleInput(int id);

private:
    Command *Up_Command;
    Command *Down_Command;
    Command *Left_Command;
    Command *Right_Command;
};

class Player : public GameObject{

protected:
    int id = 0;
    int pre_x = 0, pre_y = 0;
    InputHandler *inputhandler;
    enum class State
    {
        STATE_STANDING,
        STATE_JUMPING,
        STATE_DUCKING,
    } state;

public:
    Player() = default;
    Player(int x, int y, int w, int h);
    virtual void init(int x, int y, int w, int h, int id_);
    void setState();
    int getid();
    void storePos();
    void releasePos();
    void move_left(int dis);
    void move_right(int dis);
    void move_up(int dis);
    void move_down(int dis);
    void handle_input();
    void update_imgui_parameter();
    float imgui_x,imgui_y;

    // void setState();
    // State getState()
};

#endif