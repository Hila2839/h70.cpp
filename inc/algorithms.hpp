#include <cstddef>
#include <iostream>

namespace algorithm
{

template<typename C>
void gprint(C const& container){
    typename C::const_iterator it = container.begin();
    typename C::const_iterator e = container.end();

    while(it != e){  
        //typename C::value_type const& e = *it;         
        typename C::const_reference e = *it;

        std::cout << e << ", ";
        ++it;
    }
    std::cout << '\n';
}


template<typename C>
void sort(C& container)
{
    size_t ordered = 1;
    while(ordered)
    {
        typename C::iterator start = container.begin();
        typename C::iterator next = ++container.begin();

        ordered = 0;
        while(next != container.end())
        {
            if (*start > *next)
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




}//namespace algorithm