#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode
{
    public:
        // constructor with 0 parameters
        ListNode();
        // constructor with 2 parameters
        ListNode(void * data, ListNode * next);
        // Destructor
        ~ListNode();
        // set data the data for this node
        void set_data(void * data);
        // get data the data in this node
        void * get_data(void);
        // set next the node
        void set_next(ListNode * next);
        // get the next node
        ListNode * get_next(void);

    private:
        // fields
        void * data;
ListNode * next;
};

#endif