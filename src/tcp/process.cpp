#include <iostream>
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h>  /*htons*/
#include <unistd.h>     /*close*/
#include <fcntl.h>      /*fcntl*/
#include <sys/select.h> /*select*/

#include "process.hpp"


Processor::Processor(Work& a_client)
: m_client(a_client)
{
}




std::vector<uint8_t> parcer(std::vector<uint8_t> a_message)
{
    size_t size = a_message.size();
    int sum = 0;
    std::vector<uint8_t> answer;
    if(a_message[0] == 'a' &&  a_message[1] == 'd' && a_message[2] == 'd' && a_message[3] == ':')
    {
        for (size_t i = 4; i < size; i++)
        {
            sum += a_message[i];
        }
        answer.push_back(sum);
    }
    else if(a_message[0] == 'm' &&  a_message[1] == 'u' && a_message[2] == 'l' && a_message[3] == ':')
    {
        for (size_t i = 4; i < size; i++)
        {
            sum *= a_message[i];
        }
        answer.push_back(sum);
    }
    else if(a_message[0] == 'g' &&  a_message[1] == 'e' && a_message[2] == 't' && a_message[3] == ':')
    {
        //read from file
        answer.push_back(sum);
    }
    else
    {
        throw "wrong command";
    }
    return answer;
}


void Processor::send(int a_client_socket, std::vector<uint8_t> const&  a_data)
{
    int sent_bytes = ::send(a_client_socket, a_data.data(), a_data.size(), 0);
    std::cout << "sentBytes to client at socket: " << a_client_socket << ", " << sent_bytes << '\n';

	    if(sent_bytes < 0) 
        {
            std::cout << "server send failed\n";
            throw "send failed";
        }
	
}




void Processor::process()
{
    std::vector<uint8_t> message;
    message = m_client.get_massage();
    std::vector<uint8_t>  answer = parcer(message);
    
    int socket = m_client.get_socket();
    this->send(socket, answer);

}