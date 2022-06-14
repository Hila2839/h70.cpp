#include <cstddef>


#include "Ip.hpp"





Ip::Ip()
: m_ip(0)
{}


void Ip::next()
{
    ++m_ip;
}


void Ip::prev()
{
    --m_ip;
}

size_t Ip::get_ip()
{
    return m_ip;
}
void Ip::set_ip(size_t a_num)
{
    m_ip = a_num;
}