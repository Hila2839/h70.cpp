#include <cstddef>
#include <string>
#include <list>

class Person
{
public:
    Person(std::string const& a_id, std::string const& a_name, double a_age, size_t a_body_mass, 
                short a_hight);

std::string get_id();
std::string get_name();
size_t get_age();
size_t get_body_mass();
size_t get_hight();
void print_person();


private:
    std::string m_id;
    std::string m_name;
    size_t m_age;
    size_t m_body_mass;
    size_t m_hight;
};

 void sort_name(std::list<Person>& a_list);

 void print_list(std::list<Person>& list);
