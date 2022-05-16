
#include "mu_test.h"

#include "stack.hpp"




BEGIN_TEST(print_stack_push)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();
	
	ASSERT_THAT(a.get_size() == 3);
	
	
END_TEST


BEGIN_TEST(print_stack_pop)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    a.print();
	
	ASSERT_THAT(a.get_size() == 2);
	
	
END_TEST

BEGIN_TEST(stack_get_size)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    int b = a.get_size();
	
	ASSERT_THAT(b == 3);
	
	
END_TEST

BEGIN_TEST(stack_get_top)	
    
    adt::Stack a(50);
    for (size_t i = 0; i < 50; i++)
    {
        a.push(i);
    }
    int b = a.top();
	
	ASSERT_THAT(b == 49);
	
	
END_TEST


BEGIN_TEST(print_stack_clear)	
    
    adt::Stack a(50);
    for (size_t i = 0; i < 50; i++)
    {
        a.push(i);
    }
	a.clear();
    a.print();
	
    ASSERT_THAT(a.get_size() == 0);
	
	
END_TEST


BEGIN_TEST(add_two_stacks)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);

    adt::Stack b(50);
    b.push(4);
    b.push(5);
    b.push(6);
    
    a += b;
    a.print();
    b.print();
	
	ASSERT_THAT(a.get_size() == 6);
    ASSERT_THAT(b.get_size() == 3);
    ASSERT_THAT(a.top() == 4);
	
	
END_TEST

BEGIN_TEST(transfer_from_other_to_self)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);

    adt::Stack b(50);
    b.push(4);
    b.push(5);
    b.push(6);
   
    a << b;
    a.print();
    b.print();
	
	ASSERT_THAT(a.get_size() == 6);
    ASSERT_THAT(b.get_size() == 0);
    ASSERT_THAT(a.top() == 4);
	
	
END_TEST


BEGIN_TEST(transfer_from_self_to_other)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);

    adt::Stack b(50);
    b.push(4);
    b.push(5);
    b.push(6);
   
    a >> b;
    a.print();
    b.print();
	
	ASSERT_THAT(a.get_size() == 0);
    ASSERT_THAT(b.get_size() == 6);
    ASSERT_THAT(b.top() == 1);
	
	
END_TEST

BEGIN_TEST(transfer_from_self_to_other_to_third)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);

    adt::Stack b(50);
    b.push(4);
    b.push(5);
    b.push(6);

     adt::Stack c(50);
    b.push(7);
    b.push(8);
    b.push(9);
   
    a >> b >> c;
    a.print();
    b.print();
    c.print();
	
	ASSERT_THAT(a.get_size() == 0);
    ASSERT_THAT(b.get_size() == 0);
    ASSERT_THAT(c.get_size() == 9);
    ASSERT_THAT(c.top() == 1);
	
	
END_TEST


BEGIN_TEST(transfer_to_self_from_other_and_from_third)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);

    adt::Stack b(50);
    b.push(4);
    b.push(5);
    b.push(6);

     adt::Stack c(50);
    b.push(7);
    b.push(8);
    b.push(9);
   
    a << b << c;
    a.print();
    b.print();
    c.print();
    
	
	ASSERT_THAT(a.get_size() == 9);
    ASSERT_THAT(b.get_size() == 0);
    ASSERT_THAT(c.get_size() == 0);
    ASSERT_THAT(a.top() == 4);
	
	
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(print_stack_push)
    TEST(print_stack_pop)	
	TEST(print_stack_clear)	
	TEST(stack_get_size)
    TEST(stack_get_top)
    TEST(add_two_stacks)	
    TEST(transfer_from_other_to_self)	
    TEST(transfer_from_self_to_other)	
    TEST(transfer_from_self_to_other_to_third)
    TEST(transfer_to_self_from_other_and_from_third)	
    	


END_SUITE
