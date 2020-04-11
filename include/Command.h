#define MOVE_UNIT 10

#ifndef Command_H
#define Command_H

#include "Player.h"


class Command
{

public:
    virtual ~Command() {}
    virtual void execute(Player &player) = 0;
};

class UpCommand : public Command
{

public:
    virtual void execute(Player &player) override;
};

class DownCommand : public Command
{

public:
    virtual void execute(Player &player) override;
};

class LeftCommand : public Command
{

public:
    virtual void execute(Player &player) override;
};

class RightCommand : public Command
{

public:
    virtual void execute(Player &player) override;
};

#endif