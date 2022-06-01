
#include <vector>

#include "mu_test.h"
#include "person.hpp"
#include "algorithms.hpp"



BEGIN_TEST(get_and_print_test)	
	
	Person a("222222222", "dan", 20, 50.5, 175);
	Person b("333333333", "anna", 28, 70, 160);
	Person c("444444444", "mike", 15, 44, 170);
	Person d("111111111", "alma", 4, 13, 130);

	a.print_person();
	ASSERT_THAT(b.get_name() == "anna");
	ASSERT_THAT(a.get_id() == "222222222");
	ASSERT_THAT(b.get_age() == 28);
	ASSERT_THAT(c.get_hight() == 170);
	ASSERT_THAT(d.get_body_mass() == 13);

END_TEST


BEGIN_TEST(sort_person_by_name)		
	
	Person a("222222222", "dan", 20, 50.5, 175);
	Person b("333333333", "anna", 28, 70, 160);
	Person c("444444444", "mike", 15, 44, 170);
	Person d("111111111", "alma", 4, 13, 130);

	std::list<Person> list;
	list.push_back(a);
	list.push_back(b);
	list.push_back(c);
	list.push_back(d);

	sort_name(list);
	print_list(list);
	ASSERT_PASS();



END_TEST

BEGIN_TEST(generic_sort_vector_int)		
	
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(2);

	algorithm::sort(vec);
	algorithm::gprint(vec);

	ASSERT_THAT(*vec.begin() == 1);
	ASSERT_THAT(*--vec.end() == 5);


END_TEST



BEGIN_TEST(generic_sort_vector_string)		
	
	std::vector<std::string> vec;
	vec.push_back("hey");
	vec.push_back("you");
	vec.push_back("are");
	vec.push_back("there");

	algorithm::sort(vec);
	algorithm::gprint(vec);
	
	ASSERT_THAT(*vec.begin() == "are");
	ASSERT_THAT(*--vec.end() == "you");



END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	
	TEST(get_and_print_test)
	TEST(sort_person_by_name)	
	TEST(generic_sort_vector_int)
	TEST(generic_sort_vector_string)	


END_SUITE
