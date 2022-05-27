#include <cstdio>//cout
#include <iostream>
#include <cstdlib>

#include "board.hpp" 
#include "game.hpp"



namespace play
{

//constructor
Game::Game()
: m_board(7, 7)
{
}


//get members
void Game::disply_board(dis::Board a_board)
{
    a_board.print_board();
}



dis::Board Game::get_board()
{
    return m_board;
}



void Game::set_board(dis::Board a_board)
{
    m_board = a_board;
}


void Game::a_move(char a_car, char a_direction)
{
    m_board.check_if_move_legal_and_move(a_car, a_direction);
    
}


void Game::end_game()
{
    printf("you won!!!\n");
}



//game functions
void Game::play_game(char* a_file_name)
{
    set_board(dis::read_level_from_file(a_file_name));

    m_board.prepare_board();

    play::Game::disply_board(m_board);
    while (true)
    {
        bool is_move = move_car();
        if(is_move == true)
        {
             play::Game::disply_board(m_board);
        } 
        if (m_board.get_vector()->at(m_board.get_exit_index()) != 'E')
        {
            break;
        }
        
    }
    end_game();
    
}


bool Game::move_car()
{
    char car; 
    char direction;
    std::cout<<"if you want to exit press ! \n";
    std::cout<<"enter a car name:";
    scanf("%s", &car);

    if(car == '!')
    {
        exit(0);
    }

    std::cout<<"enter the direction you want to move the car:";
    scanf("%s", &direction);
    
    if(m_board.check_if_move_legal_and_move(car, direction) == true)
    {
        return true;
    }
    return false;
}




}//namespace play
