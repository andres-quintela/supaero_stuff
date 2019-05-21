/**
 * @file app_stack_int.c
 *
 * @brief Simple program using stack containing `int` values.
 *
 * @author Christophe Garion
 */

#include "stack_int.h"
#include <stdio.h>

void print_details(const char* msg, stack_int *p_s) {
    printf("%s:\n\n", msg);
    print_stack(p_s);
    printf("\n\n");
}

int main() {
    stack_int s;
    stack_int *p_s = &s;
    create_empty_stack(p_s);

    print_details("empty stack", p_s);

    push(p_s, 3);
    print_details("pushing 3", p_s);

    push(p_s, 7);
    print_details("pushing 7", p_s);

    push(p_s, 25);
    print_details("pushing 25", p_s);

    int v = pop(p_s);
    print_details("popping", p_s);
    printf("popped value: %d\n", v);

    deallocate_stack(p_s);

    return 0;
}
