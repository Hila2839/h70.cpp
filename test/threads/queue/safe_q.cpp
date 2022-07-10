#include <iostream>
#include <functional>
#include <vector>
#include <numeric>
#include <algorithm>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <queue>
#include <memory>


#include "safe_q.hpp"


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



// void print(std::queue<std::vector<int>> a_q)
// {
// 	std::queue<std::vector<int>> q_copy(a_q);

// 	size_t size = q_copy.size();

// 	std::list<std::vector<int>> elements;

// 	for(size_t i = 0; i < size; ++i)
// 	{
// 		std::vector<int> element;
// 		q_copy.dequeue(element);	
// 		elements.push_front(element);
// 	}

// 	auto it = elements.begin();
// 	auto end = elements.end();

// 	while(it != end)
// 	{
// 		std::cout << *it << ", ";

// 		++it;
// 	}

// 	std::cout << "\n\n";
// }

// std::queue<std::vector<int> > init_queue(size_t capacity)
// {
//     std::cout<<"init queue \n";
//     std::queue<std::vector<int> > vectors_queue;
    
//     while(capacity-- > 0)
//     {
//         std::vector<int> v = random_vector();
//         vectors_queue.push(v);
//     }
    
//     return vectors_queue;
// }


void add_producers(SafeQ<std::vector<int>>& a_q, 
                std::vector<std::thread>& a_threads, size_t a_num)
{
    const auto processor_count = std::thread::hardware_concurrency();

    if (a_num > processor_count)
    {
        a_num = processor_count;
    }
    
    
    while(a_num --> 0)
    {
        std::vector<int> vec(100, 1);
        a_threads.push_back(std::thread(&SafeQ<std::vector<int>>::enqueue, std::ref(a_q), std::ref(vec)));	
    }
}



void add_consumers(SafeQ<std::vector<int>>& a_q, 
                std::vector<std::thread>& a_threads, size_t a_num)
{
    const auto processor_count = std::thread::hardware_concurrency();

    if (a_num > processor_count)
    {
        a_num = processor_count;
    }

    std::vector<int> poped;
    while(a_num --> 0)
    {
        a_threads.push_back(std::thread(&SafeQ<std::vector<int>>::dequeue, std::ref(a_q), std::ref(poped)));	
    }
}




void join_threads(std::vector<std::thread>& a_threads)
{
    for (auto& t :  a_threads)
	{
		t.join();
	}
}



int main()
{
    SafeQ<std::vector<int>> test;

    std::vector<std::thread> threads;
    
    // add_producers(test, threads, 2);
    // add_consumers(test, threads, 2);


    std::vector<int> poped;
    std::vector<int> vec(10000, 1);


    for (size_t i = 0; i < 100; ++i)
    {
        std::cout<<"add"<<'\n';
        threads.push_back(std::thread(&SafeQ<std::vector<int>>::dequeue, std::ref(test), std::ref(poped)));	
         std::cout<<"pop"<<'\n';
        threads.push_back(std::thread(&SafeQ<std::vector<int>>::enqueue, std::ref(test), std::ref(vec)));	
    }
    
    join_threads(threads);


    std::cout<<"q size:"<<test.size()<<'\n';

    //test.print();


    return 0;
}