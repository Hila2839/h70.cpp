#include <ostream>


#include "MachineError.hpp"

/*

MachineError::MachineError(const char* a_func, const char* a_what)
:m_func(a_func)
,m_what(a_what)
{}

MachineError::~MachineError() 
{}

void MachineError::print(std::ostream& os) const 
{
        os << m_func << " : " << m_what << '\n';
}

const char* MachineError::what() const //throw() 
{
    return m_what.c_str();
}*/