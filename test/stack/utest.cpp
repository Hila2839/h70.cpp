
#include "mu_test.h"

#include "stack.hpp"




BEGIN_TEST(print_stack_push)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();
	
	ASSERT_PASS();
	
	
END_TEST


BEGIN_TEST(print_stack_pop)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    a.print();
	
	ASSERT_PASS();
	
	
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
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(1);
    a.push(7);
    a.push(9);
    int b = a.top();
	
	ASSERT_THAT(b == 9);
	
	
END_TEST


BEGIN_TEST(print_stack_clear)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(1);
    a.push(2);
    a.push(3);
    a.clear();
    a.print();
	
	ASSERT_PASS();
	
	
END_TEST


BEGIN_TEST(add_two_stacks)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();

    adt::Stack b(50);
    b.push(4);
    b.push(5);
    b.push(6);
    a.print();
    b.print();
    a += b;
    a.print();
    b.print();
	
	ASSERT_PASS();
	
	
END_TEST

BEGIN_TEST(transfer_from_other_to_self)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();

    adt::Stack b(50);
    b.push(4);
    b.push(5);
    b.push(6);
    a.print();
    b.print();
    a << b;
    a.print();
    b.print();
	
	ASSERT_PASS();
	
	
END_TEST


BEGIN_TEST(transfer_from_self_to_other)	
    
    adt::Stack a(50);
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();

    adt::Stack b(50);
    b.push(4);
    b.push(5);
    b.push(6);
    a.print();
    b.print();
    a >> b;
    a.print();
    b.print();
	
	ASSERT_PASS();
	
	
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
    	


END_SUITE
