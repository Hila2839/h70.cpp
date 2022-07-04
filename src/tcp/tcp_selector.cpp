#include "tcp_selector.hpp"
#include "tcp_server.hpp"

namespace net{


void is_activate_clients(TcpServer& a_server, fd_set* a_master, fd_set* a_temp, int activity)
{
    std::list<TcpClientSocket*> clients_list = a_server.get_clients();

    auto begin = clients_list.begin();
    auto end = clients_list.end();

    while(begin != end && activity > 0)
    {
        int client_socket = (*begin)->get_socket();
        if(FD_ISSET(client_socket, a_temp))
        {
            if(!a_server.check_exsist_client(client_socket))
            {
                a_server.remove_client(begin);
                FD_CLR(client_socket, a_master);
            }
            --activity;
        }
        ++begin;
    }
}



void TcpSelector::select(TcpServer& a_server)
{
    int listen_socket = a_server.get_socket();
    fd_set master;
	fd_set temp;

    FD_ZERO(&master);
	FD_SET(listen_socket, &master);
	
	while(1)
	{
		FD_ZERO(&temp);
		temp = master;

		int activity = ::select(1025, &temp, nullptr, nullptr, nullptr);
		if(activity < 0)
		{
            throw "selection failed";
        }

        if(activity > 0)
		{
			if(FD_ISSET(listen_socket, &temp))
			{
                int new_client = a_server.add_new_client();
                if(new_client >= 0)
                {
                    FD_SET(new_client, &master);
                }
                --activity;
            }
            if(activity > 0)
            {
				is_activate_clients(a_server, &master, &temp, activity);
			}
		}	
	}
}





} //net
    


