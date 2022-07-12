
#ifndef SAFEQUEUE_HPP
#define SAFEQUEUE_HPP

#include <iostream>
#include <queue>
#include <mutex>
#include <list>
#include <memory>
#include <condition_variable>

#include "semaphore.hpp"


template <typename T, size_t Size>
class SafeQueue
{
public:
	SafeQueue();
	~SafeQueue();

	//SafeQueue(SafeQueue<T, Size>&& a_other) = delete;
	SafeQueue(SafeQueue<T, Size> const& a_other);

	 SafeQueue& operator=(SafeQueue<T, Size> const& a_other);
	 //SafeQueue& operator=(SafeQueue<T, Size>&& a_other) = delete;

	bool dequeue(T& a_popped);
	bool try_dequeue(T& a_popped);
	void enqueue(T const& a_element);

	size_t size() const;
    size_t dirty_size() const;

    bool is_empty() const;

	void print() const;

private:
	std::queue<T> m_q;
	mutable std::mutex m_mtx;
	Semaphore m_present_count;
	Semaphore m_element_count;
};

template <typename T, size_t Size>
SafeQueue<T, Size>::SafeQueue()
: m_present_count(0)
, m_element_count(Size)
{
}

template <typename T, size_t Size>
SafeQueue<T, Size>::SafeQueue(SafeQueue<T, Size> const& a_other)
: m_present_count(0)
, m_element_count(Size)
{
	std::unique_lock<std::mutex> guard(m_mtx);
	std::lock_guard<std::mutex> other_guard(a_other.m_mtx);

	m_q = a_other.m_q;
}

template <typename T, size_t Size>
SafeQueue<T, Size>::~SafeQueue()
{
    std::unique_lock<std::mutex> guard(m_mtx);
}



template <typename T, size_t Size>
bool SafeQueue<T, Size>::try_dequeue(T& a_popped)
{
	if(m_present_count.try_wait())
	{
		if(m_mtx.try_lock())
		{
			a_popped = std::move(m_q.front());
        	m_q.pop();
			m_mtx.unlock();
    		m_element_count.Release();
        	return true;
		}
		else
		{
			m_present_count.Release();
		}
	}
	return false;
}


template <typename T, size_t Size>
bool SafeQueue<T, Size>::dequeue(T& a_popped)
{
	m_present_count.Wait();

	m_mtx.lock();
    //if (!m_q.empty())
 
	a_popped = std::move(m_q.front());
    m_q.pop();
		
        
    
    m_mtx.unlock();
    m_element_count.Release();

	return false;
}

template <typename T, size_t Size>
void SafeQueue<T, Size>::enqueue(T const& a_element)
{
	m_element_count.Wait();
	m_mtx.lock();

	m_q.push(a_element);

	m_mtx.unlock();
	m_present_count.Release();

}

template <typename T, size_t Size>
size_t SafeQueue<T, Size>::size() const
{
	std::unique_lock<std::mutex> guard(m_mtx);
	return m_q.size();
}


template <typename T, size_t Size>
bool SafeQueue<T, Size>::is_empty() const
{
	return m_q.empty();
}


template <typename T, size_t Size>
size_t SafeQueue<T, Size>::dirty_size() const
{
	return m_q.size();
}


#endif //SAFEQUEUE_HPP
