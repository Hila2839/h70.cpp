#include <vector>
#include <iostream>
#include <memory>

#include "rational.hpp"





auto partition(std::vector<std::unique_ptr<algebra::Rational>>& a_vector, size_t a_begin, size_t a_end)
{
    algebra::Rational pivot = *(a_vector[a_begin]);

    ++a_begin;
  


    while(a_begin < a_end)
	{
		while(*a_vector[a_begin] < pivot &&  a_begin < a_end)
		{
			++a_begin;
		}

		while(*a_vector[a_end] > pivot)
		{
			--a_end;
		}
        if (a_begin < a_end)
        {
            a_vector[a_begin].swap(a_vector[a_end]);
        }
	}

    if(a_begin == a_end)
    {
        if(*a_vector[a_end] < pivot)
        {
           a_vector[a_begin].swap(a_vector[a_end]);
        }
        return a_end;
    }
	return a_end;
}





void quick_sort(std::vector<std::unique_ptr<algebra::Rational>>& a_vector,
 size_t a_begin, size_t a_end)
{

	if(a_begin >= a_end )
	{
		return;
	}

	size_t pIndex = partition(a_vector, a_begin, a_end);

	quick_sort(a_vector, a_begin, --pIndex);
	
	quick_sort(a_vector, ++pIndex, a_end );
}


/*
void print(std::vector<std::unique_ptr<algebra::Rational>> a_vector,
             size_t a_begin, size_t a_end)
{

    while(a_begin != a_end)
    {
        (*a_vector[a_begin])->print();
        ++a_begin;
        
    }
    std::cout<<'\n';
}*/



int main()
{
    std::vector<std::unique_ptr<algebra::Rational>> vector;

    std::unique_ptr<algebra::Rational> a(new algebra::Rational(9, 1));
    std::unique_ptr<algebra::Rational> b(new algebra::Rational(2, 2));
    std::unique_ptr<algebra::Rational> c(new algebra::Rational(10, 1));
    std::unique_ptr<algebra::Rational> d(new algebra::Rational(5, 1));
    std::unique_ptr<algebra::Rational> e(new algebra::Rational(8, 2));
    std::unique_ptr<algebra::Rational> f(new algebra::Rational(7, 1));
    std::unique_ptr<algebra::Rational> g(new algebra::Rational(6, 3));
    std::unique_ptr<algebra::Rational> h(new algebra::Rational(1, 1));
    std::unique_ptr<algebra::Rational> i(new algebra::Rational(3, 1));

    vector.push_back(std::move(a));
    vector.push_back(std::move(b));
    vector.push_back(std::move(c));
    vector.push_back(std::move(d));
    vector.push_back(std::move(e));
    vector.push_back(std::move(f));
    vector.push_back(std::move(g));
    vector.push_back(std::move(h));
    vector.push_back(std::move(i));


    for(auto const& item : vector)
    {
        ((*item).print());
    }
    std::cout<<'\n';

    quick_sort(vector, 0, vector.size() - 1);

    for(auto const& item : vector)
    {
        ((*item).print());
    }
    std::cout<<'\n';

    return 0;

}