#ifndef MACHINEERROR_H
#define MACHINEERROR_H

#include <string>
#include <exception>
#include <iostream>

class MachineError: public std::exception{
public:
    //MachineError(const char* a_func, const char* a_what);

    virtual ~MachineError() noexcept;//throw();

    virtual void print(std::ostream& os) const = 0;

    virtual const char* what() const noexcept = 0;//throw() = 0;
 
};


std::ostream& operator<<(std::ostream& os, MachineError const& e);

#endif