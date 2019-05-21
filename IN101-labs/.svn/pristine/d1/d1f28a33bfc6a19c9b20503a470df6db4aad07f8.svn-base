#include <stdio.h>

void swap(int *p_a, int *p_b) {
    int temp = *p_a;

    *p_a = *p_b;
    *p_b = temp;
}

int main(void) {
    int a = 2;
    int b = 1;

    printf("a before swap: %d\n", a);
    printf("b before swap: %d\n", b);

    printf("swapping...\n");

    swap(&a, &b);

    printf("a after swap: %d\n", a);
    printf("b after swap: %d\n", b);

    return 0;
}
