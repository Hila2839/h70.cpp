#include "adress.hpp"

Adress::Adress(const char* a_ip, int a_port)
: m_port(a_port)
, m_ip(a_ip)
{
}


const char* Adress::get_ip() const
{
    return m_ip;
}

int Adress::get_port() const
{
    return m_port;
}

