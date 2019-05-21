#include <stdio.h>

void multiply_array_by_two(int array[], int length) {
    for (int i = 0; i < length; i++) {
        array[i] = array[i] * 2;
    }
}

int main(void) {
    int my_array[] = { 1, 2, 3, 0, 4, 5, 6 };

    multiply_array_by_two(my_array, 7);

    printf("[ ");

    for (int i = 0; i < 7; i++) {
        printf("%d%s", my_array[i], i == 6 ? " " : ", ");
    }

    printf("]\n");

    return 0;
}
