#ifndef SLIST_H
#define SLIST_H 

#include <cstddef>
#include <iostream>

namespace adt
{

template<typename T>
class List{
public:    
    List();
   
    int get_size() const;
    T const& front_value() const;
    T const& back_value() const;
    T const& front_value() ;
    T const& back_value() ;
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
    //Node* reverse();
    

    T get_value() const;
private:

//class node
class Node
{
public:
    Node();
    T& get_value();
    //T* get_next_value(Node* a_node) const;
    void set_value(T a_value);
    void set_next_value(T* a_value) ;
    Node* get_next() const;
    void set_next(Node* a_node) ;
    //Node* reverse(Node* a_head );


 
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
    //assert(m_size > 0 && "empty list"); 
    return m_head;
}


template<typename T>
typename List<T>::Node* List<T>::back() const
{
    //assert(m_size > 0 && "empty list"); 
    return m_tail;
}

template<typename T>
T const& List<T>::front_value() const
{
    return m_head.get_value();
}


template<typename T>
T const& List<T>::back_value() const
{
    return m_tail.get_value();
}

template<typename T>
T const& List<T>::front_value() 
{
    return m_head->get_value();;
}


template<typename T>
T const& List<T>::back_value() 
{
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
    Node* head = a_list.front();
    while(head->get_next() != 0)
    {
        preppend(head->get_value());
        head = head->get_next();
    }
    preppend(head->get_value()); 

}

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
        printf("%d",temp->get_value());
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
/*

template<typename T>
typename List<T>::Node* List<T>::Node::reverse(List<T>::Node* a_head )
{
    Node* temp_head;
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
typename List<T>::Node*  List<T>::reverse()
{
    Node* temp_head = front();
    if(temp_head->get_next() == 0)
    {
        return front();
    }
    temp_head = reverse(temp_head->get_next());
    (temp_head->get_next())->set_next(temp_head);
    temp_head->set_next(0);
    return temp_head;
}


*/






}//namespace adt



#endif
