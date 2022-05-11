#include <cstdio>
#include <cassert>
#include "rational.hpp"

namespace implementation_details
{


void common_denominator(int* a_a, int* a_b)
{
    int keep = *a_a;
    *a_a *= *a_b;
    *a_b *= keep;
}


}//namespace implementation_details


namespace algebra
{

Rational::Rational(int a_num)
: m_numerator(a_num)               
, m_denominator(1)
{    
}

Rational::Rational(int a_num, int a_denom)
: m_numerator(a_num)               
, m_denominator(a_denom)
{
    assert(m_denominator != 0 && "denom can't be zero");       
}


void Rational::add(Rational a_ratio) 
{
    if(m_denominator == a_ratio.m_denominator)
    {
        m_numerator += a_ratio.m_numerator;
    }
    else
    {
        m_numerator *= a_ratio.m_denominator;
        a_ratio.m_numerator *= m_denominator;
        m_numerator += a_ratio.m_numerator;
        implementation_details::common_denominator(&m_denominator , &a_ratio.m_denominator);
        
    }
}


void Rational::substruct(Rational a_ratio) 
{
    if(m_denominator == a_ratio.m_denominator)
    {
        m_numerator  -= a_ratio.m_numerator ;
    }
    else
    {
        m_numerator  *= a_ratio.m_denominator;
        a_ratio.m_numerator  *= m_denominator;
        m_numerator  -= a_ratio.m_numerator ;
         implementation_details::common_denominator(&m_denominator , &a_ratio.m_denominator);
    }
}



void Rational::multi(Rational a_ratio) 
{
    this->m_numerator = this->m_numerator * a_ratio.m_numerator;
    this->m_denominator = this->m_denominator * a_ratio.m_denominator;
}

void Rational::divide(Rational a_ratio) 
{
    int keep = a_ratio.m_numerator;
    a_ratio.m_numerator = a_ratio.m_denominator;
    a_ratio.m_denominator = keep;
    this->m_numerator = this->m_numerator * a_ratio.m_numerator;
    this->m_denominator = this->m_denominator * a_ratio.m_denominator;
}

void Rational::add(int a_number)
{
    a_number *= m_denominator;
    m_numerator += a_number;
}


void Rational::substruct(int a_number)
{
    a_number *= m_denominator;
    m_numerator -= a_number;
}


void Rational::multi(int a_number)
{
    m_numerator = a_number * m_numerator; 
}


void Rational::divide(int a_number)
{
    m_denominator *= a_number;
}



void Rational::reduce()
{
    int smallest = m_numerator ;
    if(m_numerator >  m_denominator)
    {
        smallest = m_denominator;
    }
    for (int i =  smallest; i >= 2 ; --i)
    {
        if(m_numerator % i == 0 && m_denominator % i == 0)
        {
            m_numerator /= i; 
            m_denominator /= i;
        }
        
    }
}



 int Rational::get_numerator()
 {
     return m_numerator;
 }

 int Rational::get_denominator()
 {
     return m_denominator;
 }



 Rational add(Rational a_a, Rational a_b)
 {
     int numerator = 0;
     int denominator = 0;
    if(a_a.get_denominator() == a_b.get_denominator())
    {
        numerator = a_a.get_numerator() + a_b.get_numerator();
        denominator = a_a.get_denominator();
    }
    else
    {
        numerator = a_a.get_numerator() * a_b.get_denominator();
        numerator += a_b.get_numerator() * a_a.get_denominator();
        denominator = a_a.get_denominator() * a_b.get_denominator();
    }
    return Rational(numerator, denominator );
 }

 bool equal(Rational a_a, Rational a_b)
 {
    a_a.reduce();
    a_b.reduce();
    if(a_a.get_numerator() != a_b.get_numerator())
    {
        return false;
    }
    if(a_b.get_denominator() != a_a.get_denominator())
    {
        return false;
    }
    return true;

 }

 bool not_equal(Rational a_a, Rational a_b)
 {
    a_a.reduce();
    a_b.reduce();
    if(a_a.get_numerator() == a_b.get_denominator() && a_b.get_numerator() == a_a.get_denominator())
    {
        return false;
    }
    return true;

 }

}//namespace algebra
