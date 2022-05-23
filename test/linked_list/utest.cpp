#include "mu_test.h"

#include "slist.hpp"


BEGIN_TEST(append_a_list_test)	

    adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);

    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(3);
    b.append(6);
    
    a.print();
    b.print();
   
    a.append(b);
    a.print();
  
    ASSERT_THAT(a.get_size() == 8);
    ASSERT_THAT(a.back_value() == 6);
    ASSERT_THAT(a.front_value() == 1);
    

 
END_TEST



BEGIN_TEST(append_test)	

    adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.print();

  

    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(a.back_value() == 4);
    ASSERT_THAT(a.front_value() == 1);
    

    
END_TEST


BEGIN_TEST(append_char_test)	

    adt::List<char> a;
    a.append('H');
    a.append('i');
    a.append('l');
    a.append('a');
    a.print();

  

    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(a.back_value() == 'a');
    ASSERT_THAT(a.front_value() == 'H');
    

    
END_TEST



BEGIN_TEST(preppend_test)	

    adt::List<int> a;
    a.preppend(1);
    a.preppend(2);
    a.preppend(3);
    a.preppend(4);
    a.print();

  

    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(a.back_value() == 1);
    ASSERT_THAT(a.front_value() == 4);
    	
END_TEST

BEGIN_TEST(preppend_a_list_test)	

    adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);

    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(3);
    b.append(6);
    
    a.print();
    b.print();
   
    a.preppend(b);
    a.print();
  
    ASSERT_THAT(a.get_size() == 8);
    ASSERT_THAT(a.back_value() == 4);
    ASSERT_THAT(a.front_value() == 1);
    

 
END_TEST


BEGIN_TEST(remove_head_test)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.remove_front();
    a.print();

  

    ASSERT_THAT(a.get_size() == 3);
    ASSERT_THAT(a.back_value() == 4);
    ASSERT_THAT(a.front_value() == 2);

    	
END_TEST

BEGIN_TEST(remove_back_test)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.remove_back();
    a.print();

  
    ASSERT_THAT(a.get_size() == 3);
    ASSERT_THAT(a.back_value() == 3);
    ASSERT_THAT(a.front_value() == 1);

    	
END_TEST


BEGIN_TEST(operator_append)	

   adt::List<int> a;
   int x = 1;
   a << x <<2 << 5;

    a.print();

  
    ASSERT_THAT(a.get_size() == 3);
    ASSERT_THAT(a.back_value() == 5);
    ASSERT_THAT(a.front_value() == 1);

    
END_TEST


BEGIN_TEST(equal_test_true)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(3);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a == b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 4);
    ASSERT_THAT(c == true);
   
    	
END_TEST


BEGIN_TEST(equal_test_false)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(2);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a == b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 4);
    ASSERT_THAT(c == false);
   
    	
END_TEST


BEGIN_TEST(not_equal_test_true)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(2);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a != b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 4);
    ASSERT_THAT(c == true);
   
    	
END_TEST


BEGIN_TEST(not_equal_test_false)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(3);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a != b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 4);
    ASSERT_THAT(c == false);
   
    	
END_TEST





BEGIN_TEST(is_bigger_test_true)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(4);
    a.append(4);
   


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(3);
    b.append(4);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a > b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 5);
    ASSERT_THAT(c == true);
   
    	
END_TEST



BEGIN_TEST(is_bigger_test_false)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
   


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(4);
    b.append(4);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a > b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 5);
    ASSERT_THAT(c == false);
   
    	
END_TEST




BEGIN_TEST(is_bigger_or_equal_test_true)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(4);
   
   


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a >= b);
  
    ASSERT_THAT(a.get_size() == 3);
    ASSERT_THAT(b.get_size() == 3);
    ASSERT_THAT(c == true);
   
    	
END_TEST



BEGIN_TEST(is_bigger_or_equal_test_false)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
   


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(4);
    b.append(4);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a >= b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 5);
    ASSERT_THAT(c == false);
   
    	
END_TEST



BEGIN_TEST(is_smaller_test_true)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(2);
    a.append(4);
   


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(3);
    b.append(4);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a < b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 5);
    ASSERT_THAT(c == true);
   
    	
END_TEST



BEGIN_TEST(is_smaller_test_false)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
   


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(4);
    b.append(4);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a > b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 5);
    ASSERT_THAT(c == false);
   
    	
END_TEST




BEGIN_TEST(is_smaller_or_equal_test_true)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(4);
   
   


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a <= b);
  
    ASSERT_THAT(a.get_size() == 3);
    ASSERT_THAT(b.get_size() == 3);
    ASSERT_THAT(c == true);
   
    	
END_TEST



BEGIN_TEST(is_smaller_or_equal_test_false)	

   adt::List<int> a;
    a.append(1);
    a.append(2);
    a.append(5);
    a.append(4);
   


    adt::List<int> b;
    b.append(1);
    b.append(2);
    b.append(4);
    b.append(4);
    b.append(4);
    
    a.print();
    
    b.print();

    bool c = (a <= b);
  
    ASSERT_THAT(a.get_size() == 4);
    ASSERT_THAT(b.get_size() == 5);
    ASSERT_THAT(c == false);
   
    	
END_TEST


BEGIN_TEST(reverse_test)	

   adt::List<int> a;
   for (size_t i = 0; i < 20; i++)
   {
       a.append(i);
   }
   
    a.print();
    a.reverse();
    a.print();
    

  
    ASSERT_THAT(a.get_size() == 20);
    std::cout<<a.back_value()<<'\n';
    std::cout<<a.front_value();
    ASSERT_THAT(a.back_value() == 0);
    ASSERT_THAT(a.front_value() == 19);

   
    	
END_TEST


/*
BEGIN_TEST(cpp_fo_each_test)	

   adt::List<int> a;
   for (size_t i = 0; i < 20; i++)
   {
       a.append(i);
   }
   
    a.print();
    a.reverse();
    a.print();
    
    std::for_each(a.begin(), a.end(), (-1));
  
   ASSERT_PASS();

   
    	
END_TEST

*/


    BEGIN_SUITE(Its what you learn after you know it all that counts)
    	
    	TEST(append_a_list_test)	
        TEST(append_test)	
        TEST(append_char_test)
        TEST(preppend_test)
        TEST(preppend_a_list_test)
        TEST(remove_head_test)
        TEST(remove_back_test)
        TEST(operator_append)
        TEST(equal_test_true)
        TEST(equal_test_false)
        TEST(not_equal_test_true)	
        TEST(not_equal_test_false)
        TEST(is_bigger_test_true)
        TEST(is_bigger_test_false)
        TEST(is_bigger_or_equal_test_true)	
        TEST(is_bigger_or_equal_test_false)
        TEST(is_smaller_test_true)
        TEST(is_smaller_test_false)
        TEST(is_smaller_or_equal_test_true)	
        TEST(is_smaller_or_equal_test_false)
        TEST(reverse_test)	
        //TEST(cpp_fo_each_test)


END_SUITE