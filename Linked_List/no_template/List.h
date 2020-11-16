#include "ListNode.h"
#include <string>

#ifndef LIST_H
#define LIST_H

using namespace std;

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
        void insert_at_front(void * data);
        // insert at back of list
        void insert_at_back(void * data);
        // remove from front of list
        void * remove_from_front(void);
        // remove from back of list
        void * remove_from_back(void);
        // get the first node in the list
        ListNode * get_first(void);
        
    protected:
        ListNode * first_node;
        ListNode * last_node;
        string name;    
};

#endif