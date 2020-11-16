#include "ListNode.h"
#include <string>

#ifndef LIST_H
#define LIST_H

using namespace std;

template <typename T>
class List
{
    public:
        // constructor with 0 parameters
        List();
        // constructor with name parameter
        List(string name);
        // Destructor
        ~List();
        // insert at front of list
        void insert_at_front(T * data);
        // insert at back of list
        void insert_at_back(T * data);
        // remove from front of list
        T * remove_from_front(void);
        // remove from back of list
        T * remove_from_back(void);
        // get the first node in the list
        ListNode<T> * get_first(void);
        
    protected:
        ListNode<T> * first_node;
        ListNode<T> * last_node;
        string name;    
};

// constructor with 0 parameters
template <typename T>
List<T>::List() :
List("List")
{

}

// constructor with name parameter
template <typename T>
List<T>::List(string name) :
first_node(nullptr), last_node(nullptr), name(name)
{

}

template <typename T>
List<T>::~List()
{
    // set current to the start of the list
    ListNode<T> * current = first_node;
    ListNode<T> * previous = nullptr;
    // clean the list until the end
    while(current != nullptr)
    {
        previous = current;
        // set next to traverse through the list
        current = current->get_next();
        // delete the data in the node
        delete previous;
    }
}

// insert at front of list
template <typename T>
void List<T>::insert_at_front(T * data)
{
    // cases
    // 1) empty list
    // 2) list with many elements

    // case 1
    if(first_node == nullptr)
    {
        // set first node to new peice of data
        ListNode<T> * new_node = new ListNode<T>(data, nullptr);
        first_node = new_node;
        // set last node to the new data since there is only one element
        last_node = first_node;
    }
    // case 2
    else
    {
        // set next of new first node to current first node 
        ListNode<T> * new_node = new ListNode<T> (data, first_node);
        first_node = new_node;
    }
}

// insert at back of list
template <typename T>
void List<T>::insert_at_back(T * data)
{
    // cases
    // 1) empty list
    // 2) list with many elements

    // case 1
    if(first_node == nullptr)
    {
        // set last node to the new data
        last_node = new ListNode<T> (data, nullptr);
        // set the first node to the last node since there is only one element
        first_node = last_node;
    }
    // case 2
    else
    {
        // next of last node is 0
        ListNode<T> * new_node = new ListNode<T> (data, nullptr);
        // set current last node to the new instance
        last_node->set_next(new_node);
        // set last node to the new node
        last_node = new_node;
    }
    
}

// remove from front of list
template <typename T>
T * List<T>::remove_from_front(void)
{
    void * removed_data = nullptr;
    // cases
    // 1) empty list
    // 2) one element in list
    // 3) multiple elements in list

    // empty list
    if(first_node == nullptr)
    {
        removed_data = nullptr;
    }
    // one element in list
    else if(first_node == last_node)
    {
        // removed_data holds the address of the first element
        removed_data = first_node;  
        // null first and last node no more elements
        first_node = nullptr;
        last_node  = nullptr;
    }
    // multiple element in list
    else
    {
        // remvoed data holds the address of the first element
        removed_data = first_node;
        // set the 2nd element in the list as the first
        first_node = first_node->get_next();
    }
    return removed_data;
}

// remove from back of list
template <typename T>
T * List<T>::remove_from_back(void)
{
    // cases
    // 1) empty list
    // 2) one element in list
    // 3) multiple elements in list

    void * removed_data = nullptr;

    // empty list
    if(first_node == nullptr)
    {
        removed_data = nullptr;
    }
    // one element in list
    else if(first_node == last_node)
    {
        // removed data holds the address of the last element
        removed_data = last_node;
        // set the last node to null as list is empty
        first_node = nullptr;
        // set the last node to null as list is empty
        last_node = nullptr;
    }
    // multiple elements in list
    else
    {
        ListNode<T> * current = first_node;

        while(current->get_next() != last_node)
        {
            current = current->get_next();
        }

        // removed data holds the address of the current last element in the
        // list
        removed_data = last_node;
        // set the last node to equal to the current variable which is the 
        // second to last element in the list
        last_node = current;
    }
    return removed_data;
}

// get the first node in the list
template <typename T>
ListNode<T> * List<T>::get_first(void)
{
    return first_node;
}
#endif