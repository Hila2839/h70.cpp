#ifndef SLIST_H
#define SLIST_H 




#include <cstddef>
#include <iostream>




namespace adt
{

template<typename T>
class Node
{
public:
    Node();
    T get_value() const;
    Node<T>* get_next() const;
    void add_value(T a_value);
    void put_next(Node<T>* a_node) ;
  /*template<typename T>
  struct Node
  {
      Tm_data;
      Node*m_next;

  }  ;*/




private:
    T m_value;
    Node<T>* m_next;



};


template<typename T>
class List{
public:    
    List();
    Node<T>* front() const;
    Node<T>* back() const;
    int get_size() const;
    void preppend(T a_value);
    void preppend(T& a_list);
    void append(T a_value) ;
    void append(List<T>& a_list);
    void remove_front();
    void remove_back();
    void print() const;
    Node<T>& get_tail() const;
    T get_next_value(Node<T>& a_node) const ;
    List<T>& operator<<( T a_value);
    Node<T>* reverse(Node<T>* a_head);

    T get_value() const;
private:
    Node<T>* m_head;
    Node<T>* m_tail;
    size_t m_size;
};


//Node constructor
template<typename T>
 Node<T>::Node()
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

template<typename T>
T Node<T>::get_value() const 
{ 
    return m_value;
}

template<typename T>
void Node<T>::add_value(T a_value) 
{ 
    m_value = a_value;
}

template<typename T>
void Node<T>::put_next(Node<T>* a_node) 
{ 
    m_next = a_node;
}

template<typename T>
Node<T>* Node<T>::get_next() const 
{ 
    return m_next;
}

template<typename T>
T List<T>::get_next_value(Node<T>& a_node) const 
{ 
    return a_node.get_next().get_value();
}


template<typename T>
Node<T>* List<T>::front() const
{
    //assert(m_size > 0 && "empty list"); 
    return m_head;
}


template<typename T>
Node<T>* List<T>::back() const
{
    //assert(m_size > 0 && "empty list"); 
    return m_tail;
}

template<typename T>
int List<T>::get_size() const
{
    return m_size;
}

 

//add option to get list
template<typename T>
void List<T>::preppend(T a_value) //not const because of m_size++
{
    Node<T>* node = new Node<T>[1];
    node->add_value(a_value);
    if(m_size == 0)
    {
        m_head = node;
        m_tail = node;
        m_size++;
    }
    else
    {
        node->put_next(m_head);
        m_head = node;
        m_size++;
    }
}


template<typename T>
void List<T>::preppend(T& a_list)
{
    a_list->m_tail.put_next(m_head);
    m_head = a_list.front();

}

//add option to get list
template<typename T>
void List<T>::append(T a_value) //not const because of m_size++
{
    Node<T>* node = new Node<T>[1];
    node->add_value(a_value);
    Node<T>* temp = m_head;
    if(m_head == 0)
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
        temp->put_next(node);
        node->put_next(0);
        m_tail = node;
        m_size++;
    }
}


template<typename T>
void List<T>::append(List<T>& a_list) //not const because of m_size++
{
    m_tail->put_next(a_list.front());
    m_tail = a_list.back();
    m_size += a_list.get_size();

}



template<typename T>
void List<T>::remove_front() //not const because of m_size--
{
    //assert(m_size > 0 && "empty list");
    Node<T>* temp = m_head;
    m_head = temp->get_next();
    m_size--;
    delete[] temp;
    //return temp;
}
//remove tail
 /*Node<T>* temp = m_head;
    m_head->put_next(temp->get_next());
    m_size--;
*/
template<typename T>
void List<T>::remove_back() //not const because of m_size--
{
    //assert(m_size > 0 && "empty list");
    Node<T>* runner = m_head;
    Node<T>* temp = m_tail;
    while(runner->get_next()->get_next() != 0)
    {
        runner = runner->get_next();
    }
    runner->put_next(0);
    m_tail = runner;
    m_size--;
    delete[] temp;
    //return temp;
}


template<typename T>
void List<T>::print() const
{
    Node<T>* temp = m_head;
    for (size_t i = 0; i < m_size; i++)
    {
        printf("%d",temp->get_value());
         temp = temp->get_next();
    }
    std::cout << "\n";
}


//template<typename T> List<T>& operator<<(List<T>* a_list, T a_value);


/*template<typename T>
 List<T>& operator<<(List<T> a_list, T a_value)
{
    append(a_value);
    return ;
}*/






template<typename T>
bool operator==(List<T> const& a_list, List<T> const& a_other_list) //not const because of m_size++
{
    if (a_list.get_size() != a_other_list.get_size())
    {
        return false;
    }
    Node<T>* temp = a_list.front();
    Node<T>* other_temp = a_other_list.front();

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
bool operator>(List<T> const& a_list, List<T> const& a_other_list) 
{
    Node<T>* temp = a_list.front();
    Node<T>* other_temp = a_other_list.front();
    if(a_list == a_other_list)
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
Node<T>* List<T>::reverse(Node<T>* a_head )
{
    Node<T>* temp_head;
    if(a_head->get_next() == 0)
    {
        return a_head;
    }
    temp_head = reverse(a_head->get_next());
    (a_head->get_next())->put_next(a_head);
    a_head->put_next(0);
    return temp_head;
}









}//namespace adt



#endif
