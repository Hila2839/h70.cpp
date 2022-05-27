#ifndef GAME_H
#define GAME_H 


#include <cstddef>//size_t
#include <cstdio>//cout

#include "board.hpp"
#include "game.hpp"


namespace play
{

class Game
{
    
public:
    /**
     * @brief Construct a new Game object
     * 
     */
    Game();
    
    /**
     * @brief start the game
     * 
     * @param a_file_name - the current level
     */
    void play_game(char* a_file_name);

    /**
     * @brief terminate the game in a case of winning
     * 
     */
    void end_game();
    

    /**
     * @brief moves the car if all parameters are legal
     * 
     * @return true 
     * @return false 
     */
    bool move_car();

    /**
     * @brief disply the game board
     * 
     * @param a_board 
     */
    void disply_board(dis::Board a_board);

    /**
     * @brief Get the board object
     * 
     * @return dis::Board 
     */
    dis::Board get_board();

    /**
     * @brief Set the board object
     * 
     * @param a_board 
     */
    void set_board(dis::Board a_board);

    /**
     * @brief call board function to check if move is legal
     * 
     * @param a_car 
     * @param a_direction 
     */
    void a_move(char a_car, char a_direction);

//members
private: 

    dis::Board m_board;

};



}//namespace play


#endif