#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "space.h"

void print_points(double x[], double y[], int start, int end) {
    printf("[");

    for (int i = start; i < end; i++) {
        printf("(%lf, %lf), ", x[i], y[i]);
    }

    if (end >= start) {
        printf("(%lf, %lf)", x[end], y[end]);
    }

    printf("]\n");
}

bool is_counterclockwise(double x1, double y1,
                         double x2, double y2,
                         double x3, double y3) {

    return (x1 - x2) * (y3 - y2) < (x3 - x2) * (y1 - y2);
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

int partition(double x[], double y[], int lo, int hi) {
    double x_pivot = x[lo];
    double y_pivot = y[lo];
    int    i       = lo;
    int    j       = hi;

    while (true) {
        while (is_counterclockwise(x_pivot, y_pivot,
                                   x[0], y[0],
                                   x[i], y[i])) {
            i = i + 1;
        }

        while (is_counterclockwise(x[j], y[j],
                                   x[0], y[0],
                                   x_pivot, y_pivot)) {
            j = j - 1;
        }

        if (i >= j) {
            return j;
        }

        swap(x, y, i, j);
    }
}

void rec_quicksort(double x[], double y[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(x, y, lo, hi);
        rec_quicksort(x, y, lo, p);
        rec_quicksort(x, y, p + 1, hi);
    }
}

void quicksort(double x[], double y[], int size) {
    rec_quicksort(x, y, 1, size - 1);
}

int find_min(double x[], double y[], int size) {
    int min = 0;

    for (int i = 1; i < size; i++) {
        if (y[i] < y[min]) {
            min = i;
        }
    }

    for (int i = 0; i < size; i++) {
        if (y[i] == y[min]) {
            if (x[i] < x[min]) {
                min = i;
            }
        }
    }

    return min;
}

void copy_plus_one(double x_src[], double y_src[],
                   double x_dest[], double y_dest[],
                   int size) {
    for (int i = 0; i < size; i++) {
        x_dest[i + 1] = x_src[i];
        y_dest[i + 1] = y_src[i];
    }

    x_dest[0] = x_src[size - 1];
    y_dest[0] = y_src[size - 1];
}

int convex_hull(double x[], double y[],
                int size, bool draw) {
    int index = 3;

    for (int i = 4; i < size; i++) {
        while (! is_counterclockwise(x[index - 1], y[index - 1],
                                     x[index], y[index],
                                     x[i], y[i])) {
            index = index - 1;
        }

        index = index + 1;

        swap(x, y, index, i);

        if (draw) {
            DrawConvexHull(x, y, size, index);
        }
    }

    return index;
}

void simple_test() {
    double x[] = { 3.5, -1.0, 5.0, 4.0, -1.0, 3.5, -1.5, -3.0, 4.0};
    double y[] = { 2.0,  5.0, 2.0, 4.5,  0.0, 4.0,  3.0,  4.0, 1.0};

    printf("testing print\n");
    print_points(x, y, 0, 8);
    print_points(x, y, 0, 0);
    print_points(x, y, 2, 2);
    print_points(x, y, 2, 1);

    printf("testing find_min\n");
    int min = find_min(x, y, 9);
    printf("min index: %d\n", find_min(x, y, 9));

    printf("testing swap\n");
    swap(x, y, min, 0);
    print_points(x, y, 0, 8);

    printf("testing sorting\n");
    quicksort(x, y, 9);
    print_points(x, y, 0, 8);

    printf("testing copy\n");
    double x_ch[10];
    double y_ch[10];

    copy_plus_one(x, y, x_ch, y_ch, 9);
    print_points(x_ch, y_ch, 0, 9);

    printf("testing convex hull\n");

    int index = convex_hull(x_ch, y_ch, 10, false);

    printf("number of points in convex hull: %d\n", index);

    print_points(x_ch, y_ch, 1, index);
}

int main(int argc, char *argv[]) {
    bool b_space          = true;
    bool b_draw           = false;
    int  opts             = 0;

    while ((opts = getopt(argc, argv, "tsd")) != -1) {
        switch (opts) {
        case 't': {
            simple_test();
            return 0;
        }
        case 's': {
            b_space = false;
            break;
        }
        case 'd': {
            b_draw = true;
            break;
        }
        default:
            abort();
        }
    }

    int nb_points;
    printf("How many %s? ", b_space ? "stars" : "points");
    scanf("%d", &nb_points);

    double x[nb_points], y[nb_points];

    CreateWindow(800, 800);

    if (b_space) {
        GenerateGalaxy(x, y, nb_points, 6502);
    } else {
        GenerateSquare(x, y, nb_points, 6502);
    }

    PlotPixels(x, y, nb_points);

    printf("Click to start\n");
    WaitClick();

    clock_t start_time = clock();

    printf("finding minimum...\n");
    int min = find_min(x, y, nb_points);
    swap(x, y, min, 0);

    printf("sorting points...\n");
    quicksort(x, y, nb_points);

    printf("creating new array...\n");
    double x_ch[nb_points + 1];
    double y_ch[nb_points + 1];

    copy_plus_one(x, y, x_ch, y_ch, nb_points);

    printf("computing convex hull...\n");
    int index = convex_hull(x_ch, y_ch, nb_points, b_draw);

    clock_t end_time = clock();

    printf("drawing convex hull...\n");

    DrawConvexHull(x_ch, y_ch, nb_points, index);

    printf("time spent: %f\n", (double) (end_time - start_time) /
           CLOCKS_PER_SEC);

    printf("Click to exit\n");
    WaitClick();

    CloseWindow();

    return 0;
}
