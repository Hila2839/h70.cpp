#include <cstddef>
#include <string>
#include <iostream>
#include <list>

#include"person.hpp"

    
Person::Person(std::string const& a_id, std::string const& a_name, 
                double a_age, size_t a_body_mass, short a_hight)
: m_id(a_id)
, m_name(a_name)
, m_age(a_age)
, m_body_mass(a_body_mass)
, m_hight(a_hight)
{
}



std::string Person::get_id()
{
    return m_id;
}

std::string Person::get_name()
{
    return m_name;
}

size_t Person::get_age()
{
    return m_age;
}

size_t Person::get_body_mass()
{
    return m_body_mass;
}


 size_t Person::get_hight()
 {
     return  m_hight;
 }


 void Person::print_person()
 {
    std::cout<<"name: "<<m_name<<'\n';
    std::cout<<"age: "<<m_age<<'\n';
    std::cout<<"id: "<<m_id<<'\n';
    std::cout<<"body mass: "<<m_body_mass<<'\n';
    std::cout<<"hight: "<<m_hight<<'\n';
 }


 void sort_name(std::list<Person>& a_list)
 {
    size_t ordered = 1;
    while(ordered)
    {
        std::list<Person>::iterator start = a_list.begin();
        std::list<Person>::iterator next = ++a_list.begin();

        ordered = 0;
        while(next != a_list.end())
        {
            std::string a = start->get_name();
            std::string b = next->get_name();
            
            if (a > b)
            {
                std::swap(*start, *next);
                ordered = 1;
            }
            start++;
            next++;
        }
        if(ordered == 0)
        {
            break;
        }
    }
 }

void print_list(std::list<Person>& list)
{
std::list<Person>::iterator it = list.begin();
std::list<Person>::iterator e = list.end();

while(it != e)
{           
    (*it).print_person();
	it++;
}
std::cout << '\n';
}