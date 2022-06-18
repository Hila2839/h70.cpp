#include <ostream>


#include "MachineError.hpp"



//MachineError::MachineError(const char* a_func, const char* a_what)
//:m_func(a_func)
//,m_what(a_what)
//{}

MachineError::~MachineError() noexcept//throw() 
{}


std::ostream& operator<<(std::ostream& os, MachineError const& e)
{
    e.print(os);
    return os;
}
