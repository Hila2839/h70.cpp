#ifndef SELECTOR_INTERFACE_HPP
#define SELECTOR_INTERFACE_HPP



namespace net{

class Selector
{
public:
    
    ~Selector() = default;

    virtual void select() = 0;

private:
   
};






}//namespace net

#endif