#ifndef PROCESS_HPP
#define PROCESS_HPP

#include "work.hpp"


class Processor
{
public:
    Processor(Work& a_client);

    void process();

    void send(int a_client_socket, std::vector<uint8_t> const&  a_data);



private:
    Work& m_client;
};


#endif //PROCESS_HPP