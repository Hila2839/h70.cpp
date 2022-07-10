
#ifndef SAFEQ_HPP
#define SAFEQ_HPP

#include <iostream>
#include <queue>
#include <mutex>
#include <semaphore>
#include <list>
#include <memory>
#include <condition_variable>


template <typename T>
class SafeQ
{
public:
	SafeQ();
	~SafeQ();

	SafeQ(SafeQ<T>const& a_other);
	SafeQ(SafeQ<T>&& a_other) = delete;

	SafeQ<T>& operator=(SafeQ<T>const& a_other);
	SafeQ<T>& operator=(SafeQ<T>&& a_other) = delete;

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
	std::binary_semaphore m_smph;
};

template <typename T>
SafeQ<T>::SafeQ()
: m_smph(0)
{

}

template <typename T>
SafeQ<T>::SafeQ(SafeQ<T> const& a_other)
: m_smph(0)
{
	std::unique_lock<std::mutex> guard(m_mtx);
	std::lock_guard<std::mutex> other_guard(a_other.m_mtx);

	m_q = a_other.m_q;
}

template <typename T>
SafeQ<T>::~SafeQ()
{
    std::unique_lock<std::mutex> guard(m_mtx);
}


/*
template <typename T>
bool SafeQ<T>::try_dequeue(T& a_popped)
{
	std::unique_lock<std::mutex> guard(m_mtx);

	auto not_empty = [this]()
	{
		return !(m_q.empty());
	};

	std::condition_variable cv;

	cv.wait(guard, not_empty);

	try
	{
		a_popped = m_q.front();
		m_q.pop();
	}
	catch(...)
	{
		return 0;
	}

	return 1;
}
*/

template <typename T>
bool SafeQ<T>::dequeue(T& a_popped)
{
	m_smph.acquire();

    if (!m_q.empty())
    { 
	    a_popped = std::move(m_q.front());
        m_q.pop();
        return true;
    }
    
    m_smph.release();

	return false;
}

template <typename T>
void SafeQ<T>::enqueue(T const& a_element)
{
	std::unique_lock<std::mutex> guard(m_mtx);
	m_q.push(a_element);

	m_smph.release();

}

template <typename T>
size_t SafeQ<T>::size() const
{
	std::unique_lock<std::mutex> guard(m_mtx);
	return m_q.size();
}


template <typename T>
bool SafeQ<T>::is_empty() const
{
	return m_q.empty();
}


template <typename T>
size_t SafeQ<T>::dirty_size() const
{
	return m_q.size();
}


#endif //SAFEQ_HPP
