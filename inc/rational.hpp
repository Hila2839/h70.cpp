#ifndef RATIONAL_H
#define RATIONAL_H



namespace algebra
{

class Rational 
{    
public:
    /**
     * @brief Construct a new Rational object
     * 
     * @param a_num 
     */
    Rational(int a_num);

    /**
     * @brief Construct a new Rational object
     * 
     * @param a_num 
     * @param a_denom 
     */
    Rational(int a_num, int a_denom);


    /**
     * @brief Get the numerator object
     * 
     * @return int 
     */
   int get_numerator();

   /**
    * @brief Get the denominator object
    * 
    * @return int 
    */
   int get_denominator();

    //two rationals functions

    /**
     * @brief add a rational to self rational
     * 
     * @param a_ratio 
     */
   void add(Rational a_ratio);

   /**
    * @brief substruct a Rational from self rational
    * 
    * @param a_ratio 
    */
   void substruct(Rational a_ratio);


   /**
    * @brief multi self rational by rational
    * 
    * @param a_ratio 
    */
   void multi(Rational a_ratio);


   /**
    * @brief divide rational by givan rational
    * 
    * @param a_ratio 
    */
   void divide(Rational a_ratio);
    
    //one rational and one int functions

    /**
     * @brief add int to self rational
     * 
     * @param a_number 
     */
   void add(int a_number);

   /**
    * @brief substruct int from self rational
    * 
    * @param a_number 
    */
   void substruct(int a_number);


   /**
    * @brief multiply self rational by int
    * 
    * @param a_number 
    */
   void multi(int a_number);

   /**
    * @brief divide rational by givan int
    * 
    * @param a_ratio 
    */
   void divide(int a_number);


  /**
   * @brief reduce a rational
   * 
   */
   void reduce();

   //operators functions
   /**
    * @brief add a rational to self rational
    * 
    * @param a_other 
    */
    //void operator+(Rational a_other);

    /**
     * @brief multi self rational by rational
     * 
     * @param a_other 
     */
    //void operator*(Rational a_other);

    /**
     * @brief divide rational by givan rational
     * 
     * @param a_other 
     */
    //void operator/(Rational a_other);


    /**
     * @brief  substruct rational from self rational
     * 
     * @param a_other 
     */
    //void operator-(Rational a_other);
    


    
private:    
    int m_numerator;
    int m_denominator;
};

/**
 * @brief add two rationals to third rational
 * 
 * @param a_a 
 * @param a_b 
 * @return Rational 
 */
Rational add(Rational a_a, Rational a_b);


/**
 * @brief add a rational and an int to a new rational
 * 
 * @param a_ratio 
 * @param a_number 
 * @return Rational 
 */
Rational add(Rational a_ratio,int a_number);


/**
 * @brief add an int and a rational 
 * 
 * @param a_number 
 * @param a_ratio 
 * @return Rational 
 */
Rational add(int a_number, Rational a_ratio);


Rational multi(Rational a_lhs, Rational a_rhs) ;



Rational divide(Rational a_lhs, Rational a_rhs) ;
 


Rational substruct(Rational a_lhs, Rational a_rhs) ;


/**
 * @brief equal two rationals
 * 
 * @param a_a 
 * @param a_b 
 * @return true 
 * @return false 
 */
bool equal(Rational a_a, Rational a_b);


/**
 * @brief checks if two rationals are equal
 * 
 * @param a_a 
 * @param a_b 
 * @return true 
 * @return false 
 */
bool not_equal(Rational a_a, Rational a_b);


/**
 * @brief checks if two rationals are equal
 * 
 * @param a_lhs 
 * @param a_rhs 
 * @return true 
 * @return false 
 */
bool operator==(Rational a_lhs, Rational a_rhs);


/**
 * @brief checks if two rationals are not equal
 * 
 * @param a_lhs 
 * @param a_rhs 
 * @return true 
 * @return false 
 */
bool operator!=(Rational a_lhs, Rational a_rhs);


/**
 * @brief checks if one rational bigger from another
 * 
 * @param a_bigger 
 * @param a_smaller 
 * @return true 
 * @return false 
 */
bool operator>(Rational a_bigger, Rational a_smaller);

/**
 * @brief  checks if one rational equal or bigger from another
 * 
 * 
 * @param a_bigger 
 * @param a_smaller 
 * @return true 
 * @return false 
 */
bool operator>=(Rational a_bigger, Rational a_smaller);

/**
 * @brief checks if one rational smaller from another
 * 
 * @param a_bigger 
 * @param a_smaller 
 * @return true 
 * @return false 
 */
bool operator<(Rational a_bigger, Rational a_smaller);

/**
 * @brief checks if one rational equal or smaller  from another
 * 
 * @param a_bigger 
 * @param a_smaller 
 * @return true 
 * @return false 
 */
bool operator<=(Rational a_bigger, Rational a_smaller);

/**
 * @brief add two rationals to a new rational
 * 
 * @param a_lhs 
 * @param a_rhs 
 * @return Rational 
 */
Rational operator+(Rational a_lhs, Rational a_rhs);


/**
 * @brief subsruct two rationals to a new rational
 * 
 * @param a_lhs 
 * @param a_rhs 
 * @return Rational 
 */
Rational operator-(Rational a_lhs, Rational a_rhs);


/**
 * @brief multiply two rationals to a new rational
 * 
 * @param a_lhs 
 * @param a_rhs 
 * @return Rational 
 */
Rational operator*(Rational a_lhs, Rational a_rhs);


/**
 * @brief divide two rationals to a new rational
 * 
 * @param a_lhs 
 * @param a_rhs 
 * @return Rational 
 */
Rational operator/(Rational a_lhs, Rational a_rhs);


}//namespace algebra


#endif