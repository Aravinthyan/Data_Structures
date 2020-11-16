#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode
{
    public:
        // constructor with 0 parameters
        ListNode();
        // constructor with 2 parameters
        ListNode(T * data, ListNode * next);
        // Destructor
        ~ListNode();
        // set data the data for this node
        void set_data(T * data);
        // get data the data in this node
        T * get_data(void);
        // set next the node
        void set_next(ListNode * next);
        // get the next node
        ListNode * get_next(void);

    private:
        // fields
        T * data;
        ListNode * next;
};

// constructor with 0 parameters
template <typename T>
ListNode<T>::ListNode() :
ListNode(nullptr, nullptr)
{

}


// constructor with 2 parameters
template <typename T>
ListNode<T>::ListNode(T * data, ListNode * next) : 
data(data), next(next)
{

}

// Destructor
template <typename T>
ListNode<T>::~ListNode()
{
    // delete the data it holds only
    delete data;
}

// set data the data for this node
template <typename T>
void ListNode<T>::set_data(T * data)
{
    this->data = data;
}

// get data the data in this node
template <typename T>
T * ListNode<T>::get_data(void)
{
    return this->data;
}

// set next the node
template <typename T>
void ListNode<T>::set_next(ListNode * next)
{
    this->next = next;
}

// get the next node
template <typename T>
ListNode<T> * ListNode<T>::get_next(void)
{
    return this->next;
}

#endif