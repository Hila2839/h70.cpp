#include "mu_test.h"

#include "first.hpp"

/*-----------------------------------find tests-----------------------------*/

BEGIN_TEST(find_x_begin)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 1;
    int r = find(array, 8, x);

	ASSERT_THAT( r == true);
END_TEST

BEGIN_TEST(find_x_end)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 4;
    int r = find(array, 8, x);

	ASSERT_THAT( r == true);
END_TEST

BEGIN_TEST(find_x_between)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 6;
    int r = find(array, 8, x);

	ASSERT_THAT( r == true);
END_TEST

BEGIN_TEST(find_x_arr_null)
    
	int x = 1;
    int r = find(NULL, 8, x);

	ASSERT_THAT( r == false);
END_TEST


BEGIN_TEST(find_size_0)
    int array[] = {1, 2};
	int x = 4;
    int r = find(array, 0, x);

	ASSERT_THAT( r == false);
END_TEST

BEGIN_TEST(find_x_not_exist)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 3;
    int r = find(array, 8, x);

	ASSERT_THAT( r == false);
END_TEST

BEGIN_TEST(find_x_out_of_range)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 4;
    int r = find(array, 7, x);

	ASSERT_THAT( r == false);
END_TEST
/*-----------------------------------recursive find tests--------------------*/

BEGIN_TEST(find_x_begin_rec)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 1;
    int r = findRec(array, 8, x);

	ASSERT_THAT( r == true);
END_TEST

BEGIN_TEST(find_x_end_rec)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 4;
    int r = findRec(array, 8, x);

	ASSERT_THAT( r == true);
END_TEST

BEGIN_TEST(find_x_between_rec)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 6;
    int r = findRec(array, 8, x);

	ASSERT_THAT( r == true);
END_TEST

BEGIN_TEST(find_x_arr_null_rec)
    
	int x = 1;
    int r = findRec(NULL, 8, x);

	ASSERT_THAT( r == false);
END_TEST


BEGIN_TEST(find_size_0_rec)
    int array[] = {1, 2};
	int x = 4;
    int r = findRec(array, 0, x);

	ASSERT_THAT( r == false);
END_TEST

BEGIN_TEST(find_x_not_exist_rec)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 3;
    int r = findRec(array, 8, x);

	ASSERT_THAT( r == false);
END_TEST

BEGIN_TEST(find_x_out_of_range_rec)
    const int array[]  = {1, 2, 5, 6, 8, 9, 2, 4};
	int x = 4;
    int r = findRec(array, 7, x);

	ASSERT_THAT( r == false);
END_TEST

/*---------------------------------------bites on tests----------------------*/
/*BEGIN_TEST(bites_on_long_test)
	unsigned long a = 1;
	int r = FindHowManyBitesOnLong(a);
	
	ASSERT_THAT( r = 1);
END_TEST


BEGIN_TEST(bites_on_lut_test)
	long a = 1;
	int r = CalcBitOnLong(a);
	
	ASSERT_THAT( r = 1);
END_TEST*/

/*---------------------------------------binar search tests----------------------*/

BEGIN_TEST(find_x_index_begin)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 1;
    int r =  FindIndex(array, 8, x);

	ASSERT_THAT( r == 0);
END_TEST

BEGIN_TEST(find_x_index_end)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 8;
    int r =  FindIndex(array, 8, x);

	ASSERT_THAT( r == 7);
END_TEST

BEGIN_TEST(find_x_index_between)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 5;
    int r = FindIndex(array, 8, x);

	ASSERT_THAT( r == 4);
END_TEST

BEGIN_TEST(find_x_index_arr_null)
    
	int x = 1;
    int r =  FindIndex(NULL, 8, x);

	ASSERT_THAT( r == 8);
END_TEST


BEGIN_TEST(find_index_size_0)
    int array[] = {1, 2};
	int x = 4;
    int r =  FindIndex(array, 0, x);

	ASSERT_THAT( r == 0);
END_TEST

BEGIN_TEST(find_x_index_not_exist)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 9;
    int r =  FindIndex(array, 8, x);

	ASSERT_THAT( r == 8);
END_TEST

BEGIN_TEST(find_x_index_out_of_range)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 8;
    int r =  FindIndex(array, 7, x);

	ASSERT_THAT( r == 8);
END_TEST

/*-----------------------------------test secound binary search---------------------*/

BEGIN_TEST(find_x_index_begin2)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 1;
    int r =  binarySearch(array, 8, x);

	ASSERT_THAT( r == 0);
END_TEST

BEGIN_TEST(find_x_index_end2)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 8;
    int r =  binarySearch(array, 8, x);

	ASSERT_THAT( r == 7);
END_TEST

BEGIN_TEST(find_x_index_between2)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 5;
    int r = binarySearch(array, 8, x);

	ASSERT_THAT( r == 4);
END_TEST

BEGIN_TEST(find_x_index_arr_null2)
    
	int x = 1;
    int r =  binarySearch(NULL, 8, x);

	ASSERT_THAT( r == 8);
END_TEST


BEGIN_TEST(find_index_size_02)
    int array[] = {1, 2};
	int x = 4;
    int r =  binarySearch(array, 0, x);

	ASSERT_THAT( r == 0);
END_TEST

BEGIN_TEST(find_x_index_not_exist2)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 9;
    int r =  binarySearch(array, 8, x);

	ASSERT_THAT( r == 8);
END_TEST

BEGIN_TEST(find_x_index_out_of_range2)
    const int array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 8;
    int r =  binarySearch(array, 7, x);

	ASSERT_THAT( r == 7);
END_TEST
/*---------------------------------------2 recursive tests----------------------*/

BEGIN_TEST(add_two_small_integers_test)
	int a = 42;
	int b = 3;
	int r = add(a, b);
	
	ASSERT_THAT( r > a);
	ASSERT_THAT( r > b);
	ASSERT_EQUAL(r, a+b);	
END_TEST


BEGIN_TEST(add_two_small_opposite_integers_test)
	int a = 42;
	int b = -a;
	int r = add(a, b);		
	
	ASSERT_EQUAL(r, 0);

	ASSERT_NOT_EQUAL(a, b);
	

END_TEST

BEGIN_TEST(add_two_big_integers_test)
	int a = 298342894;
	int b = 238904789;
	int r = add(a, b);
	
	ASSERT_THAT( r > a);
	ASSERT_THAT( r > b);
	ASSERT_EQUAL(r, a+b);
END_TEST




BEGIN_TEST(half_a)
	int a = 42;
	int r = half(a);
	
	ASSERT_THAT( r < a);
	ASSERT_EQUAL(r, a/2);	
END_TEST


BEGIN_TEST(odd_a)
	int a = 41;
	int r = is_odd(a);
	
	ASSERT_EQUAL(r, true);	
END_TEST

BEGIN_TEST(mul_a_b)
	int a = 4;
	int b = 3;
	int r = multi(a, b);
	
	ASSERT_EQUAL(r, a * b);	
END_TEST

BEGIN_TEST(mul_minus_a_b)
	int a = (-4);
	int b = 3;
	int r = multi(a, b);
	
	ASSERT_EQUAL(r, a * b);	
END_TEST

BEGIN_TEST(mul_a_minus_b)
	int a = 4;
	int b = -3;
	int r = multi(a, b);
	
	ASSERT_EQUAL(r, a * b);	
END_TEST

BEGIN_TEST(mul_minus_a_minus_b)
	int a = 4;
	int b = -3;
	int r = multi(a, b);
	
	ASSERT_EQUAL(r, a * b);	
END_TEST

BEGIN_TEST(mul_zero_a_b)
	int a = 0;
	int b = 3;
	int r = multi(a, b);
	
	ASSERT_EQUAL(r, a * b);	
END_TEST

BEGIN_TEST(mul_a_zero_b)
	int a = 0;
	int b = 3;
	int r = multi(a, b);
	
	ASSERT_EQUAL(r, a * b);	
END_TEST

BEGIN_TEST(mul_zero_a_and_b)
	int a = 0;
	int b = 0;
	int r = multi(a, b);
	
	ASSERT_EQUAL(r, a * b);	
END_TEST

/*---------------------------is even---------------*/

BEGIN_TEST(iseven_a)
	int a = 2;
	int r = isEven(a);
	
	ASSERT_EQUAL(r, true);	
END_TEST

BEGIN_TEST(is_not_even_a)
	int a = 1;
	int r = isEven(a);
	
	ASSERT_EQUAL(r, false);	
END_TEST

BEGIN_TEST(is_minus_even_a)
	int a = -2;
	int r = isEven(a);
	
	ASSERT_EQUAL(r, true);	
END_TEST

BEGIN_TEST(is_minus_not_even_a)
	int a = -1;
	int r = isEven(a);
	
	ASSERT_EQUAL(r, false);	
END_TEST

BEGIN_TEST(is_zero_even_a)
	int a = 0;
	int r = isEven(a);
	
	ASSERT_EQUAL(r, true);	
END_TEST

/*--------------------------MONO TESTS---------------------*/
BEGIN_TEST(is_mono_increase_stricly)
	const float array[]  = {1, 2, 3, 4, 5, 6, 7, 8};
	int r = monoticity(array, 7);
	
	ASSERT_EQUAL(r, MONO_STRICLY_INCREASING);	
END_TEST

BEGIN_TEST(is_mono_increase_not_stricly)
	const float array[]  = {1, 2, 3, 3, 4, 5, 6, 7, 8};
	int r = monoticity(array, 8);
	
	ASSERT_EQUAL(r, MONO_INCREASING);	
END_TEST

BEGIN_TEST(is_mono_not_increase)
	const float array[]  = {1, 2, 3, 2, 4, 5, 6, 7, 8};
	int r = monoticity(array, 8);
	
	ASSERT_EQUAL(r, MONO_NOT_MONO);	
END_TEST

BEGIN_TEST(is_mono_decrease_stricky)
	const float array[]  = {8, 7, 6, 5, 3, 2, 1};
	int r = monoticity(array, 7);
	
	ASSERT_EQUAL(r, MONO_STRICLY_DECREASING);	
END_TEST

BEGIN_TEST(is_mono_decrease_not_stricky)
	const float array[]  = {8, 7, 6, 5, 3, 3, 2, 1};
	int r = monoticity(array, 8);
	
	ASSERT_EQUAL(r, MONO_DECREASING);	
END_TEST

/*-------------------------------prime factors tests---------------------*/

BEGIN_TEST(prime_factors_test)
	unsigned long a = 42;
	size_t* r = prime_factors(a);
	
	ASSERT_EQUAL(r[1], 3);	
END_TEST



BEGIN_SUITE(Its what you learn after you know it all that counts)
    TEST(find_x_begin)
	TEST(find_x_end)
	TEST(find_x_between)
	TEST(find_x_arr_null)
	TEST(find_size_0)
	TEST(find_x_not_exist)
	TEST(find_x_out_of_range)
	TEST(find_x_begin_rec)
	TEST(find_x_end_rec)
	TEST(find_x_between_rec)
	TEST(find_x_arr_null_rec)
	TEST(find_size_0_rec)
	TEST(find_x_not_exist_rec)
	TEST(find_x_out_of_range_rec)
	//TEST(bites_on_long_test)
	//TEST(bites_on_lut_test)
    TEST(find_x_index_begin)
	//TEST(find_x_index_end)
	TEST(find_x_index_between)
	TEST(find_x_index_arr_null)
	TEST(find_index_size_0)
	//TEST(find_x_index_not_exist)
	//TEST(find_x_index_out_of_range)
	TEST(find_x_index_begin2)
	TEST(find_x_index_end2)
	TEST(find_x_index_between2)
	TEST(find_x_index_arr_null2)
	TEST(find_index_size_02)
	TEST(find_x_index_not_exist2)
	TEST(find_x_index_out_of_range2)
    TEST(add_two_small_integers_test)
    TEST(half_a)
    TEST(odd_a)
	TEST(mul_a_b)
	TEST(mul_minus_a_b)
	TEST(mul_a_minus_b)
	TEST(mul_minus_a_minus_b)
	TEST(mul_zero_a_b)
	TEST(mul_a_zero_b)
	TEST(mul_zero_a_and_b)
	TEST(add_two_small_opposite_integers_test)
	TEST(add_two_small_opposite_integers_test)
	TEST(add_two_big_integers_test)
	TEST(iseven_a)
	TEST(is_not_even_a)
	TEST(is_minus_even_a)
	TEST(is_minus_not_even_a)
	TEST(is_zero_even_a)
	TEST(is_mono_increase_stricly)
	TEST(is_mono_increase_not_stricly)
	TEST(is_mono_not_increase)
	TEST(is_mono_decrease_stricky)
	TEST(is_mono_decrease_not_stricky)
	TEST(prime_factors_test)
	
END_SUITE
