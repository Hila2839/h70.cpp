#include <vector>
#include <iostream>
#include <cassert>
#include <fstream>

#include "game.hpp"
#include "car.hpp"
#include "game.hpp"


int main(int argc, char* argv[])
{
    play::Game new_game;
    
    
    new_game.play_game(argv[1]);

    return 0;
}