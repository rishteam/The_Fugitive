#pragma once
#include "game_object.h"

class Player : public GameObject{

protected:
    enum class State
    {
        STATE_STANDING,
        STATE_JUMPING,
        STATE_DUCKING,
    } state;

public:
    Player() = default;
    Player(int x, int y, int w, int h);
    virtual void init(int x, int y, int w, int h);
    void setState();
    void move_left(int dis);
    void move_right(int dis);
    void move_up(int dis);
    void move_down(int dis);
    void handleInput(sf::Event event, int move_unit, int id);
    // void setState();
    // State getState()
};