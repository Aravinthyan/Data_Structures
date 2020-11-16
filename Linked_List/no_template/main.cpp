#include "List.h"
#include "ListNode.h"
#include <cstdio>
//
using namespace std;

void save(ListNode * current)
{
    FILE * file = fopen("test.txt", "w");
    while(current != NULL)
    {
        fwrite(current->get_data(), sizeof(int), 1, file);
        current = current->get_next();
    }
    fclose(file);
}

List * read(List * list)
{
    FILE * file  = fopen("test.txt", "r");
    int * data;
    while(!feof(file))
    {
        data = new int;
        fread(data, sizeof(int), 1, file);
        list->insert_at_back((void *) data);
    }
    fclose(file);
    return list;
}

void print(ListNode * current)
{
    int * data;
    while(current != NULL)
    {
        data = (int *)current->get_data();
        printf("Data: %d\n", *data);
        current = current->get_next();
    }
}

int main(void)
{
    List * list = new List();

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

    list->insert_at_front((void *) val_3);
    list->insert_at_front((void *) val_2);
    list->insert_at_back((void *) val_5);
    list->insert_at_back((void *) val_4);
    list->insert_at_front((void *) val_1);

    print(list->get_first());
    save(list->get_first());
    delete list;

    List * new_list = new List();
    new_list = read(new_list);
    print(new_list->get_first());
    delete new_list;
    
    return 0;
}
