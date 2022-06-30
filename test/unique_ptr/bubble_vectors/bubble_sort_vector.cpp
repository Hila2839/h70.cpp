#include <iostream>
#include <vector>
#include <memory>
#include <map>

//#include "bubble_sort.hpp"



int sum_calc(std::vector<int>& a_vector)
{
    int sum = 0;
    for(auto const& item : a_vector)
    {
        sum += item;
    }
    return sum;
}



void add_vec_sum(std::vector<std::vector<int>>& a_vector)
{
    for(auto& item : a_vector)
    {
        int sum = sum_calc(item);
        item.push_back(sum);
    }
}


void remove_vec_sum(std::vector<std::vector<int>>& a_vectors_vector)
{
    for(auto& item : a_vectors_vector)
    {
        item.pop_back();
    }
}


bool is_smaller(std::vector<int>& a_lhs, std::vector<int>& a_rhs)
{
    int lhs_sum =  a_lhs[a_lhs.size() - 1];
    int rhs_sum = a_rhs[a_rhs.size() - 1];
    //int lhs_sum = sum_calc(a_lhs);
    //int rhs_sum = sum_calc(a_rhs);

    return lhs_sum > rhs_sum;
    
}


void swap(std::vector<int>& a_lhs, std::vector<int>& a_rhs)
{
    //std::vector<int> temp = a_lhs;
    //a_lhs = a_rhs;
    //a_rhs = temp;

    std::vector<int> temp = std::move(a_lhs);
    a_lhs = std::move(a_rhs);
    a_rhs = std::move(temp);
    
}


void sort(std::vector<std::vector<int>>& a_vectors_vector)
{
    add_vec_sum(a_vectors_vector);
    for (size_t i = 0; i < a_vectors_vector.size() - 1; ++i)
    {
        for (size_t j = 0; j <  a_vectors_vector.size() - 1 - i; j++)
        {
            if (is_smaller(a_vectors_vector[j], a_vectors_vector[j + 1]))
            {
            swap(a_vectors_vector[j], a_vectors_vector[j + 1]);
            }
        }
        
    }
    remove_vec_sum(a_vectors_vector);
}



std::vector<int> random_vector()
{
    size_t s = 10 + rand() % 10;
    std::vector<int> v;
    v.reserve(s);
    while(s-->0){
        v.push_back(rand());
    }

    return v;
}

std::vector<std::vector<int> > init_vec(size_t capacity)
{
    std::vector<std::vector<int> > vectors_vector;
    vectors_vector.reserve(capacity);
    while(capacity-- > 0)
    {
        std::vector<int> v = random_vector();
        vectors_vector.push_back(v);
    }
    
    return vectors_vector;
}



int main()
{
std::vector<std::vector<int>> my_vectors = init_vec(10);

for(auto& item : my_vectors)
{
    std::cout<<(sum_calc(item));
    std::cout<<',';

}
std::cout<<'\n';


sort(my_vectors);

std::cout<<"after sort:\n";


for(auto& item : my_vectors)
{
    std::cout<<(sum_calc(item));
    std::cout<<',';
}
std::cout<<'\n';

 return 0;
}
