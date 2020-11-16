#include "ListNode.h"

// constructor with 0 parameters
ListNode::ListNode() :
ListNode(nullptr, nullptr)
{

}

// constructor with 2 parameters
ListNode::ListNode(void * data, ListNode * next) : 
data(data), next(next)
{

}

// Destructor
ListNode::~ListNode()
{
    // delete the data it holds only
    delete data;
}

// set data the data for this node
void ListNode::set_data(void * data)
{
    this->data = data;
}

// get data the data in this node
void * ListNode::get_data(void)
{
    return this->data;
}

// set next the node
void ListNode::set_next(ListNode * next)
{
    this->next = next;
}

// get the next node
ListNode * ListNode::get_next(void)
{
    return this->next;
}