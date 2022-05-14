#ifndef QUATRIC_H
#define QUATRIC_H 

#include "rational.hpp"



namespace algebra
{

struct Roots
{
    int m_root_1;
    int m_root_2;
    int m_roots_num;
};


class Quadratic
{
public:
    /**
     * @brief Construct a new Quadratic object
     * 
     * @param a_a 
     * @param a_b 
     * @param a_c 
     */
    Quadratic(algebra::Rational a_a, algebra::Rational a_b, algebra::Rational a_c);

    /**prints a quadratic
     * @brief 
     * 
     */
    void print();


    /**
     * @brief multi a quadratic by int
     * 
     * @param a_number 
     */
    void multi(int a_number);


    /**
     * @brief  multi a quadratic by Rational
     * 
     * @param a_ratio 
     */
    void multi(algebra::Rational a_ratio);


    /**
     * @brief Get the coefficient object
     * 
     * @param degree 
     * @return algebra::Rational 
     */
    algebra::Rational get_coefficient(int degree);


    /**
     * @brief compute the quadratic roots
     * 
     * @param a_struct 
     * @return void
     */
    void root(algebra::Roots *a_struct);


private:
    algebra::Rational m_a;
    algebra::Rational m_b;
    algebra::Rational m_c; 
};

/**
 * @brief add two quadratics to a new quadratic
 * 
 * @param a_a_pulynom 
 * @param a_b_pulynom 
 * @return Quadratic 
 */
Quadratic add(Quadratic a_a_pulynom, Quadratic a_b_pulynom);

}//namespace algebra

#endif