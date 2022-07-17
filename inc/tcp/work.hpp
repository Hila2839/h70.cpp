#ifndef WORK_HPP
#define WORK_HPP

#include <vector>
#include "tcp_client_socket.hpp"


class Work
{
public:
    Work();
    Work(Work&& a_other);
    Work(net::TcpClientSocket* a_client_socket_p, std::vector<uint8_t> const& a_message);
    std::vector<uint8_t> const& get_massage();
    int get_socket();
    Work& operator=(Work&& a_other);

    


private:
    net::TcpClientSocket* m_client_socket_p;
    std::vector<uint8_t> const& m_message;
};




#endif //WORK_HPP