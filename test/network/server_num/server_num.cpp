#include <iostream>

#include "tcp_server.hpp"
#include "tcp_server_socket.hpp"
#include "tcp_selector.hpp"

#include "adress.hpp"
#include "handler.hpp"
#include "server_handler_num.hpp"


int main()
{
    try{
        
        Adress adress("127.0.0.1", 5555);
        net::ServerHandlerNum handler(5); 
        net::TcpServer server(adress, &handler);
        net::TcpSelector selector(server); 

        selector.select();

   
    }catch(...)
    {}


return 0;
}