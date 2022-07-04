#include "tcp_client_socket.hpp"

#include "server_handler_string.hpp"

#include "adress.hpp"


int main()
{
    try{
        net::TcpClientSocket clien;
        Adress adress("127.0.0.1", 5555);
        clien.bind(adress);
        
        std::vector<uint8_t> message;
        message.push_back('u');
        message.push_back('p');
        message.push_back('p');
        message.push_back('e');
        message.push_back('r');
        clien.send(message);

    }catch(...)
    {}


return 0;
}