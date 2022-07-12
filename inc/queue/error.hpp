#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <iostream>



class Error
{
public:
    Error(const char* a_func, const char* a_what);

    virtual ~Error() noexcept;

    virtual void print(std::ostream& os) const;

    virtual const char* what() const noexcept;
    
    
private:
    std::string m_func;
    std::string m_what;

};


std::ostream& operator<<(std::ostream& os, Error const& e);


#endif