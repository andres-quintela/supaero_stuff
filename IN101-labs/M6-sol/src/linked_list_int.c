/**
 * @file linked_list_int.c
 *
 * @ingroup in101-labs
 *
 * @brief Simple implementation of a linked list.
 *
 * The implementation of the linked list.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list_int.h"

// utilitary functions goes here
cell_int *go_to_position(const linked_list_int *p_list, int pos) {
    cell_int *p_current_cell = *p_list;

    for (int i = 0; i < pos; i++) {
        p_current_cell = p_current_cell->next;
    }

    return p_current_cell;
}

// functions from the signature
void nil(linked_list_int *p_list) {
    *p_list = NULL;
}

void cons(linked_list_int *p_list, int value) {
    cell_int *p_new_cell = malloc(sizeof(cell_int));

    if (p_new_cell == NULL) {
        printf("problem with creating cell in cons!\n");
    }

    p_new_cell->value = value;
    p_new_cell->next  = *p_list;

    *p_list = p_new_cell;
}

int size(const linked_list_int *p_list) {
    int length = 0;
    cell_int *p_current_cell = *p_list;

    while (p_current_cell != NULL) {
        p_current_cell = p_current_cell->next;
        length++;
    }

    return length;
}

bool is_empty(const linked_list_int *p_list) {
    return *p_list == NULL;
}

int get_element(const linked_list_int *p_list, int pos) {
    // not very efficient to use size function but...
    int length = size(p_list);

    assert(p_list != NULL && pos >= 0 && pos < length);

    // go to position
    cell_int *p_cell = go_to_position(p_list, pos);

    return p_cell->value;
}

void insert_element(linked_list_int *p_list, int pos, int value) {
    cell_int *p_current_cell = *p_list;

    // not very efficient to use size function but...
    int length = size(p_list);

    assert(pos >= 0 && pos <= length);

    if (pos == 0) {
        cons(p_list, value);

        return;
    }

    cell_int *p_new_cell = malloc(sizeof(cell_int));

    if (p_new_cell == NULL) {
        printf("problem with creating cell in insert_element!\n");
    }

    p_new_cell->value = value;

    p_current_cell = go_to_position(p_list, pos - 1);

    p_new_cell->next     = p_current_cell->next;
    p_current_cell->next = p_new_cell;
}

void remove_element(linked_list_int *p_list, int pos) {
    cell_int *p_current_cell = *p_list;
    cell_int *p_old_cell     = NULL;

    // not very efficient to use size function but...
    int length = size(p_list);

    assert(p_list != NULL && pos >= 0 && pos < length);

    if (pos == 0) {
        *p_list = p_current_cell->next;
        free(p_current_cell);

        return;
    }

    p_current_cell       = go_to_position(p_list, pos - 1);
    p_old_cell           = p_current_cell->next;
    p_current_cell->next = p_old_cell->next;

    free(p_old_cell);
}

void deallocate_list(linked_list_int *p_list) {
    cell_int *p_temp_cell    = NULL;
    cell_int *p_current_cell = *p_list;

    while (p_current_cell != NULL) {
        p_temp_cell    = p_current_cell;
        p_current_cell = p_current_cell->next;
        free(p_temp_cell);
    }
}

void print_list(const linked_list_int * p_list) {
    cell_int *p_current_cell = *p_list;

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
