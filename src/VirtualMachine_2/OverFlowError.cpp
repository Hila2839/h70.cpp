#include "OverFlowError.hpp" 
    
    
 
    
OverFlowError::OverFlowError(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{
}


OverFlowError::~OverFlowError() noexcept//throw()
{}


void OverFlowError::print(std::ostream& os) const 
{
        os << m_func << " : " << m_what << '\n';
}

const char* OverFlowError::what() const noexcept//throw() 
{
    return m_what.c_str();
}

