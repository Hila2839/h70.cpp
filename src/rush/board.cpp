#include <cstddef>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <fstream>

#include "board.hpp"
#include "car.hpp"

namespace dis
{

void Board::print_board()
{
    std::cout<<m_rows<<'\n';
    std::cout<<m_columns<<'\n';

    for(size_t i = 0; i < m_rows ; i++)
    {
        std::cout << "___________________________________________"<<'\n';
    for (size_t j = 0; j < m_columns; j++)
    {
       std::cout << "|  "<< m_vector->at(i * m_columns + j)<<"  ";
       
    }
    std::cout<<"|\n";
    }
    std::cout << "___________________________________________"<<'\n';
    
}


Board::Board(size_t a_rows, size_t a_columns)
: m_rows(a_rows)
, m_columns(a_columns)
, m_board_size(m_rows * m_columns)
, m_red(2, 1, 'r')
, m_yellow(2, 0, 'y')
, m_white(2, 1, 'w')
, m_orange(2, 1, 'o')
, m_brown(2, 0, 'b')
, m_green(2, 1, 'g')
{
    m_vector =  new std::vector<char>[1];
    m_exit_index = 27;
}



void Board::set_rows_and_columns(size_t a_rows, size_t a_columns)
{
    m_rows = a_rows;
    m_columns = a_columns;
}


size_t Board::get_rows() const
{
    return m_rows;
}


size_t Board::get_columns() const
{
    return m_columns;
}


size_t Board::get_board_size() const
{
    return m_board_size;
}


std::vector<char>* Board::get_vector() const
{
    return m_vector;
}


void Board::set_vector(std::vector<char>* a_vector) 
{
    m_vector = a_vector;
}


size_t Board::get_exit_index() const
{
    return m_exit_index;
}


Board read_level_from_file(const char* a_file_name)
{
   std::ifstream file_name(a_file_name);
   assert(file_name.is_open() && "failed to open a new file");

   int rows = 0, columns = 0;

   file_name >> rows >> columns;

    Board from_file(rows, columns);

    char ch;
    for (size_t i = 0; i < from_file.get_board_size(); ++i)
    {
            file_name >> ch;
            from_file.get_vector()->push_back(ch);
    }
    file_name.close();
    return from_file;
}


void Board::prepare_board()
{
    
    int flag_r = 0, flag_y = 0, flag_w = 0, flag_o = 0, flag_b = 0, flag_g = 0;
    for (size_t i = 0; i < m_board_size; i++)
    {
        if(m_vector->at(i) != '_')
        {
            if(m_vector->at(i) == 'r' && flag_r == 0)
            {
                m_red.set_location(i);
                flag_r = 1;
            }
            if(m_vector->at(i) == 'y' && flag_y == 0)
            {
                m_yellow.set_location(i);
                flag_y = 1;
            }
            if(m_vector->at(i) == 'w' && flag_w == 0)
            {
                m_white.set_location(i);
                flag_w = 1;
            }
            if(m_vector->at(i) == 'o' && flag_o == 0)
            {
                m_orange.set_location(i);
                flag_o = 1;
            }
            if(m_vector->at(i) == 'b' && flag_b == 0)
            {
                m_brown.set_location(i);
                flag_b = 1;
            }
            if(m_vector->at(i) == 'g' && flag_g == 0)
            {
                m_green.set_location(i);
                flag_g = 1;
            }
        }
    }
}




bool Board::check_if_move_legal_and_move(char a_car, char a_direction)
{
    bool car_valid = act::check_if_direction_legal(a_car, a_direction);
     if (car_valid == false)
     {
         return false;
     }

    act::Car* car = recognise_car(a_car);
     if (check_if_move_in_boarders(car, a_direction) == false)
     {
         return false;
     }
     bool accident = move(car, a_direction);
    if (accident == false)
     {
         return false;
     }

    return true;  
}



act::Car* Board::recognise_car(char a_car)
{
    if (a_car == 'w')
    {
        return &m_white;
    }
    else if (a_car == 'g')
    {
        return &m_green;
    }
    else if (a_car == 'b')
    {
        return &m_brown;
    }
    else if (a_car == 'o')
    {
        return &m_orange;
    }
    else if (a_car == 'y')
    {
        return &m_yellow;
    }
    else
    {
        return &m_red;
    }
    
}



bool Board::check_if_move_in_boarders(act::Car* a_car, char a_direction)
{
    if (a_direction == 'l')
    {
        for (size_t i = 0; i < m_board_size - 1; i += m_rows)
        {
            if(a_car->get_location() == i)
            {
                printf("you are about to fall of a cliff...please try other direction\n");
                return false;
            }
            
        }
        return true;
    }
    if (a_direction == 'r')
    {
        for (size_t i = m_rows - 1; i < m_board_size - 1; i+= m_rows)
        {
            if(a_car->get_location() + a_car->get_length() - 1 == i)
            {
                printf("you are about to fall of a cliff...please try other direction\n");
                return false;
            }
        }
        return true;
        
    }
    if (a_direction == 'u')
    {
        for (size_t i = 0; i < m_rows - 1; ++i)
        {
            if(a_car->get_location() == i)
            {
                printf("you are about to fall of a cliff...please try other direction\n");
                return false;
            }
        }
        return true;
    }
    if (a_direction == 'd')
    {
        for (size_t i = (m_rows - 1) * m_columns ; i < m_board_size - 1; ++i)
        {
            if (a_car->get_location() + (a_car->get_length()- 1) * m_rows == i)
            {
                printf("you are about to fall of a cliff...please try other direction\n");
                return false;
            }
        }
        return true;
    }
    else
    {
        printf("invalid direction, try again\n");
        return false;
    }  
}



bool Board::move(act::Car* a_car, char a_direction)
{
    if (a_direction == 'l')
    {
        if(m_vector->at(a_car->get_location() - 1) == '_' || m_vector->at(a_car->get_location() - 1) == 'E')
        {
            a_car->set_location(a_car->get_location() - 1);
            m_vector->at(a_car->get_location() + a_car->get_length() ) = '_';
            m_vector->at(a_car->get_location() ) = a_car->get_name();
            return true;
        }
        else
        {
            printf("oops..there will be a car accident if you go there... please choose other direction\n");
            return false;
        }
        
    }
    else if (a_direction == 'r')
    {
        if( m_vector->at(a_car->get_location() + a_car->get_length() )  == '_'
                || m_vector->at(a_car->get_location() + a_car->get_length() )  == 'E')
        {
            a_car->set_location(a_car->get_location() + 1);
            m_vector->at(a_car->get_location() + a_car->get_length() - 1) = a_car->get_name();
            m_vector->at(a_car->get_location() - 1) = '_';
            return true;
        }
        else
        {
            printf("oops..there will be a car accident if you go there... please choose other direction\n");
            return false;
        }
        
    }
    else if (a_direction == 'u')
    {
        if(m_vector->at(a_car->get_location() - m_rows)  == '_' || m_vector->at(a_car->get_location() - m_rows)  == 'E')
        {
            a_car->set_location(a_car->get_location() - m_rows);
            m_vector->at(a_car->get_location() + (a_car->get_length() ) * m_rows) = '_';
            m_vector->at(a_car->get_location()) = a_car->get_name();
            return true;
        }
        else
        {
            printf("oops..there will be a car accident if you go there... please choose other direction\n");
            return false;
        }
        
    }
    else if (a_direction == 'd')
    {
        if(m_vector->at(a_car->get_location() + (a_car->get_length()) * m_rows) == '_'
                    || m_vector->at(a_car->get_location() + (a_car->get_length()) * m_rows) == 'E')
        {
            a_car->set_location(a_car->get_location() + m_rows);
            m_vector->at(a_car->get_location() - (a_car->get_length() - 1) * m_rows) = '_';
            m_vector->at(a_car->get_location() + (a_car->get_length() - 1) * m_rows) = a_car->get_name();
            return true;
        }
        else
        {
            printf("oops..there will be a car accident if you go there... please choose other direction\n");
            return false;
        }
        
    }
    else
    {
        printf("you entered invalid direction, please try again\n");
        return false;
    }
}


}//namespace dis