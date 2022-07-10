#include <iostream>

#include "tcp_client_socket.hpp"

#include "server_handler_num.hpp"

#include "adress.hpp"


int main()
{
    try{
        net::TcpClientSocket clien;
        Adress adress("127.0.0.1", 5555);
        clien.bind(adress);
        
        uint8_t x;
        std::vector<uint8_t> message;
        std::cout<<"try to guess the number:\n";
        std::cin>>x;
        message.push_back(x);
       
        clien.send(message);
        clien.recieve();

    }catch(...)
    {}


return 0;
}