#include <stdio.h>

int *stack_return() {
    int my_int = 2;

    return &my_int;
}

void foo() {
    int i = 42;
}

int main(void) {
    int *p = stack_return();

    printf("value of *p: %d\n", *p);

    foo();

    printf("value of *p after calling foo: %d\n",
           *p);

    return 0;
}
