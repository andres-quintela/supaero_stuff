#include <stdio.h>

int main(void) {
    int i1;
    printf("First integer? ");
    scanf("%d", &i1);

    int i2;
    printf("Second integer? ");
    scanf("%d", &i2);

    int a = i1;
    int b = i2;

    while (a != b) {
        if (a > b) {
           a = a - b;
        } else {
           b = b - a;
        }
    }

    printf("The GCD of %d and %d is %d\n",
           i1, i2, a);

    return 0;
}
