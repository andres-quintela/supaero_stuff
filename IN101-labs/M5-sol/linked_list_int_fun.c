#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell_int  cell_int;
typedef cell_int        *linked_list_int;

struct cell_int {
    int      value;
    cell_int *next;
};

// utilitary functions goes here
cell_int *go_to_position(linked_list_int list, int pos) {
    cell_int *p_current_cell = list;

    for (int i = 0; i < pos; i++) {
        p_current_cell = p_current_cell->next;
    }

    return p_current_cell;
}

// functions from the signature
linked_list_int nil() {
    return NULL;
}

linked_list_int cons(linked_list_int list, int value) {
    cell_int *p_new_cell = malloc(sizeof(cell_int));

    if (p_new_cell == NULL) {
        printf("problem with creating cell in cons!\n");
    }

    p_new_cell->value = value;
    p_new_cell->next  = list;

    return p_new_cell;
}

int size(linked_list_int list) {
    int length = 0;
    cell_int *p_current_cell = list;

    while (p_current_cell != NULL) {
        p_current_cell = p_current_cell->next;
        length++;
    }

    return length;
}

bool is_empty(linked_list_int list) {
    return list == NULL;
}

int get_element(linked_list_int list, int pos) {
    // not very efficient to use size function but...
    int length = size(list);

    assert(list != NULL && pos >= 0 && pos < length);

    // go to position
    cell_int *p_cell = go_to_position(list, pos);

    return p_cell->value;
}

linked_list_int insert_element(linked_list_int list, int pos, int value) {
    // not very efficient to use size function but...
    int length = size(list);

    assert(pos >= 0 && pos <= length);

    if (pos == 0) {
        return cons(list, value);
    }

    cell_int *p_current_cell = list;

    cell_int *p_new_cell = malloc(sizeof(cell_int));

    if (p_new_cell == NULL) {
        printf("problem with creating cell in insert_element!\n");
    }

    p_new_cell->value = value;

    p_current_cell = go_to_position(list, pos - 1);

    p_new_cell->next     = p_current_cell->next;
    p_current_cell->next = p_new_cell;

    return list;
}

linked_list_int remove_element(linked_list_int list, int pos) {
    cell_int *p_current_cell = list;
    cell_int *p_old_cell     = NULL;

    // not very efficient to use size function but...
    int length = size(list);

    assert(list != NULL && pos >= 0 && pos < length);

    if (pos == 0) {
        linked_list_int tail = p_current_cell->next;
        free(p_current_cell);

        return tail;
    }

    p_current_cell       = go_to_position(list, pos - 1);
    p_old_cell           = p_current_cell->next;
    p_current_cell->next = p_old_cell->next;

    free(p_old_cell);

    return list;
}

void deallocate_list(linked_list_int list) {
    cell_int *p_temp_cell    = NULL;
    cell_int *p_current_cell = list;

    while (p_current_cell != NULL) {
        p_temp_cell    = p_current_cell;
        p_current_cell = p_current_cell->next;
        free(p_temp_cell);
    }
}

void print_list(linked_list_int list) {
    cell_int *p_current_cell = list;

    printf("[ ");

    while (p_current_cell != NULL) {
        printf("%d", p_current_cell->value);

        if (p_current_cell->next != NULL) {
            printf(", ");
            p_current_cell = p_current_cell->next;
        } else {
            printf(" ");
            break;
        }
    }

    printf("]");
}

// the program
int main(void) {
    linked_list_int test_list = nil();

    printf("empty list: ");
    print_list(test_list);
    printf("\n");

    printf("is list empty? %s\n",
           is_empty(test_list) ? "true" : "false");

    test_list = cons(cons(cons(cons(test_list, 1), 2), 3), 4);

    printf("initial list: ");
    print_list(test_list);
    printf("\n");

    printf("list size: %d\n", size(test_list));

    test_list = insert_element(test_list, 0, 255);
    test_list = insert_element(test_list, 2, 254);
    test_list = insert_element(test_list, 6, 253);

    printf("list after inserting 3 elements: ");
    print_list(test_list);
    printf("\n");

    printf("list size: %d\n", size(test_list));

    printf("is list empty? %s\n",
           is_empty(test_list) ? "true" : "false");

    printf("3rd element: %d\n", get_element(test_list, 2));

    test_list = remove_element(test_list, 3);

    printf("list after removing 1 element: ");
    print_list(test_list);
    printf("\n");

    deallocate_list(test_list);

    return 0;
}
