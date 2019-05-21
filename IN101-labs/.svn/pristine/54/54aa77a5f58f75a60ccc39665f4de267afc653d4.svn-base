#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "space.h"

bool VectorIsInHull(int index1, int index2, double x_pos[], double y_pos[], int nb_points) {
    double x_orthogonal = -(y_pos[index2]-y_pos[index1]);
    double y_orthogonal = x_pos[index2]-x_pos[index1];

    if (x_orthogonal==0 && y_orthogonal==0) return false;

    for (int i=0; i<nb_points; i++) {
	if (i==index1 || i==index2) continue;

        double x_vect = x_pos[i]-x_pos[index1];
	double y_vect = y_pos[i]-y_pos[index1];

        if (x_vect*x_orthogonal+y_vect*y_orthogonal<0) return false;
    }

    return true;
}

int main(void) {
    int nb_points;

    printf("How many stars? ");
    scanf("%d", &nb_points);

    double x_pos[nb_points], y_pos[nb_points];

    CreateWindow(800, 800);

    GenerateGalaxy(x_pos, y_pos, nb_points, 6502);

    PlotPixels(x_pos, y_pos, nb_points);

    printf("Click to start\n");
    WaitClick();

    clock_t start_time = clock();

    for (int i=0; i<nb_points; i++)
	for (int j=0; j<nb_points; j++)
            if (i!=j && VectorIsInHull(i, j, x_pos, y_pos, nb_points))
		DrawLine(x_pos[i], y_pos[i], x_pos[j], y_pos[j], WU);

    clock_t end_time = clock();

    printf("time spent: %f\n", (double) (end_time - start_time) /
           CLOCKS_PER_SEC);

    printf("Click to exit\n");
    WaitClick();

    CloseWindow();
}
