#include <vector>

#include "game.hpp"
#include "car.hpp"
#include "game.hpp"


int main()
{
    play::Game new_game;

    char file_name[] = "level 1";
    new_game.play_game(file_name);

    return 0;
}