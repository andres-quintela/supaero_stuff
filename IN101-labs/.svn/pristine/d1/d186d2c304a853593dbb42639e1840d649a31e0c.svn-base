#include <math.h>
#include <stdio.h>

int main(void) {
    int n = 4;

    float matrix[4][4] = { {1.0, 2.0, 3.0, 4.0},
                           {0.0, 2.0, 3.0, 4.0},
                           {0.0, 0.0, 3.0, 4.0},
                           {0.0, 0.0, 0.0, 4.0} };

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0.0) {
                printf("This is not an upper triangular matrix because of cell (%d, %d) = %f!\n",
                       i, j, matrix[i][j]);
                return 0;
            }
        }
    }

    printf("This is an upper triangular matrix.\n");

    matrix[3][0] = 1E300 + 1E-10 - 1E300;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0.0) {
                printf("This is not an upper triangular matrix because of cell (%d, %d) = %f!\n",
                       i, j, matrix[i][j]);
                return 0;
            }
        }
    }

    printf("This is an upper triangular matrix.\n");

    float epsilon = 1E-6;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (fabs(matrix[i][j]) > epsilon) {
                printf("This is not an upper triangular matrix because of cell (%d, %d) = %f!\n",
                       i, j, matrix[i][j]);
                return 0;
            }
        }
    }

    printf("This is an upper triangular matrix.\n");

    matrix[3][0] = 1E300 -1E300 + 1E-10;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0.0) {
                printf("This is not an upper triangular matrix because of cell (%d, %d) = %f!\n",
                       i, j, matrix[i][j]);
                return 0;
            }
        }
    }

    printf("This is an upper triangular matrix.\n");

    return 0;
}
