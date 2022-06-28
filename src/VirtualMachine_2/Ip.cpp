#include <cstddef>


#include "Ip.hpp"





Ip::Ip()
: m_ip(0)
{}


void Ip::next()
{
    ++m_ip;
}

void Ip::operator++()
{
    ++m_ip;
}

void Ip::prev()
{
    --m_ip;
}


void Ip::operator--()
{
    --m_ip;
}

size_t Ip::get_ip() const
{
    return m_ip;
}
void Ip::jump_to(size_t a_num)
{
    m_ip = a_num;
}