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
#include "mu_test.hpp"


// int random_vector()
// {
//     size_t s = 10 + rand() % 10;
//     std::vector<int> v;
//     v.reserve(s);
//     while(s-->0){
//         v.push_back(rand());
//     }

//     return v;
// }


// std::queue<int > init_queue(size_t capacity)
// {
//     std::cout<<"init queue \n";
//     std::queue<int > vectors_queue;
    
//     while(capacity-- > 0)
//     {
//         int v = random_vector();
//         vectors_queue.push(v);
//     }
    
//     return vectors_queue;
// }


// void add_producers(SafeQueue<int, 3000>& a_q, 
//                 std::vector<std::thread>& a_threads, size_t a_num)
// {
//     const auto processor_count = std::thread::hardware_concurrency();

//     if (a_num > processor_count)
//     {
//         a_num = processor_count;
//     }
    
    
//     while(a_num --> 0)
//     {
//         int number = a_num;
//         a_threads.push_back(std::thread(&SafeQueue<int, 3000>::enqueue, std::ref(a_q), number));	
//     }
// }

// void create_producers(SafeQueue<int, 3000>& a_q, size_t a_threads_number, 
// std::vector<std::thread>& a_threads)
// {
//     int total_counter = 0;
//     auto producer = [&a_q, &total_counter](int a_threads_number)
//     {
//         for (int i = 0; i < 50; i++)
//         {
//             int vec = {a_threads_number, total_counter++, i};
//             a_q.enqueue(vec);
//         }
//     };
//     while(a_threads_number --> 0)
//     {
//         a_threads.push_back(std::thread(producer, a_threads_number));	
//     }
// }


// std::vector<std::vector<int>> create_consumers(SafeQueue<int, 3000>& a_q, size_t a_threads_number,
//                      std::vector<std::thread>& a_threads, size_t a_producers_num)
// {
//     std::vector<std::vector<int>> all_poped(a_threads_number);
//     auto consumer = [&a_q](std::vector<std::vector<int>> a_all, size_t a_producers_num)
//     {
//         std::vector<int> my_poped;
//         size_t poisen_apples = a_producers_num;
//         while( poisen_apples > 0)
//         {
//             int poped;
//             a_q.dequeue(poped);
//             my_poped.push_back(poped);
//             if(poped == (-1))
// 		    {
//                 break;
// 		    }
//             //if poped == poisen apple--
//         }
//         a_all.push_back(my_poped);
//     };

//    for (size_t i = 0; i < a_threads_number; i++)
//    {
//         a_threads.push_back(std::thread(consumer, std::ref(all_poped), a_producers_num));	
//    }
//    return all_poped;
// }



// void add_consumers(SafeQueue<int, 3000>& a_q, 
//                 std::vector<std::thread>& a_threads, size_t a_num)
// {
//     const auto processor_count = std::thread::hardware_concurrency();

//     if (a_num > processor_count)
//     {
//         a_num = processor_count;
//     }

//     int poped;
//     while(a_num --> 0)
//     {
//         a_threads.push_back(std::thread(&SafeQueue<int, 3000>::dequeue, std::ref(a_q), std::ref(poped)));	
//     }
// }

// bool check_fifo(all_poped)
// {
//     for (auto& vector_of_vectors : all_poped)
// 	{
// 		for(auto& vector_of_ints: vector_of_vectors)
//         {
//             if(vector_of_ints[])
//         }
// 	}

// }


// void give_apples(SafeQueue<int, 3000>& a_q, std::vector<std::thread>& a_threads)
// {
//     for(size_t i = 0; i < a_threads.size(); ++i)
//     {
//         int poisen = -1;
//         a_q.enqueue(poisen);
//     }
// }



// void join_producers(std::vector<std::thread>& a_threads)
// {
//     for (auto& t :  a_threads)
// 	{
// 		t.join();
// 	}
// }

// void join_consumers(std::vector<std::thread>& a_threads)
// {
//     for (auto& t :  a_threads)
// 	{
// 		t.join();
// 	}
// }







BEGIN_TEST(one_consumer_one_producer)	

    std::cout<<"one consumer one producer\n";

    SafeQueue<int, 3000> my_q;

 auto push_safe = [&my_q](size_t a_number)
    {
        while(a_number-->0)
        {
            my_q.enqueue(a_number);
        }
    };

    auto pop_safe = [&my_q](size_t a_number)
    {
        int poped;
        while(a_number-->0)
        {
            my_q.dequeue(poped);
        }
    };

    
    std::thread producer(push_safe,1000);
    std::thread consumer(pop_safe, 1000);

    producer.join();
    consumer.join();

    std::cout<<"q size:"<<my_q.size()<<'\n';


    ASSERT_THAT(my_q.size() == 0);


END_TEST






BEGIN_TEST(two_consumers_one_producer)	

    std::cout<<"one consumer one producer\n";

    SafeQueue<int, 3000> my_q;

 auto push_safe = [&my_q](size_t a_number)
    {
        while(a_number-->0)
        {
            my_q.enqueue(a_number);
        }
    };

    auto pop_safe = [&my_q](size_t a_number)
    {
        int poped;
        while(a_number-->0)
        {
            my_q.dequeue(poped);
        }
    };

    
    std::thread producer(push_safe,2000);
    std::thread consumer1(pop_safe, 1000);
    std::thread consumer2(pop_safe, 1000);

    producer.join();
    consumer1.join();
    consumer2.join();

    std::cout<<"q size:"<<my_q.size()<<'\n';


    ASSERT_THAT(my_q.size() == 0);


END_TEST



BEGIN_TEST(one_consumers_two_producer)	

    std::cout<<"one consumer one producer\n";

    SafeQueue<int, 3000> my_q;

 auto push_safe = [&my_q](size_t a_number)
    {
        while(a_number-->0)
        {
            my_q.enqueue(a_number);
        }
    };

    auto pop_safe = [&my_q](size_t a_number)
    {
        int poped;
        while(a_number-->0)
        {
            my_q.dequeue(poped);
        }
    };

    
    std::thread producer1(push_safe,2000);
    std::thread producer2(push_safe,2000);
    std::thread consumer(pop_safe, 4000);

    producer1.join();
    producer2.join();
    consumer.join();
    

    std::cout<<"q size:"<<my_q.size()<<'\n';


    ASSERT_THAT(my_q.size() == 0);


END_TEST


BEGIN_TEST(multi)	

    std::cout<<"one consumer one producer\n";

    SafeQueue<int, 3000> my_q;

 auto push_safe = [&my_q](size_t a_number)
    {
        while(a_number-->0)
        {
            my_q.enqueue(a_number);
        }
    };

    auto pop_safe = [&my_q](size_t a_number)
    {
        int poped;
        while(a_number-->0)
        {
            my_q.dequeue(poped);
        }
    };

    
    std::thread producer1(push_safe,2000);
    std::thread producer2(push_safe,2000);
    std::thread producer3(push_safe,2000);
    std::thread producer4(push_safe,2000);
    std::thread consumer1(pop_safe, 2000);
    std::thread consumer2(pop_safe, 2000);
    std::thread consumer3(pop_safe, 2000);
    std::thread consumer4(pop_safe, 2000);

    producer1.join();
    producer2.join();
    producer3.join();
    producer4.join();
    consumer1.join();
    consumer2.join();
    consumer3.join();
    consumer4.join();

    

    std::cout<<"q size:"<<my_q.size()<<'\n';


    ASSERT_THAT(my_q.size() == 0);


END_TEST



BEGIN_SUITE(Its what you learn after you know it all that counts)
    	
    	TEST(one_consumer_one_producer)	
        TEST(two_consumers_one_producer)	
        TEST(one_consumers_two_producer)
        TEST(multi)	
        

END_SUITE


//  int main()
//  {
//     std::cout<<"one consumer one producer\n";

//     SafeQueue<int, 3000> my_q;

//     auto push_safe = [&my_q](size_t a_number)
//     {
//         while(a_number-->0)
//         {
//             my_q.enqueue(a_number);
//         }
//     };

//     auto pop_safe = [&my_q](size_t a_number)
//     {
//         int poped;
//         while(a_number-->0)
//         {
//             my_q.dequeue(poped);
//         }
//     };
    
//     std::thread producer(push_safe,1000);
//     std::thread consumer(pop_safe, 1000);

//     producer.join();
//     consumer.join();

//     std::cout<<"q size:"<<my_q.size()<<'\n';

//     SafeQueue<int, 3000> my_q;

//     std::vector<std::thread> p_threads;
//     std::vector<std::thread> c_threads;

    //create_producers(my_q, 2, p_threads);
    
    //std::vector<std::vector<int>> all_poped = create_consumers(my_q, 2, c_threads, 2);

    //check_fifo(all_poped);

    //join_producers(p_threads);

    //give_apples(my_q, c_threads);

    //join_consumers(c_threads);


    // add_producers(my_q, threads, 2);
    // add_consumers(my_q, threads, 2);


    // int poped;
    // int vec(1000, 1);


    // for (size_t i = 0; i < 1000; ++i)
    // {
    //     std::cout<<"add"<<'\n';
    //     threads.push_back(std::thread(&SafeQueue<int, 3000>::dequeue, std::ref(my_q), std::ref(poped)));	
    //      std::cout<<"pop"<<'\n';
    //     threads.push_back(std::thread(&SafeQueue<int, 3000>::enqueue, std::ref(my_q), std::ref(vec)));	
    // }
    
    // join_threads(threads);


//     std::cout<<"q size:"<<my_q.size()<<'\n';

//     //my_q.print();


    // return 0;
 //}