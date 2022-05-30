#ifndef BOARD_H
#define BOARD_H 

#include <cstddef>//size_t
#include <cstdio>//cout
#include <vector>

#include "car.hpp"

namespace dis
{

class Board
{
    
public:

    friend class Game;
    /**
     * @brief Construct a new Board object
     * 
     * @param a_rows 
     * @param a_columns 
     * @param a_red 
     */
    Board(size_t a_rows, size_t a_columns, act::Car a_red);

    /**
     * @brief Construct a new Board object
     * 
     */
    Board();

    /**
     * @brief Construct a new Board object
     * 
     * @param a_file_name 
     */
    Board(char* a_file_name);



    /**
     * @brief Construct a new Board object
     * 
     * @param a_rows 
     * @param a_columns 
     */
    //Board(size_t a_rows, size_t a_columns); 

    /**
     * @brief Get the rows object
     * 
     * @return size_t 
     */
    size_t get_rows() const;

    /**
     * @brief Get the columns object
     * 
     * @return size_t 
     */
    size_t get_columns() const;

    /**
     * @brief Get the board size object
     * 
     * @return size_t 
     */
    size_t get_board_size() const;

    /**
     * @brief Get the vector object
     * 
     * @return std::vector<char>* 
     */
    std::vector<char>* get_vector() const;

    /**
     * @brief Set the vector object
     * 
     * @param a_vector 
     */
    void set_vector(std::vector<char>* a_vector);

    /**
     * @brief Get the exit index object
     * 
     * @return size_t 
     */
    size_t get_exit_index() const;

    /**
     * @brief Set the rows and columns object
     * 
     * @param a_rows 
     * @param a_columns 
     */
    void set_rows_and_columns(size_t a_rows, size_t a_columns);


    /**
     * @brief print the current board
     * 
     */
    void print_board();

    /**
     * @brief making the board from file information
     * 
     */
    void prepare_board();


    /**
     * @brief check if move legal and call move to move the car if does
     * 
     * @param a_car 
     * @param a_direction 
     * @return true 
     * @return false 
     */
    bool check_if_move_legal_and_move(char a_car, char a_direction);

    /**
     * @brief  move the car if move legal
     * 
     * @param a_car 
     * @param a_direction 
     * @return true 
     * @return false 
     */
    bool move(act::Car* a_car, char a_direction);

    /**
     * @brief recognize which car the user want to move
     * 
     * @param a_car 
     * @return act::Car* 
     */
    act::Car* recognise_car(char a_car);

    /**
     * @brief check if move in legal boarders
     * 
     * @param a_car 
     * @param a_direction 
     * @return true 
     * @return false 
     */
    bool check_if_move_in_boarders(act::Car* a_car, char a_direction);

    
//members
private: 

    size_t m_rows;
    size_t m_columns;
    size_t m_board_size;
    std::vector<char>* m_vector;
    size_t m_exit_index;


    act::Car m_red;
    act::Car m_yellow;
    act::Car m_white;
    act::Car m_orange;
    act::Car m_brown;
    act::Car m_green;

};



}//namespace dis


#endif