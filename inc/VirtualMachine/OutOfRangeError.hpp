#ifndef OUTOFRANGEERROR_H
#define OUTOFRANGEERROR_H

#include <string>
#include <iostream>

#include "MachineError.hpp"


class OutOfRangeError: public MachineError{
public:
    OutOfRangeError(const char* a_func, const char* a_what);

    virtual ~OutOfRangeError() noexcept;//throw();

    virtual void print(std::ostream& os) const;

    virtual const char* what() const noexcept;//throw();
    
private:
    std::string m_func;
    std::string m_what;

};

#endif