#include <stdio.h>

void print_array(int array[], int length) {
    printf("[ ");

    for (int i = 0; i < length; i++) {
        printf("%d%s", array[i], i == length - 1 ? " " : ", ");
    }

    printf("]");
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void selection_sort(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(array, i, min_index);
        }
    }
}

int main(void) {
    int my_array[] = { -1, 0, 14, 7, -8, 10 };

    printf("Array before sorting: ");
    print_array(my_array, 6);
    printf("\n");

    selection_sort(my_array, 6);

    printf("Array after sorting: ");
    print_array(my_array, 6);
    printf("\n");

    return 0;
}
