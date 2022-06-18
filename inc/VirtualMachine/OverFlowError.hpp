#ifndef OVERFLOWERROR_H
#define OVERFLOWERROR_H

#include <string>
#include <iostream>

#include "MachineError.hpp"


class OverFlowError: public MachineError{
public:
    OverFlowError(const char* a_func, const char* a_what);

    virtual ~OverFlowError() noexcept; //throw();

    virtual void print(std::ostream& os) const;

    virtual const char* what() const noexcept; //throw();
    
private:
    std::string m_func;
    std::string m_what;

};

#endif