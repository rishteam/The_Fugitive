#include <iostream>

#include "Game.h"


int main()
{
    // Start the game loop
    Game game;
    while (true)
    {
        game.run();
    }
    return EXIT_SUCCESS;
}
