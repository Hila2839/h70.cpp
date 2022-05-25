#include <cassert>

#include "message.hpp"

#define ID_SIZE 9


struct Massage
{
    enum Tag{};//option for different kinds of massages
//members
    int m_id;
    double m_speed;
    double m_altitude;
//functions

    /**
     * @brief a member function to send a massage to server
     * 
     */
    void send_massage() const;

}


size_t massage_pack(Massage::Massage const& a_msg, char& a_buffer) const
{
    char *packageRunner = NULL;
    char id_size = ID_SIZE;
    char totalSize = ID_SIZE + 2;

    assert(a_buffer && "buffer is NULL");
    
    packageRunner = a_buffer;

    //*packageRunner = TAG;
    //packageRunner ++;

    *packageRunner =  totalSize;

    packageRunner ++;
    strcpy(packageRunner, a_msg.m_id);

    packageRunner += ID_SIZE;
    *packageRunner  = a_msg.m_speed;

    packageRunner ++;
    *packageRunner =  a_msg.m_altitude;

   
    return totalSize ;
}



void Massage::send_massage(int a_port, int a_adress) const
{
    Socket sock(a_port, a_adress);

    char buffer[254] = {0};

    int size = massage_pack(buffer);

    send_massage(buffer, size); 

    termination();

}
