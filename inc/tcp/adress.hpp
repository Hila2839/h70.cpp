#ifndef ADRESS_HPP
#define ADRESS_HPP

#include <string>

class Adress
{
public:
    Adress(const char* a_ip, int a_port);

    const char* get_ip() const;

    int get_port() const;

private:
    int m_port;
    const char* m_ip;
};





#endif