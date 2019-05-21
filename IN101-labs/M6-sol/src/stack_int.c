/**
 * @file stack_int.c
 *
 * @brief Implementation of a stack using a linked list
 *
 * @author Christophe Garion
 *
 * The implementation of the stack.
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "stack_int.h"

void create_empty_stack(stack_int *p_stack) {
    nil(p_stack);
}

bool is_stack_empty(const stack_int *p_stack) {
    return is_empty(p_stack);
}

void push(stack_int *p_stack, int element) {
    cons(p_stack, element);
}

int pop(stack_int *p_stack) {
    assert(! is_stack_empty(p_stack));

    int value = get_element(p_stack, 0);
    remove_element(p_stack, 0);

    return value;
}

void deallocate_stack(stack_int *p_stack) {
    deallocate_list(p_stack);
}

void print_stack(const stack_int *p_stack) {
    cell_int *p_cell = *p_stack;
    int max          = 0;

    while (p_cell != NULL) {
        printf("| %d\n", p_cell->value);

        if (p_cell->value > max) {
            max = p_cell->value;
        }

        p_cell = p_cell->next;
    }

    if (max == 0) {
        printf("+---\n");
    } else {
        int rep_size = (int) log10(max);

        char tab_minus[rep_size + 1];

        for (int i = 0; i < rep_size; i++) {
            tab_minus[i] = '-';
        }

        tab_minus[rep_size] = '\0';

        printf("+-%s--", tab_minus);
    }
}
