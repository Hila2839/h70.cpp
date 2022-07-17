#include <iostream>

#include "tcp_server.hpp"
#include "tcp_server_socket.hpp"
#include "tcp_selector.hpp"

#include "adress.hpp"
#include "handler.hpp"
#include "server_handler_push.hpp"
#include "../../inc/queue/safe_q.hpp"
#include "work.hpp"
#include "process.hpp"



int main()
{
    try{
        Adress adress("127.0.0.1", 5555);
        std::vector<std::thread> threads;

        SafeQueue<Work, 1000> my_q;

        net::ServerHandlerPush handler(my_q); 

        net::TcpServer server(adress, &handler);
        net::TcpSelector selector(server); 

        selector.select();


        auto app = [&my_q, &server]()
        {
            while(true)
            {
                Work client;
                my_q.dequeue(client);
                Processor processor(client);
                processor.process();
            }
        };

        
        threads.push_back(std::thread(app));

        for(auto& t: threads)
        {
            t.join();
        }

    

        std::cout<<my_q.size();

   
    }catch(...)
    {}


return 0;
}





