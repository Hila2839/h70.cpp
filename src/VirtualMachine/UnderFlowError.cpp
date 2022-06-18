#include "UnderFlowError.hpp" 
    
    
 
    
UnderFlowError::UnderFlowError(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{
}


UnderFlowError::~UnderFlowError() noexcept//throw()
{}


void UnderFlowError::print(std::ostream& os) const 
{
        os << m_func << " : " << m_what << '\n';
}

const char* UnderFlowError::what() const noexcept//throw() 
{
    return m_what.c_str();
}

