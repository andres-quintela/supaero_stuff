#include <stdio.h>

void print_array_array(int size, int array[]) {
    printf("[ ");

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]); // change 1 to the correct expression here
    }

    printf("]\n");
}

void print_array_pointer(int size, int array[]) {
    printf("[ ");

    for (int i = 0; i < size; i++) {
        printf("%d ", *(array+i)); // change 1 to the correct expression here
    }

    printf("]\n");
}

void print_pointer_array(int size, int *array) {
    printf("[ ");

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]); // change 1 to the correct expression here
    }

    printf("]\n");
}

void print_pointer_pointer(int size, int *array) {
    printf("[ ");

    for (int i = 0; i < size; i++) {
        printf("%d ", *(array+i)); // change 1 to the correct expression here
    }

    printf("]\n");
}

int main(void) {
    int my_array[] = {1, 2, 3, 4, 5};

    printf("declared as a array and used as an array:\n");
    print_array_array(5, my_array);

    printf("declared as a array and used as a pointer:\n");
    print_array_pointer(5, my_array);

    printf("declared as a pointer and used as an array:\n");
    print_pointer_array(5, my_array);

    printf("declared as a pointer and used as a pointer:\n");
    print_pointer_pointer(5, my_array);

    return 0;
}
