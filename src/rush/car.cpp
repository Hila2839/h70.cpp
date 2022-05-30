#include <cassert>

#include "car.hpp"

namespace act
{

Car::Car(char a_name,  size_t a_direction, size_t a_length, size_t a_location)
: m_length(a_length)
, m_direction(a_direction)
, m_name(a_name)
, m_location(a_location)
{
    assert(a_length > 0 && "invalid car length");
}

Car::Car(size_t a_length, bool a_direction, char a_name)
: m_length(a_length)
, m_direction(a_direction)
, m_name(a_name)
{
}

Car::Car()
: m_length(0)
, m_direction(0)
, m_name('0')
{
}

void Car::set_location(size_t a_location)
{
    m_location = a_location;
}
/*
void Car::set_direction(size_t a_direction)
{
    m_direction = a_direction;
}

void Car::set_length(size_t a_length)
{
    m_length = a_length;
}

void Car::set_name(char a_name)
{
    m_name = a_name;
}

*/
size_t Car::get_location()
{
    return m_location;
}


char Car::get_name()
{
    return m_name;
}


size_t Car::get_length()
{
    return m_length;
}



bool check_if_direction_legal(char a_car, char a_direction)
{
     if(a_car == 'w' || a_car == 'r' || a_car == 'o' || a_car == 'g')
     {
         if(a_direction == 'r' || a_direction == 'l')
         {
             return true;
         }
         else
         {
            printf("this car cant move to this direction. please try again\n");
            return false;
         }
     }
     else if(a_car == 'y' || a_car == 'b' )
     {
         if(a_direction == 'u' || a_direction == 'd')
         {
             return true;
         }
         else
         {
            printf("this car cant move to this direction. please try again\n");
            return false;
         }
     }
     else
     {
         printf("car name is wrong. please try again\n");
         return false;
     }
 }





}//namespace act