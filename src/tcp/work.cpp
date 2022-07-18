// #include <vector>

// #include "work.hpp"
// #include "tcp_client_socket.hpp"


// Work::Work(net::TcpClientSocket* a_client_socket_p, std::vector<uint8_t> const& a_message)
// : m_client_socket_p(a_client_socket_p)
// , m_message(a_message)
// {
// }

// Work::Work()
// {
// }

// Work::Work(Work&& a_other)
// : m_client_socket_p(a_other.m_client_socket_p)
// , m_message(a_other.m_message)
// {
// }

// std::vector<uint8_t> const& Work::get_massage()
// {
//     return m_message;
// }


// int Work::get_socket()
// {
//         return m_client_socket_p->get_socket();
// } 

// Work& Work::operator=(Work&& a_other)
// {
//     Work copy(a_other);
//     *this = std::move(copy);
//     // if(this != a_other)
//     // {
//     //     m_client_socket_p = a_other.m_client_socket_p;
//     //     m_message = a_other.m_message;
//     // }
//     return *this;
// }