#include <iostream>
//#include <functional>
#include <vector>
#include <numeric>
//#include <algorithm>
#include <thread>
#include <mutex>
#include <atomic>
//#include <condition_variable>




int sum(std::vector<int> const& a_vector, size_t a_thread_num)
{
    const auto processor_count = std::thread::hardware_concurrency();

    if (a_thread_num > processor_count * 2)
    {
        a_thread_num = processor_count * 2;
    }
    
    std::vector<int> results(a_thread_num, 0);
	std::vector<std::thread> threads;

    auto calc_sum = [](std::vector<int>::const_iterator a_start, 
                            std::vector<int>::const_iterator a_end, int& a_sum)
    { 
        a_sum += std::accumulate(a_start, a_end, 0);
    };

    auto segment_size = a_vector.size() / a_thread_num;	
	auto start = a_vector.begin();
	
	auto result_index = 0;
	while( a_thread_num --> 1)
	{
		auto end = start + segment_size;
		threads.push_back(std::thread(calc_sum, start, end, std::ref(results[result_index++])));		
		start = end;		
	}
	calc_sum(start, a_vector.end(), results[result_index++]);
	
	for (auto& t :  threads)
	{
		t.join();
	}

	return std::accumulate(results.begin(), results.end(), 0);
}





int max(std::vector<int> const& a_vector, size_t a_thread_num)
{
    const auto processor_count = std::thread::hardware_concurrency();

    if (a_thread_num > processor_count * 2)
    {
        a_thread_num = processor_count * 2;
    }
    
    std::vector<int> results(a_thread_num, 0);
	std::vector<std::thread> threads;

    auto calc_max = [](std::vector<int>::const_iterator a_start, 
                            std::vector<int>::const_iterator a_end, int& a_max)
    { 
        while(a_start != a_end)
        {
            if (*a_start > a_max)
            {
                a_max = *a_start;
            }
            ++a_start;
        }
    };

    auto segment_size = a_vector.size() / a_thread_num;	
	auto start = a_vector.begin();
	
	auto result_index = 0;
	while( a_thread_num --> 1)
	{
		auto end = start + segment_size;
		threads.push_back(std::thread(calc_max, start, end, std::ref(results[result_index++])));		
		start = end;		
	}
	calc_max(start, a_vector.end(), results[result_index++]);
	
	for (auto& t :  threads)
	{
		t.join();
	}


    int max = 0;
	for (auto& r :  results)
	{
		if (r > max)
        {
            max = r;
        }
	}
    return max;
}



/*
int find_max(std::vector<int> const& a_vector)
{
    std::atomic<int> max = a_vector[0];
    auto is_max = [&max, &a_vector](size_t a_from, size_t a_to){ 
        
        for(size_t i = a_from; i <a_to; ++i)
        {
            if(a_vector[i] > max)
            {
                max = a_vector[i];
            };
        }
    };

    std::thread t1(is_max, 1, (a_vector.size() / 2));
    std::thread t2(is_max, (a_vector.size() / 2 ), a_vector.size());

    t1.join();
    t2.join();
    //how do i integrate both threads maxes??
    int final_max = max;
    return final_max;

}
*/



int main()
{
    std::vector<int> large;
    for(size_t i = 0; i < 10000; ++i)
    {
        large.push_back(1);
    }

    large.push_back(3);

    for(size_t i = 0; i < 10000; ++i)
    {
        large.push_back(2);
    }

    std::cout<<"sum:"<<sum(large, 4)<<'\n';

    std::cout<<"max:"<<max(large, 4)<<'\n';

    return 0;
}
