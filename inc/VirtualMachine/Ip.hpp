#ifndef IP_H
#define IP_H

#include <cstddef>

class Ip
{
public:
    Ip();
    void next();
    void prev();
    size_t get_ip();
    void set_ip(size_t a_num);


private:
    size_t m_ip;
};



#endif