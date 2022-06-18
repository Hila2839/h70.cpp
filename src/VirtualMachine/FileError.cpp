#include "FileError.hpp" 
    
    
 
    
FileError::FileError(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{
}


FileError::~FileError() noexcept//throw()
{}


void FileError::print(std::ostream& os) const 
{
        os << m_func << " : " << m_what << '\n';
}

const char* FileError::what() const noexcept//throw() 
{
    return m_what.c_str();
}

