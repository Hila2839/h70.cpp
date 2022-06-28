#ifndef UNDERFLOWERROR_H
#define UNDERFLOWERROR_H

#include <string>
#include <iostream>

#include "MachineError.hpp"


class UnderFlowError: public MachineError{
public:
    UnderFlowError(const char* a_func, const char* a_what);

    virtual ~UnderFlowError() noexcept;//throw();

    virtual void print(std::ostream& os) const;

    virtual const char* what() const noexcept;//throw();
    
private:
    std::string m_func;
    std::string m_what;

};

#endif