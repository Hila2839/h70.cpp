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
    int send_massage(char& a_data, int const a_size); 

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
};




//functions

    /**
     * @brief packing the struct in order to send it to server
     * 
     * @param a_buffer to pack massage to
     * @param  a_msg -a massage to send
     * @return size_t - the packed massage size
     */
    size_t massage_pack(Massage::Massage const& a_msg, char* a_buffer) const;

    /**
     * @brief unpack the reply from the server
     * 
     * @param a_buffer to get the massage to
     * @param  a_msg -a massage to recievr information to
     * @return size_t - the massage size
     */
    size_t massage_unpack(Massage const& a_msg, char* a_buffer );







