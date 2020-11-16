#include "List.h"
#include "ListNode.h"
#include <cstdio>

int main(void)
{
    List<int> * list = new List<int> ();

    int * val_1 = new int;
    *val_1 = 1;
    int * val_2 = new int;
    *val_2 = 2;
    int * val_3 = new int;
    *val_3 = 3;
    int * val_4 = new int;
    *val_4 = 4;
    int * val_5 = new int;
    *val_5 = 5;

    list->insert_at_front(val_3);
    list->insert_at_front(val_2);
    list->insert_at_back(val_5);
    list->insert_at_back(val_4);
    list->insert_at_front(val_1);

    int * data;
    ListNode<int> *current = list->get_first();
    
    while(current != nullptr)
    {
        data = (int *)current->get_data();
        printf("Data: %d\n", *data);
        current = current->get_next();
    }
    delete list;
    return 0;
}