#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>


class Socket
{

public:
    /**
     * @brief Construct a new socket object and connect client
     * 
     * @param a_server_port 
     * @param a_inet_addr 
     */
    socket(int a_server_port, const char* a_inet_addr);//init and connect

    /**
     * @brief send a massage to server
     * 
     * @param a_data 
     * @param a_size 
     * @return int - to check errors: <0 = send failed
     */
    int send_massage(char &a_data,int const a_size); 

     /**
      * @brief recieve a massage from server
      * 
      * @param a_buffer 
      * @param a_expected_data_len 
      * @return int - to check errors:  <0 = recieve failed
      */
    int recieve_maggage(char& a_buffer, int const a_expected_data_len);

    /**
     * @brief terminate communication with the server
     * 
     */
    void termination();

private:

    int m_sock;
}


struct Massage
{
    enum Tag{};//option for different kinds of massages
//members
    int m_id;
    double m_speed;
    double m_altitude;

//functions

    /**
     * @brief packing the struct in order to send it to server
     * 
     * @param a_buffer with packed massage
     * @return size_t - the packed massage size
     */
    size_t massage_pack(char* a_buffer);

    /**
     * @brief unpack the reply from the server
     * 
     * @param a_buffer to get the massage to
     * @return size_t - the massage size
     */
    size_t massage_unpack(char* a_buffer );

}






