#include "Command.h"

void UpCommand::execute(Player &player)
{
    player.move_up(MOVE_UNIT);
}

void DownCommand::execute(Player &player)
{
    player.move_down(MOVE_UNIT);
}

void LeftCommand::execute(Player &player)
{
    player.move_left(MOVE_UNIT);
}

void RightCommand::execute(Player &player)
{
    player.move_right(MOVE_UNIT);
}
