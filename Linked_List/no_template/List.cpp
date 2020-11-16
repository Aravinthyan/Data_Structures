#include "List.h"
#include "ListNode.h"
#include <string>

using namespace std;

// constructor with 0 parameters
List::List() :
List("List")
{

}

// constructor with name parameter
List::List(string name) :
first_node(nullptr), last_node(nullptr), name(name)
{

}

List::~List()
{
    // set current to the start of the list
    ListNode * current = first_node;
    ListNode * to_delete;
    // clean the list until the end
    while(current != nullptr)
    {
        to_delete = current;
        // set next to traverse through the list
        current = current->get_next();
        // delete the data in the node
        delete to_delete;
    }
}

// insert at front of list
void List::insert_at_front(void * data)
{
    // cases
    // 1) empty list
    // 2) list with many elements

    // case 1
    if(first_node == nullptr)
    {
        // set first node to new peice of data
        first_node = new ListNode(data, nullptr);
        // set last node to the new data since there is only one element
        last_node = first_node;
    }
    // case 2
    else
    {
        // set next of new first node to current first node 
        first_node = new ListNode(data, first_node);
    }
}

// insert at back of list
void List::insert_at_back(void * data)
{
    // cases
    // 1) empty list
    // 2) list with many elements

    // case 1
    if(first_node == nullptr)
    {
        // set last node to the new data
        last_node = new ListNode(data, nullptr);
        // set the first node to the last node since there is only one element
        first_node = last_node;
    }
    // case 2
    else
    {
        // next of last node is 0
        ListNode * new_node = new ListNode(data, nullptr);
        // set current last node to the new instance
        last_node->set_next(new_node);
        // set last node to the new node
        last_node = new_node;
    }
    
}

// remove from front of list
void * List::remove_from_front(void)
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
void * List::remove_from_back(void)
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
        ListNode * current = first_node;

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
ListNode * List::get_first(void)
{
    return first_node;
}