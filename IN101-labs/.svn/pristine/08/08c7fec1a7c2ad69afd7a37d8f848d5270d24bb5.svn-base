#ifndef LINKED_LIST_INT_H
#define LINKED_LIST_INT_H
#include <stdbool.h>



typedef struct cell_int  cell_int;
typedef cell_int *linked_list_int;

struct cell_int {
    int value;
    cell_int *next;  //points to the next cell, so pointer to cell_int structure
};


linked_list_int nil(void);
linked_list_int cons(linked_list_int list,int elt);
int size(linked_list_int list);
bool is_empty(linked_list_int list);
int get_element(linked_list_int list, int position);
linked_list_int insert_element(linked_list_int list, int position, int value);
linked_list_int remove_element(list,position);
void deallocate_list(list);
void print_list(linked_list_int list);



#endif
