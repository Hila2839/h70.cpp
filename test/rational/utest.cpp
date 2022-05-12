#include "mu_test.h"

#include "rational.hpp"

BEGIN_TEST(multi_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	a.multi(b);
	ASSERT_THAT(a.get_numerator() == 24);
	ASSERT_THAT(a.get_denominator() == 4);
	
END_TEST

BEGIN_TEST(multi_negative_test)	
	algebra::Rational a(-6, 2);
    algebra::Rational b(4, 2);
	a.multi(b);
	ASSERT_THAT(a.get_numerator() == -24);
	ASSERT_THAT(a.get_denominator() == 4);
	
END_TEST

BEGIN_TEST(add_common_denom_test)	
	 algebra::Rational a(6, 2);
     algebra::Rational b(4, 2);
	a.add(b);
	ASSERT_THAT(a.get_numerator() == 10);
	ASSERT_THAT(a.get_denominator() == 2);
END_TEST


BEGIN_TEST(add_test)	
	 algebra::Rational a(6, 2);
     algebra::Rational b(4, 3);
	a.add(b);
	ASSERT_THAT(a.get_denominator() == 6);
	ASSERT_THAT(a.get_numerator() == 26);
	
END_TEST

BEGIN_TEST(add_negative_test)	
	 algebra::Rational a(-6, 2);
     algebra::Rational b(4, 3);
	a.add(b);
	ASSERT_THAT(a.get_denominator() == 6);
	ASSERT_THAT(a.get_numerator() == -10);
	
END_TEST

BEGIN_TEST(sub_common_denom_test)	
	 algebra::Rational a(6, 2);
     algebra::Rational b(4, 2);
	a.substruct(b);
	ASSERT_THAT(a.get_numerator() == 10);
	ASSERT_THAT(a.get_denominator() == 2);
END_TEST


BEGIN_TEST(sub_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 3);
	a.substruct(b);
	ASSERT_THAT(a.get_denominator() == 6);
	ASSERT_THAT(a.get_numerator() == 10);
	
END_TEST

BEGIN_TEST(sub_common_den_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	a.substruct(b);
	ASSERT_THAT(a.get_denominator() == 2);
	ASSERT_THAT(a.get_numerator() == 2);
	
END_TEST

BEGIN_TEST(sub_negative_test)	
	algebra::Rational a(-6, 2);
    algebra::Rational b(4, 3);
	a.substruct(b);
	ASSERT_THAT(a.get_denominator() == 6);
	ASSERT_THAT(a.get_numerator() == -26);
	
END_TEST



BEGIN_TEST(div_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 3);
	a.divide(b);
	ASSERT_THAT(a.get_denominator() == 8);
	ASSERT_THAT(a.get_numerator() == 18);
	
END_TEST


BEGIN_TEST(multi_test_with_int)	
	algebra::Rational a(6, 2);
    int b(2);
	a.multi(b);
	ASSERT_THAT(a.get_numerator() == 12);
	ASSERT_THAT(a.get_denominator() == 2);
	
END_TEST

BEGIN_TEST(multi_test_with_negative_int)	
	algebra::Rational a(6, 2);
    int b(-2);
	a.multi(b);
	ASSERT_THAT(a.get_numerator() == -12);
	ASSERT_THAT(a.get_denominator() == 2);
	
END_TEST


BEGIN_TEST(add_test_with_int)	
	algebra::Rational a(6, 2);
    int b(2);
	a.add(b);
	ASSERT_THAT(a.get_denominator() == 2);
	ASSERT_THAT(a.get_numerator() == 10);
	
END_TEST

BEGIN_TEST(add_test_with_negative_int)	
	algebra::Rational a(6, 2);
    int b(-2);
	a.add(b);
	ASSERT_THAT(a.get_denominator() == 2);
	ASSERT_THAT(a.get_numerator() == 2);
	
END_TEST


BEGIN_TEST(sub_test_with_int)	
	algebra::Rational a(6, 2);
    int b(2);
	a.substruct(b);
	ASSERT_THAT(a.get_denominator() == 2);
	ASSERT_THAT(a.get_numerator() == 2);
	
END_TEST

BEGIN_TEST(sub_test_with_negative_int)	
	algebra::Rational a(6, 2);
    int b(-2);
	a.substruct(b);
	ASSERT_THAT(a.get_denominator() == 2);
	ASSERT_THAT(a.get_numerator() == 10);
	
END_TEST

BEGIN_TEST(div_test_with_int)	
	algebra::Rational a(6, 2);
    int b(2);
	a.divide(b);
	ASSERT_THAT(a.get_denominator() == 4);
	ASSERT_THAT(a.get_numerator() == 6);
	
END_TEST

BEGIN_TEST(div_test_with_negative_int)	
	algebra::Rational a(6, 2);
    int b(-2);
	a.divide(b);
	ASSERT_THAT(a.get_denominator() == -4);
	ASSERT_THAT(a.get_numerator() == 6);
	
END_TEST

BEGIN_TEST(reduce_test)	
	algebra::Rational a(4, 12);
	a.reduce();
	ASSERT_THAT(a.get_denominator() == 3);
	ASSERT_THAT(a.get_numerator() == 1);
	
END_TEST

BEGIN_TEST(reduce_test_opposite)	
	algebra::Rational a(12, 4);
	a.reduce();
	ASSERT_THAT(a.get_denominator() == 1);
	ASSERT_THAT(a.get_numerator() == 3);
	
END_TEST


BEGIN_TEST(add_global_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 3);
	algebra::Rational c = add(a, b);
	ASSERT_THAT(c.get_denominator() == 6);
	ASSERT_THAT(c.get_numerator() == 26);
	
END_TEST

BEGIN_TEST(add_global_negative_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(-4, 2);
	algebra::Rational c = add(a, b);
	ASSERT_THAT(c.get_denominator() == 2);
	ASSERT_THAT(c.get_numerator() == 2);
	
END_TEST

BEGIN_TEST(equal_global_test_common_den)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	bool c = equal(a, b);
	ASSERT_THAT(c == false);
	
END_TEST

BEGIN_TEST(equal_global_test_true)	
	algebra::Rational a(6, 3);
    algebra::Rational b(12, 6);
	bool c = equal(a, b);
	ASSERT_THAT(c == true);
	
END_TEST

BEGIN_TEST(equal_global_test)	
	algebra::Rational a(6, 5);
    algebra::Rational b(4, 2);
	bool c = equal(a, b);
	ASSERT_THAT(c == false);
	
END_TEST

BEGIN_TEST(not_equal_global_test_common_den)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	bool c = not_equal(a, b);
	ASSERT_THAT(c == true);
	
END_TEST

BEGIN_TEST(not_equal_global_test)	
	algebra::Rational a(6, 5);
    algebra::Rational b(4, 2);
	bool c = not_equal(a, b);
	ASSERT_THAT(c == true);
	
END_TEST



BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(multi_test)
	TEST(multi_negative_test)	
	TEST(add_common_denom_test)
	TEST(add_test)
	TEST(add_common_denom_test)	
	TEST(add_negative_test)	
	TEST(sub_test)
	TEST(sub_common_den_test)
	TEST(sub_negative_test)
	TEST(div_test)
	TEST(multi_test_with_int)
	TEST(multi_test_with_negative_int)	
	TEST(add_test_with_int)	
	TEST(add_test_with_negative_int)
	TEST(sub_test_with_int)
	TEST(sub_test_with_negative_int)	
	TEST(div_test_with_int)
	TEST(div_test_with_negative_int)	
	TEST(reduce_test)	
	TEST(reduce_test_opposite)
	TEST(add_global_test)
	TEST(add_global_negative_test)	
	TEST(equal_global_test_common_den)	
	TEST(equal_global_test_true)	
	TEST(equal_global_test)	
	TEST(not_equal_global_test_common_den)	
	TEST(not_equal_global_test)
		
END_SUITE
