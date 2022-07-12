#include "error.hpp" 
    
    
 
    
Error::Error(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{
}


Error::~Error() noexcept
{}


void Error::print(std::ostream& os) const 
{
        os << m_func << " : " << m_what << '\n';
}

const char* Error::what() const noexcept
{
    return m_what.c_str();
}


std::ostream& operator<<(std::ostream& os, Error const& e)
{
    e.print(os);
    return os;
}
