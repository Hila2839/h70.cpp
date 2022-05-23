#ifndef SLIST_H
#define SLIST_H 

#include <cstddef>
#include <iostream>
#include <cassert>
#include <algorithm>

namespace adt
{

template<typename T>
class List{
public:

    List();
   
    int get_size() const;


    T const& front_value() const;
    T const& back_value() const;

    T& front_value() ;
    T& back_value() ;


    void preppend(T const& a_value);
    void preppend(List<T> const& a_list);

    void append(T const& a_value);
    void append(List<T> const& a_list); 


    T remove_front();
    T remove_back();


    void print() const;


    T get_next_value(T const& a_node) const ;


    List<T>& operator<<( T const& a_value);

    bool operator==(List<T> const& a_other_list) const;

    bool operator>(List<T> const& a_other_list) const;

    List<T>& reverse();


    void for_each_c(void (*action)(T& a_value, void* a_context), void* a_context);


    class Itr;
    class ConstItr;

    const  ConstItr begin() const;
    const  ConstItr end() const;

    Itr begin();
    Itr end();


    T get_value() const;

private:
   
//class node
class Node
{
public:

    Node();

    T& get_value();

    void set_value(T a_value);

    void set_next_value(T* a_value) ;

    Node* get_next() const;

    void set_next(Node* a_node) ;

    Node* reverse(Node* a_head );


 
private:

    T m_value;
    Node* m_next;

};

// list members

    Node* m_head;
    Node* m_tail;
    size_t m_size;


//private functions

Node* front() const;
Node* back() const;
Node* reverse(Node* a_head);


};

//class iterator

template<typename T>
class List<T>::Itr
{
public:
    Itr(Node* m_current);

    Itr& operator++();
    const T& operator*();
     

    bool operator==(Itr const& a_itr) const;
    bool operator!=(Itr const& a_itr) const;


private:
    Node* m_current;

};

template<typename T>
class List<T>::ConstItr
{
public:
    ConstItr(const Node* m_current);

    ConstItr const& operator++() const;
    const T& operator*() const;

    const bool operator==(Itr const& a_itr) const;
    const bool operator!=(Itr const& a_itr) const;

    

private:
    Node* m_current;

};



//Node constructor
template<typename T>
 List<T>::Node::Node()
: m_next(0)
 {
 }
//List constructor
template<typename T>
List<T>::List()
:m_head(0)
, m_tail(0)
, m_size(0)
{
}
/*
Node::~Node()
{
    delete[]
}
*/




template<typename T>
T& List<T>::Node::get_value() 
{ 
    return m_value;
}

template<typename T>
void List<T>::Node::set_value(T a_value) 
{ 
    m_value = a_value;
}


template<typename T>
void List<T>::Node::set_next( List<T>::Node* a_node) 
{ 
    m_next = a_node;
}
template<typename T>
void List<T>::Node::set_next_value(T* a_value) 
{
    m_next.m_value = a_value;
}

template<typename T>
typename List<T>::Node* List<T>::Node::get_next() const 
{ 
    return m_next;
}



template<typename T>
typename List<T>::Node* List<T>::front() const
{
    assert(m_size > 0 && "empty list"); 
    return m_head;
}


template<typename T>
typename List<T>::Node* List<T>::back() const
{
    assert(m_size > 0 && "empty list"); 
    return m_tail;
}

template<typename T>
T const& List<T>::front_value() const
{
    assert(m_size > 0 && "empty list"); 
    return m_head.get_value();
}


template<typename T>
T const& List<T>::back_value() const
{
    assert(m_size > 0 && "empty list"); 
    return m_tail.get_value();
}

template<typename T>
T& List<T>::front_value() 
{
    assert(m_size > 0 && "empty list"); 
    return m_head->get_value();;
}


template<typename T>
T& List<T>::back_value() 
{
    assert(m_size > 0 && "empty list"); 
    return m_tail->get_value();;
}

template<typename T>
int List<T>::get_size() const
{
    return m_size;
}

 

//add option to get list
template<typename T>
void List<T>::preppend(T const& a_value) //not const because of m_size++
{
    Node* node = new Node[1];
    node->set_value(a_value);
    if(m_size == 0)
    {
        m_head = node;
        m_tail = node;
        m_size++;
    }
    else
    {
        node->set_next(m_head);
        m_head = node;
        m_size++;
    }
}


template<typename T>
void List<T>::preppend(List<T> const& a_list)
{
    List<T> copy;
    copy.append(a_list);

    copy.reverse();

    Node* head = copy.front();

    while(head->get_next() != 0)
    {
        preppend(head->get_value());
        head = head->get_next();
    }
    preppend(head->get_value());
}


/*
    Node* tail = a_list.back();
    for (size_t i = 0; i < a_list.m_size; i++)
    {
        Node* look_for_new_tail = a_list.front();
        preppend(tail->get_value());
        while(look_for_new_tail->get_next() != 0)
        {
            look_for_new_tail = look_for_new_tail->get_next();
        }
        tail = look_for_new_tail;
    }
}*/

//add option to get list
template<typename T>
void List<T>::append(T const& a_value) //not const because of m_size++
{
    Node* node = new Node[1];
    node->set_value(a_value);
    if(m_size == 0)
    {
        m_head = node;
    }
    else
    {
        m_tail->set_next(node);
        node->set_next(0);
    }
    m_tail = node;
    m_size++;
}
/*
template<typename T>
void List<T>::append(T const& a_value) //not const because of m_size++
{
    Node* node = new Node[1];
    node->set_value(a_value);
    Node* temp = m_head;
    if(m_size == 0)
    {
        m_head = node;
        m_tail = node;
        m_size++;
    }
    else
    {
        while(temp->get_next() != 0)
        {
             temp = temp->get_next();
        }
        temp->set_next(node);
        node->set_next(0);
        m_tail = node;
        m_size++;
    }
}

*/
template<typename T>
void List<T>::append(List<T> const& a_list)
{
   Node* head = a_list.front();
    while(head->get_next() != 0)
    {
        append(head->get_value());
        head = head->get_next();
    }
    append(head->get_value());
   
}



template<typename T>
T List<T>::remove_front() //not const because of m_size--
{
    //assert(m_size > 0 && "empty list");
    Node* temp = m_head;
    T value = m_head->get_value();
    m_head = temp->get_next();
    m_size--;
    delete[] temp;
    return value;
}


//remove tail
 //Node* temp = m_head;
 //   m_head->set_next(temp->get_next());
 //   m_size--;

template<typename T>
T List<T>::remove_back() //not const because of m_size--
{
    //assert(m_size > 0 && "empty list");
    Node* runner = m_head;
    Node* temp = m_tail;
    T value = m_tail->get_value();
    while(runner->get_next()->get_next() != 0)
    {
        runner = runner->get_next();
    }
    runner->set_next(0);
    m_tail = runner;
    m_size--;
    delete[] temp;
    return value;
}


template<typename T>
void List<T>::print() const
{
    Node* temp = m_head;
    for (size_t i = 0; i < m_size; i++)
    {
        std::cout << temp->get_value();
         temp = temp->get_next();
    }
    std::cout << "\n";
}



template<typename T>
List<T>& List<T>::operator<<( T const& a_value)
{
    append(a_value);
    return *this;
}



template<typename T>
bool List<T>::operator==(List<T> const& a_other_list) const //not const because of m_size++
{
    if (get_size() != a_other_list.get_size())
    {
        return false;
    }
    Node* temp = front();
    Node* other_temp = a_other_list.front();

    while(temp->get_next() != 0)
    {
        if(temp->get_value() != other_temp->get_value())
        {
            return false;
        }
        temp = temp->get_next();
        other_temp = other_temp->get_next();
    }
    return true;
}



template<typename T>
bool operator!=(List<T> const& a_list, List<T> const& a_other_list) 
{
   return !(a_list == a_other_list);
}



template<typename T>
bool List<T>::operator>(List<T> const& a_other_list) const
{
    Node* temp = front();
    Node* other_temp = a_other_list.front();
    if(*this == a_other_list)
    {
        return false;
    }
    while(temp->get_next() != 0 && other_temp->get_next() != 0 )
    {
        if(temp->get_value() < other_temp->get_value())
        {
            return false;
        }
        temp = temp->get_next();
        other_temp = other_temp->get_next();
    }
    return true;
}


template<typename T>
bool operator>=(List<T> const& a_list, List<T> const& a_other_list) 
{
    if(a_list == a_other_list)
    {
        return true;
    }
    return a_list > a_other_list;
}


template<typename T>
bool operator<(List<T> const& a_list, List<T> const& a_other_list) 
{
    if(!(a_list >= a_other_list))
    {
        return true;
    }
    return false;
}


template<typename T>
bool operator<=(List<T> const& a_list, List<T> const& a_other_list) 
{
    if(a_list == a_other_list)
    {
        return true;
    }
    return a_list < a_other_list;
}


template<typename T>
List<T>& List<T>::reverse()
{
    m_tail = m_head;
    Node* temp_head = front();
    m_head = reverse(temp_head);
    return *this;
}


template<typename T>
typename List<T>::Node*  List<T>::reverse(List<T>::Node* a_head)
{
    Node* temp_head = a_head;
    if(a_head->get_next() == 0)
    {
        return a_head;
    }
    temp_head = reverse(a_head->get_next());
 
    (a_head->get_next())->set_next(a_head);
    a_head->set_next(0);
    return temp_head;
}


template<typename T>
void List<T>::for_each_c(void (*action)(T& a_value, void* a_context), void* a_context)
{
    Node* current = m_head;
    while(current != 0)
    {
        action(current->get_value(), a_context);
        current = current->get_next();
    }
}

/*
for_each(begin(), end(), *)
{

}

*/

//iterator and const iterator constructor
template<typename T>
 List<T>::Itr::Itr(Node* m_current)
: m_current(m_head)//front
{
}

template<typename T>
 List<T>::ConstItr::ConstItr(const Node* m_current)
: m_current(m_head)//front
{
}



template<typename T>
typename List<T>::Itr& List<T>::Itr::operator++()
 {
     m_current = m_current.get_next();
     return *this;
 }



template<typename T>
typename List<T>::ConstItr const& List<T>::ConstItr::operator++() const
 {
     m_current = m_current.get_next();
     return *this;
 }


template<typename T>
const T& List<T>::Itr::operator*()
{
    return m_current.get_value();
}

template<typename T>
 const T& List<T>::ConstItr::operator*() const
{
    return m_current.get_value();
}

template<typename T> 
typename List<T>::Itr List<T>::begin()
{
    Itr itr(front);
    return itr;
}



template<typename T> 
 const typename List<T>::ConstItr List<T>::begin() const
{
    ConstItr itr(front);
    return itr;
}


template<typename T> 
typename List<T>::Itr List<T>::end()
{
    Node* tail_node = back();
    m_tail->set_next(tail_node);

    tail_node->set_next(tail_node);
    tail_node->set_value(0);

    return tail_node;
}



template<typename T> 
 const typename List<T>::ConstItr List<T>::end() const
{
    
    Node* tail_node = back();
    m_tail->set_next(tail_node);

    tail_node->set_next(tail_node);
    tail_node->set_value(0);

    return tail_node;
}

template<typename T> 
bool List<T>::Itr::operator==(Itr const& a_itr) const
{
    if(get_value() == a_itr.get_value())
    {
        return true;
    }
    return false;
}

 template<typename T> 
 const bool List<T>::ConstItr::operator==(Itr const& a_itr) const
 {
     if(get_value() == a_itr.get_value())
    {
        return true;
    }
    return false;
 }

template<typename T> 
bool List<T>::Itr::operator!=(Itr const& a_itr) const
{
    if(get_value() != a_itr.get_value())
    {
        return true;
    }
    return false;
}

 template<typename T> 
 const bool List<T>::ConstItr::operator!=(Itr const& a_itr) const
 {
     if(get_value() != a_itr.get_value())
    {
        return true;
    }
    return false;
 }




}//namespace adt



#endif
