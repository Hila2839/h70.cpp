#include <cstdio>
#include <cassert>
#include "rational.hpp"

namespace implementation_details
{


void common_denominator(int* a_lhs, int* a_rhs)
{
    int keep = *a_lhs;
    *a_lhs *= *a_rhs;
    *a_rhs *= keep;
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
    if(a_denom < 0)
    {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }    
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
    m_numerator = m_numerator * a_ratio.m_numerator;
    m_denominator = m_denominator * a_ratio.m_denominator;
    
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



 Rational add(Rational a_lhs, Rational a_rhs)
 {
     int numerator = 0;
     int denominator = 0;
    if(a_lhs.get_denominator() == a_rhs.get_denominator())
    {
        numerator = a_lhs.get_numerator() + a_rhs.get_numerator();
        denominator = a_lhs.get_denominator();
    }
    else
    {
        numerator = a_lhs.get_numerator() * a_rhs.get_denominator();
        numerator += a_rhs.get_numerator() * a_lhs.get_denominator();
        denominator = a_lhs.get_denominator() * a_rhs.get_denominator();
    }
    return Rational(numerator, denominator );
 }



Rational add(Rational a_ratio,int a_number)
 {
    int denominator = a_ratio.get_denominator();
    int numerator = a_ratio.get_numerator() +  a_ratio.get_denominator() * a_number;
    return Rational(numerator, denominator );
 }


Rational add(int a_number, Rational a_ratio)
 {
    int denominator = a_ratio.get_denominator();
    int numerator = a_ratio.get_numerator() +  a_ratio.get_denominator() * a_number;
    return Rational(numerator, denominator );
 }

Rational multi(Rational a_lhs, Rational a_rhs) 
{
    int numerator = a_lhs.get_numerator() * a_rhs.get_numerator();
    int denominator  = a_lhs.get_denominator() * a_rhs.get_denominator();
    return Rational(numerator, denominator );
    
}


/*Rational divide(Rational a_lhs, Rational a_rhs) 
{
    int numerator = 0;
    int denominator = 0;
    int keep = a_rhs.get_numerator();
    a_rhs.get_numerator() = a_rhs.get_denominator();
    a_rhs.get_denominator() = keep;
    numerator = a_lhs.get_numerator() * a_rhs.get_numerator();
    denominator = a_lhs.get_denominator() * a_rhs.get_denominator();
    return Rational(numerator, denominator );
}*/

Rational substruct(Rational a_lhs, Rational a_rhs) 
{
    int numerator = 0;
    int denominator = 0;
    if(a_lhs.get_denominator() == a_rhs.get_denominator())
    {
        numerator = a_lhs.get_numerator() - a_rhs.get_numerator();
        denominator = a_lhs.get_denominator();
    }
    else
    {
        numerator = a_lhs.get_numerator() * a_rhs.get_denominator();
        numerator -= a_rhs.get_numerator() * a_lhs.get_denominator();
        denominator = a_lhs.get_denominator() * a_rhs.get_denominator();
    }
    return Rational(numerator, denominator );
}

 bool equal(Rational a_lhs, Rational a_rhs)
 {
    a_lhs.reduce();
    a_rhs.reduce();
    if(a_lhs.get_numerator() != a_rhs.get_numerator())
    {
        return false;
    }
    if(a_rhs.get_denominator() != a_lhs.get_denominator())
    {
        return false;
    }
    return true;

 }

 bool not_equal(Rational a_lha, Rational a_rhs)
 {
    return !equal(a_lha, a_rhs);
 }


//out class (global) operators functions

bool operator==(Rational a_lhs, Rational a_rhs)
{
    return equal(a_lhs, a_rhs);// need two arguments!??!
}


bool operator!=(Rational a_lhs, Rational a_rhs)
{
    return not_equal(a_lhs, a_rhs);// need two arguments!??!
}


bool operator>(Rational a_bigger, Rational a_smaller)
{
   a_bigger.substruct(a_smaller);
   if(a_bigger.get_numerator() > 0)
    {
       return true;
    }
    return false;
}

bool operator>=(Rational a_bigger, Rational a_smaller)
{
   a_bigger.substruct(a_smaller);
   if(a_bigger.get_numerator() >= 0)
    {
       return true;
    }
    return false;
}

bool operator<(Rational a_smaller, Rational a_bigger)
{
   a_bigger.substruct(a_smaller);
   if(a_bigger.get_numerator() > 0)
    {
       return true;
    }
    return false;
}

bool operator<=(Rational a_smaller, Rational a_bigger)
{
   a_bigger.substruct(a_smaller);
   if(a_bigger.get_numerator() >= 0)
    {
       return true;
    }
    return false;
}

Rational operator+(Rational a_lhs, Rational a_rhs)
{
    return add(a_lhs, a_rhs);
}


Rational operator*(Rational a_lhs, Rational a_rhs)
{
    return multi(a_lhs, a_rhs);
}


/*Rational operator/(Rational a_lhs, Rational a_rhs)
{
    return divide(a_lhs, a_rhs);
}*/


Rational operator-(Rational a_lhs, Rational a_rhs)
{
    return substruct(a_lhs, a_rhs);
}


//in class operators functions
/*
void Rational::operator+(Rational a_other)
{
    add(a_other);
}


void Rational::operator*(Rational a_other)
{
    multi(a_other);
}


void Rational::operator/(Rational a_other)
{
    divide(a_other);
}


void Rational::operator-(Rational a_other)
{
    substruct(a_other);
}

/*void Rational::operator++()
{
   m_numerator += m_denominator;
}*/









}//namespace algebra
