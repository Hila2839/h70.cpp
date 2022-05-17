#include "mu_test.h"

#include "gray_image.hpp"




BEGIN_TEST(print_image_push)	
    
    gfx::GrayImage a(5, 5, 100);
    a.print();
	
	ASSERT_PASS();
	
	
END_TEST

BEGIN_TEST(set_image)	
    
    gfx::GrayImage a(5, 5, 100);
    a.set_pixle(2, 3, 99);
    a.print();

	
	ASSERT_PASS();
	
	
END_TEST


BEGIN_TEST(get_image)	
    
    gfx::GrayImage a(5, 5, 100);
    a.set_pixle(2, 3, 99);
    a.print();

	
	ASSERT_THAT(a.get_pixle(2, 3) == 99);
	
	
END_TEST


BEGIN_TEST(clear_image)	
    
    gfx::GrayImage a(5, 5, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);
    a.print();
    a.clear();
    a.print();

	
	ASSERT_PASS();
	
	
END_TEST


BEGIN_TEST(get_image_sizes)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

	
	ASSERT_THAT(a.get_width() == 5);
    ASSERT_THAT(a.get_hight() == 4);
    ASSERT_THAT(a.get_range() == 100);
	
	
END_TEST


BEGIN_TEST(compare_two_images)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

    gfx::GrayImage b(5, 4, 100);
    b.set_pixle(2, 3, 99);
    b.set_pixle(0, 0, 12);
    b.set_pixle(3, 3, 8);
    bool c = (a == b);
	a.print();
    b.print();

	ASSERT_THAT(c == true);
    
	
END_TEST

BEGIN_TEST(compare_two_images_different_size)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

    gfx::GrayImage b(5, 5, 100);
    b.set_pixle(2, 3, 99);
    b.set_pixle(0, 0, 12);
    b.set_pixle(3, 3, 8);
    bool c = (a == b);
	a.print();
    b.print();

	ASSERT_THAT(c == false);
    
	
END_TEST


BEGIN_TEST(uncompare_two_images_different_size)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

    gfx::GrayImage b(5, 5, 100);
    b.set_pixle(2, 3, 99);
    b.set_pixle(0, 0, 12);
    b.set_pixle(3, 3, 8);
    bool c = (a != b);
	a.print();
    b.print();

	ASSERT_THAT(c == true);
    
	
END_TEST


BEGIN_TEST(uncompare_two_images_different_pixles)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

    gfx::GrayImage b(5, 4, 100);
    b.set_pixle(2, 3, 99);
    b.set_pixle(0, 0, 1);
    b.set_pixle(3, 3, 8);
    bool c = (a != b);
	a.print();
    b.print();

	ASSERT_THAT(c == true);
    
	
END_TEST

BEGIN_TEST(operators_copy)	
    
    gfx::GrayImage a(5, 4, 100);
    

    gfx::GrayImage b = a;

	a.print();
    b.print();

	ASSERT_THAT(b == a);
    
	
END_TEST


BEGIN_TEST(operators_and_equal)	
    
    gfx::GrayImage a(5, 4, 100);
    
    gfx::GrayImage b(5, 4, 100);

    a.clear();
    b.clear();

    gfx::GrayImage c = (a &= b);

	a.print();
    b.print();

   
	ASSERT_THAT(c == a);
    
	
END_TEST


BEGIN_TEST(operators_or_equal)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 1);
    a.set_pixle(0, 0, 2);
    a.set_pixle(3, 3, 3);

    gfx::GrayImage b(5, 4, 100);
    b.set_pixle(2, 3, 2);
    b.set_pixle(0, 0, 3);
    b.set_pixle(3, 3, 4);

    gfx::GrayImage c = (a |= b);

	a.print();
    b.print();

	ASSERT_THAT(a.get_pixle(2, 3) == 3);

END_TEST

BEGIN_TEST(operators_xor_equal)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 1);
    a.set_pixle(0, 0, 2);
    a.set_pixle(3, 3, 3);

    gfx::GrayImage b(5, 4, 100);
    b.set_pixle(2, 3, 2);
    b.set_pixle(0, 0, 3);
    b.set_pixle(3, 3, 4);

    gfx::GrayImage c = (a ^= b);

	a.print();
    b.print();

     printf("%d\n", 1 ^ 2);
	ASSERT_THAT(a.get_pixle(2, 3) == 3);

END_TEST



BEGIN_TEST(operators_and)	
    
    gfx::GrayImage a(5, 4, 100);
    
    gfx::GrayImage b(5, 4, 100);

    a.clear();
    b.clear();

    gfx::GrayImage c = a & b;

	a.print();
    b.print();


	ASSERT_THAT(c == a);
    
	
END_TEST

BEGIN_TEST(operators_or)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 1);
    a.set_pixle(0, 0, 2);
    a.set_pixle(3, 3, 3);

    gfx::GrayImage b(5, 4, 100);
    b.set_pixle(2, 3, 2);
    b.set_pixle(0, 0, 3);
    b.set_pixle(3, 3, 4);

    gfx::GrayImage c = (a | b);

	a.print();
    b.print();


	ASSERT_THAT(c.get_pixle(2, 3) == 3);
    
	
END_TEST



BEGIN_TEST(operators_xor)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 1);
    a.set_pixle(0, 0, 2);
    a.set_pixle(3, 3, 3);

    gfx::GrayImage b(5, 4, 100);
    b.set_pixle(2, 3, 2);
    b.set_pixle(0, 0, 3);
    b.set_pixle(3, 3, 4);

    gfx::GrayImage c = (a ^ b);

	a.print();
    b.print();

     
	ASSERT_THAT(c.get_pixle(2, 3) == 3);

END_TEST


BEGIN_TEST(write_image_to_file)	
    
    gfx::GrayImage a(100, 100, 200);
    for (int i = 0; i < a.get_width(); ++i)
    {
        for (int j = 0; j < a.get_hight(); ++j)
        {
             a.set_pixle(i, j, i);
        }
    }
    
    write_to_file(a, "test2.pgm");
	
	ASSERT_PASS();
    
	
END_TEST


BEGIN_TEST(read_image_from_file)	
    
    gfx::GrayImage a(100, 100, 200) ;
    for (int i = 0; i < a.get_width(); ++i)
    {
        for (int j = 0; j < a.get_hight(); ++j)
        {
             a.set_pixle(i, j, i);
        }
    }
    gfx::GrayImage b = gfx::read_from_file("test2.pgm");
	
	ASSERT_THAT(b == a);
    	
END_TEST


BEGIN_TEST(opposite_image)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

  
    gfx::GrayImage b = (~ a);
	a.print();
    b.print();
    

	ASSERT_THAT(b.get_pixle(2, 3) == 1);
    
	
END_TEST


BEGIN_TEST(at_function)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

    a.at(2, 3) = 100;
    
	a.print();
  

	ASSERT_THAT(a.get_pixle(2, 3) == 100);
    
	
END_TEST



BEGIN_TEST(operator_parenthesis)	
    
    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

    a(2, 3) = 100;
    
	a.print();
  

	ASSERT_THAT(a.get_pixle(2, 3) == 100);
    
	
END_TEST

 
/*BEGIN_TEST(squerd_parenthesis)

    gfx::GrayImage a(5, 4, 100);
    a.set_pixle(2, 3, 99);
    a.set_pixle(0, 0, 12);
    a.set_pixle(3, 3, 8);

    gfx::GrayImage::Point b = {2, 3};
    a[b] = 100;
    
	a.print();
  

	ASSERT_THAT(a.get_pixle(2, 3) == 100);

*/
    BEGIN_SUITE(Its what you learn after you know it all that counts)
    	
    	TEST(print_image_push)
        TEST(set_image)
        TEST(get_image)
        TEST(clear_image)	
        TEST(get_image_sizes)	
        TEST(compare_two_images)
        TEST(compare_two_images_different_size)	
        TEST(uncompare_two_images_different_size)	
        TEST(uncompare_two_images_different_pixles)
        TEST(operators_copy)	
        TEST(operators_and_equal)	
        TEST(operators_or_equal)
        TEST(operators_xor_equal)
        TEST(operators_and)	
        TEST(operators_or)
        TEST(operators_xor)



        TEST(write_image_to_file)
        TEST(read_image_from_file)
        TEST(opposite_image)
        TEST(at_function)
        TEST(operator_parenthesis)
       // TEST(squerd_parenthesis)


END_SUITE