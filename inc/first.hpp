#ifndef FIRST_H
#define FIRST_H

// #include <stddef.h>
#include <cstddef>
enum mono {MONO_INCREASING, MONO_STRICLY_INCREASING, MONO_DECREASING, 
MONO_STRICLY_DECREASING, MONO_ERROR, MONO_NOT_MONO};

/**
 * @brief check if a_needle is in the a_haystack
 * complixity O(n)
 * @param a_haystack pointewr to an array of int
 * @param a_size size of array a_haystack
 * @param a_needle what we look for
 * @return int 0 if a_nnedle not found, 1 otherwise
 */
bool find(int const *a_haystack,  size_t a_size, int a_needle);

bool findRec(int const *a_haystack,  size_t a_size, int a_needle);

/*
test will null
test with size = 0
test for x in last element, first element, somewhere in the between
test for x not in array
test that the function doesn' access elements out of range [0..a_size)
*/
// implement find_r like find but recursive


int FindHowManyBitesOnLong(unsigned  long _lon);

/**
 * @brief check if a number is in array, returns location index
 * 
 * @param a_array pointewr to an array of int
 * @param a_size size of array
 * @param a_num what we look for
 * @return size_t of index where int was found in array, -1 if not found
 */
size_t FindIndex(int const *a_array,  size_t a_size, int a_num);
size_t binarySearch(int const *a_array,  size_t a_size, int a_num);

int add(int a, int b);
int half(int a);
bool is_odd(int a);
int multi(int a, int b);
bool isEven(int a_num);
char CalcBitOnLong(long a_num);
mono monoticity(const float *a_array, size_t a_size);
bool isEven(int a_num);
size_t* prime_factors(unsigned long a_number);


#endif