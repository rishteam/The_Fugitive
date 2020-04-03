#pragma once
#include "game_object.h"

class Player : public GameObject{

protected:
    int id = 0;
    int pre_x = 0;
    int pre_y = 0;
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
    // void setState();
    // State getState()
};