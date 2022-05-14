#include <cstdio>
#include <cassert>
#include <cmath>

#include "quadratic.hpp"
#include "rational.hpp"



namespace algebra
{

Quadratic::Quadratic(algebra::Rational a_a, algebra::Rational a_b, algebra::Rational a_c)
:m_a(a_a)
, m_b(a_b)
, m_c(a_c)
 {
     assert(a_a != 0 && "a can't be zero"); 
 }               

 void Quadratic::print()
 {
     printf("%d/%d x^2 + %d/%d x + %d/%d ",
        m_a.get_numerator(), m_a.get_denominator(), m_b.get_numerator(),
        m_b.get_denominator(),m_c.get_numerator(), m_c.get_denominator());
 }

void Quadratic::root(Roots *a_struct)
 {
    int x_1_denum = 0;
    int x_1_num = 0;
    int x_2_denum = 0;
    int x_2_num = 0;
    double a =  m_a.get_numerator() / m_a.get_denominator();
    double b =  m_b.get_numerator() / m_b.get_denominator();
    double c =  m_c.get_numerator() / m_c.get_denominator();

   double temp = sqrt(b * b - (4 * a * c )) ;
    if (temp >0)
    {     
    x_1_num = -b + temp;
    x_1_denum = 2 * a;

    x_2_num = -b - temp;
    x_2_denum = 2 * a;
    }   

    else if (temp ==  0)
    {
    x_1_num = x_2_num = -b ;
    x_1_denum = x_2_denum = 2* a;
    }
   // a_struct->m_root_1 = algebra::Rational(x_1_num, x_1_denum);
    //a_struct->m_root_2= algebra::Rational(x_2_num, x_2_denum);
    a_struct->m_root_1 = 2;
    printf("x 1 = %d/%d",  x_1_num ,x_1_denum );
    printf("x 2 = %d/%d",  x_2_num ,x_2_denum );
    //else
    //print the results are complex numbers"
   
 }



 void Quadratic::multi(int a_number)
 {
     m_a.multi(a_number);
     m_b.multi(a_number);
     m_c.multi(a_number);
 }


void Quadratic::multi(algebra::Rational a_ratio)
{
    m_a.multi(a_ratio);
    m_b.multi(a_ratio);
    m_c.multi(a_ratio);
}
    
algebra::Rational Quadratic::get_coefficient(int degree)
{
    if(degree == 3)
    {
        return algebra::Rational(m_a.get_numerator(),  m_a.get_denominator());
    }

    if(degree == 2)
    {
        return algebra::Rational(m_b.get_numerator(),  m_b.get_denominator());
    }

    if(degree == 1)
    {
        return algebra::Rational(m_c.get_numerator(),  m_c.get_denominator());
    } 
}

/*not a true function! do i neet it??
Quadratic Quadratic::multi(Quadratic a_a_pulynom, Quadratic a_b_pulynom)
{
    int a_numerator = a_a_pulynom.m_a.get_numerator() * a_b_pulynom.m_a.get_numerator();
    int a_ndenominator = a_a_pulynom.m_a.get_denominator() * a_b_pulynom.m_a.get_denominator();

    int b_numerator = a_a_pulynom.m_b.get_numerator() * a_b_pulynom.m_b.get_numerator();
    int b_ndenominator = a_a_pulynom.m_b.get_denominator() * a_b_pulynom.m_b.get_denominator();

    int c_numerator = a_a_pulynom.m_c.get_numerator() * a_b_pulynom.m_c.get_numerator();
    int c_ndenominator = a_a_pulynom.m_c.get_denominator() * a_b_pulynom.m_c.get_denominator();


    return Quadratic(algebra::Rational a(a_numerator, a_ndenominator), 
    algebra::Rational b(b_numerator, b_ndenominator), 
    algebra::Rational c(c_numerator, c_ndenominator));
}
not a true function! do i neet it??*/

Quadratic add(Quadratic a_a_pulynom, Quadratic a_b_pulynom)
{
    algebra::Rational a =add( a_a_pulynom.get_coefficient(3), a_b_pulynom.get_coefficient(3));
    algebra::Rational b =add( a_a_pulynom.get_coefficient(2), a_b_pulynom.get_coefficient(2));
    algebra::Rational c =add( a_a_pulynom.get_coefficient(1), a_b_pulynom.get_coefficient(1));

    return Quadratic(a,b,c);
}

}//namespace algebra
