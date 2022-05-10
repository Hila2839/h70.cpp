#ifndef RATIONAL_H
#define RATIONAL_H

class Rational 
{    
public:
    Rational(int a_num);
    Rational(int a_num, int a_denom);

   int get_numerator();
   int get_denominator();

    //two rationals functions
   void add(Rational a_ratio);
   void substruct(Rational a_ratio);
   void multi(Rational a_ratio);
   void divide(Rational a_ratio);
    
    //one rational and one int functions
   void add(int a_number);
   void substruct(int a_number);
   void multi(int a_number);
   void divide(int a_number);

   void reduce();

    
private:    
    int m_numerator;
    int m_denominator;
};


#endif