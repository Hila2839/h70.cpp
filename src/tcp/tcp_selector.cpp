#include <list>

#include "tcp_selector.hpp"
#include "tcp_client_socket.hpp"


namespace net{

TcpSelector::TcpSelector(TcpServer& a_server)
: m_server(a_server)
{
}




void TcpSelector::is_activate_clients(TcpServer& a_server, fd_set* a_master, fd_set* a_temp, int activity)
{
    std::list<TcpClientSocket*> clients_list = a_server.get_clients();

    auto begin = clients_list.begin();
    auto end = clients_list.end();

    while(begin != end && activity > 0)
    {
        TcpClientSocket* client_socket = (*begin);//->get_socket()
        int client_socket_num = (*begin)->get_socket();
        if(FD_ISSET(client_socket_num, a_temp))
        {
            if(!a_server.check_exsist_client(client_socket))
            {
                a_server.remove_client(begin);
                FD_CLR(client_socket_num, a_master);
            }
            --activity;
        }
        ++begin;
    }
}



void TcpSelector::select()
{
    int listen_socket = m_server.get_socket();
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
                int new_client = m_server.add_new_client();
                if(new_client >= 0)
                {
                    FD_SET(new_client, &master);
                }
                --activity;
            }
            if(activity > 0)
            {
				is_activate_clients(m_server, &master, &temp, activity);
			}
		}	
	}
}





} //net
    


