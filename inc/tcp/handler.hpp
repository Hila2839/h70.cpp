#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <stdint.h>
#include <vector>

namespace net{


class Handler
{
public:
    virtual ~Handler();

    virtual std::vector<uint8_t> handle(std::vector<uint8_t> const& a_message, size_t a_read_bytes) = 0;

private:

};


}//namespace net


#endif