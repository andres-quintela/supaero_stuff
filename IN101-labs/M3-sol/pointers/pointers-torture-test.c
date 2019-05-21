#include <stdio.h>

void add_two(int *p_i) {
    *p_i = *p_i + 2;
}

void assign_pointer(int **p_p_p, int *p_q) {
    *p_p_p = p_q;
}

int main(void) {
    int j = 2;
    int k = 5;

    add_two(&j);

    printf("j = %d\n", j);

    int *p_j = &j;
    int *p_k = &k;

    printf("p_j = %p\n", p_j);
    printf("p_k = %p\n", p_k);

    add_two(p_k);

    printf("k = %d\n", k);
    printf("p_j = %p\n", p_j);
    printf("p_k = %p\n", p_k);

    assign_pointer(&p_k, p_j);

    printf("p_j = %p\n", p_j);
    printf("p_k = %p\n", p_k);
    printf("*p_j = %d\n", *p_j);
    printf("*p_k = %d\n", *p_k);

    return 0;
}
