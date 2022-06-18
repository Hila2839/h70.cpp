#include "OutOfRangeError.hpp" 
    
    
 
    
OutOfRangeError::OutOfRangeError(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{
}


OutOfRangeError::~OutOfRangeError() noexcept//throw()
{}


void OutOfRangeError::print(std::ostream& os) const 
{
        os << m_func << " : " << m_what << '\n';
}

const char* OutOfRangeError::what() const noexcept//throw() 
{
    return m_what.c_str();
}

