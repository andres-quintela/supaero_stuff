#include <stdio.h>

void create_pascal_triangle(int size, int array[size][size]) {
    if (size == 0) {
        return;
    }

    array[0][0] = 1;

    for (int i = 1; i < size; i++) {
        array[i][0] = 1;
        array[i][i] = 1;

        for (int j = 1; j < i; j++) {
            array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
        }
    }
}

void print_pascal_triangle_array(int size, int array[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%3d ", array[i][j]);
        }

        printf("\n");
    }
}

void print_pascal_triangle_array_one_size(int size, int array[][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%3d ", array[i][j]);
        }

        printf("\n");
    }
}

// void print_pascal_triangle_array_zero_size(int size, int array[][]) {
//     for (int i = 0; i < size; i++) {
//         for (int j = 0; j <= i; j++) {
//             printf("%3d ", array[i][j]);
//         }
//
//         printf("\n");
//     }
// }

void print_pascal_triangle_pointer(int size, int array[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%3d ", *(*array + i * size + j));
            // or printf("%3d ", *(*(array + i) + j));
        }

        printf("\n");
    }
}

int main(void) {
    int size = 10;
    int array[size][size];

    create_pascal_triangle(size, array);
    print_pascal_triangle_array(size, array);
    print_pascal_triangle_array_one_size(size, array);
    //print_pascal_triangle_array_zero_size(size, array);
    print_pascal_triangle_pointer(size, array);
}
