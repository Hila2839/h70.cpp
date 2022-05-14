#include "mu_test.h"

#include "rational.hpp"
#include "quadratic.hpp"


BEGIN_TEST(print_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	algebra::Rational c(4);
	
	algebra::Quadratic q(a, b, c);
	q.print();

	ASSERT_PASS();
	
END_TEST

BEGIN_TEST(multi_int_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	algebra::Rational c(4);
	
	algebra::Quadratic q(a, b, c);
	q.multi(2);

	ASSERT_THAT(q.get_coefficient(3).get_numerator() == 12);
	ASSERT_THAT(q.get_coefficient(1).get_numerator()  == 8);
	ASSERT_THAT(q.get_coefficient(2).get_denominator() == 2);
	
END_TEST


BEGIN_TEST(multi_negative_int_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	algebra::Rational c(4);
	
	algebra::Quadratic q(a, b, c);
	q.multi(-2);

	ASSERT_THAT(q.get_coefficient(3).get_numerator() == -12);
	ASSERT_THAT(q.get_coefficient(1).get_numerator()  == -8);
	ASSERT_THAT(q.get_coefficient(2).get_denominator() == 2);
	
END_TEST


BEGIN_TEST(multi_ratio_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	algebra::Rational c(4);
	algebra::Rational d(5, 3);
	
	algebra::Quadratic q(a, b, c);
	q.multi(d);

	ASSERT_THAT(q.get_coefficient(3).get_numerator() == 30);
	ASSERT_THAT(q.get_coefficient(1).get_numerator()  == 20);
	ASSERT_THAT(q.get_coefficient(2).get_denominator() == 6);
	
END_TEST


BEGIN_TEST(multi_negative_ratio_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	algebra::Rational c(4);
	algebra::Rational d(-5, 3);
	
	algebra::Quadratic q(a, b, c);
	q.multi(d);

	ASSERT_THAT(q.get_coefficient(3).get_numerator() == -30);
	ASSERT_THAT(q.get_coefficient(1).get_numerator()  == -20);
	ASSERT_THAT(q.get_coefficient(2).get_denominator() == 6);
	
END_TEST


BEGIN_TEST(multi_negative_denum_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	algebra::Rational c(4);
	algebra::Rational d(5, -3);
	
	algebra::Quadratic q(a, b, c);
	q.multi(d);

	ASSERT_THAT(q.get_coefficient(3).get_numerator() == -30);
	ASSERT_THAT(q.get_coefficient(1).get_numerator()  == -20);
	ASSERT_THAT(q.get_coefficient(2).get_denominator() == 6);
	
END_TEST


BEGIN_TEST(root_test_two_solutions)	
	algebra::Rational a(1, 1);
    algebra::Rational b(12, 1);
	algebra::Rational c(32);
	algebra::Roots r = {0, 0, 0};
	
	algebra::Quadratic q(a, b, c);
	q.root(&r);

	ASSERT_PASS();
	
	
END_TEST

BEGIN_TEST(root_test_one_solution)	
	algebra::Rational a(9, 1);
    algebra::Rational b(12, 1);
	algebra::Rational c(4);
	algebra::Roots r = {0, 0, 0};
	
	algebra::Quadratic q(a, b, c);
	q.root(&r);

	ASSERT_PASS();
	
	
END_TEST

BEGIN_TEST(root_test_no_solution)	
	algebra::Rational a(1, 1);
    algebra::Rational b(2, 1);
	algebra::Rational c(10);
	algebra::Roots r = {0, 0, 0};
	
	algebra::Quadratic q(a, b, c);
	q.root(&r);

	ASSERT_PASS();
	
	
END_TEST


BEGIN_TEST(root_test_erationals_solution)	
	algebra::Rational a(1, 4);
    algebra::Rational b(1, 4);
	algebra::Rational c(-7, 2);
	algebra::Roots r = {0, 0, 0};
	
	algebra::Quadratic q(a, b, c);
	q.root(&r);

	ASSERT_PASS();
	
	
END_TEST


BEGIN_TEST(global_add_two_quadratics_test)	
	algebra::Rational a(6, 2);
    algebra::Rational b(4, 2);
	algebra::Rational c(4);

	algebra::Rational d(5, -3);
	algebra::Rational e(6, 8);
	algebra::Rational f(4);
	
	algebra::Quadratic q(a, b, c);
	algebra::Quadratic r(d, e, f);
	algebra::Quadratic s = add(q, r);

	ASSERT_THAT(s.get_coefficient(3).get_numerator() == 8);
	ASSERT_THAT(s.get_coefficient(1).get_numerator()  == 8);
	ASSERT_THAT(s.get_coefficient(2).get_denominator() == 16);
	
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(print_test)
	TEST(multi_int_test)
	TEST(multi_negative_int_test)
	TEST(multi_ratio_test)	
	TEST(multi_negative_ratio_test)
	TEST(multi_negative_denum_test)
	TEST(root_test_two_solutions)
	TEST(root_test_one_solution)
	TEST(root_test_no_solution)	
	TEST(root_test_erationals_solution)	
	TEST(global_add_two_quadratics_test)

	
END_SUITE
