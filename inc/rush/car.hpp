#ifndef CAR_H
#define CAR_H 



#include <cstddef> //size_t
#include <cstdio>//cout


#include "car.hpp"

namespace act
{

class Car
{

public:
    /**
     * @brief Construct a new Car object
     * 
     * @param a_length 
     * @param a_direction 
     * @param a_name 
     * @param a_location 
     */
    Car(size_t a_length, bool a_direction, char a_name, size_t a_location);
    
    /**
     * @brief Construct a new Car object
     * 
     * @param a_length 
     * @param a_direction 
     * @param a_name 
     */
    Car(size_t a_length, bool a_direction, char a_name);


    /**
     * @brief Set the location object
     * 
     * @param a_location 
     */
    void set_location(size_t a_location);

    /**
     * @brief Get the location object
     * 
     * @return size_t 
     */
    size_t get_location();

    /**
     * @brief Get the name object
     * 
     * @return char 
     */
    char get_name();

    /**
     * @brief Get the length object
     * 
     * @return size_t 
     */
    size_t get_length();

//members
private: 

    size_t m_length;
    size_t m_direction;
    char m_name;
    size_t m_location;

};

//global functions
/**
 * @brief check if direction legal to a spesific car
 * 
 * @param a_car 
 * @param a_direction 
 * @return true 
 * @return false 
 */
bool check_if_direction_legal(char a_car, char a_direction);


}//namespace act



#endif