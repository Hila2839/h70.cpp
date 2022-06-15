#ifndef FILEERROR_H
#define FILEERROR_H

#include <string>
#include <iostream>

#include "MachineError.hpp"

/*
class FileError: public MachineError{
public:
    FileError(const char* a_func, const char* a_what);

    virtual ~FileError() throw();

    virtual void print(std::ostream& os) const;

    virtual const char* what() const throw();
    
private:
    std::string m_func;
    std::string m_what;

};
*/
#endif