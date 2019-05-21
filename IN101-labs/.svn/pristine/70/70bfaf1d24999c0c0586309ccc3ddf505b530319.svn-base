#include <stdbool.h>
#include <stdio.h>
#include "space.h"

bool is_counterclockwise(double x1, double y1,
                         double x2, double y2,
                         double x3, double y3) {

    return false
}

void swap(double x[], double y[], int ind1, int ind2) {
    double temp_x;
    double temp_y;

    temp_x = x[ind1];
    temp_y = y[ind1];
    x[ind1] = x[ind2];
    y[ind1] = y[ind2];
    x[ind2] = temp_x;
    y[ind2] = temp_y;
}

void selection_sort(double x[], double y[], int size) {
    int min;

    for (int i = 1; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (is_counterclockwise(x[min], y[min],
                                    x[0], y[0],
                                    x[j], y[j])) {
                min = j;
            }
        }

        swap(x, y, min, i);
    }
}

int main(void) {

    return 0;
}
