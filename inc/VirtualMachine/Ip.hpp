#ifndef IP_H
#define IP_H

#include <cstddef>

class Ip
{
public:
    Ip();
    void next();
    void prev();
    size_t get_ip() const;
    void jump_to(size_t a_num);
    void operator++();
    void operator--();


private:
    size_t m_ip;
};



#endif