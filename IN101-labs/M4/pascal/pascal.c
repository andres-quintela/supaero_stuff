#include <stdio.h>
#include <stdlib.h>

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

void print_pascal_triangle(int size, int array[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%3d ", array[i][j]);
        }

        printf("\n");
    }
}

void print_pascal_triangle_iliffe(int size, int **array){
	
	for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%3d ", *(*(array+i)+j));
            
           }
        printf("\n");
	}
}

int *create_single_row(int size){
	
	int *p = NULL;
	
	p=malloc(size*sizeof(int*));
	
	return p;
}

int **create_pointers_array(int size){
	
	int **array=NULL;
	array = malloc(size*sizeof(int*));
	
	for (int i = 0; i < size; i++) {
		*(array+i) = create_single_row(i+1);
	}
	
	return array;
}

int **create_pascal_triangle_iliffe(int size){
	
	int **array=create_pointers_array(size);
	
	if (size == 0) {
        return NULL;
    }

    *(*array) = 1;

    for (int i = 1; i < size; i++) {
        *(array[i]) = 1;
        *(array[i]+i) = 1;

        for (int j = 1; j < i; j++) {
            *(array[i]+j) = *(array[i-1]+j-1) + *(array[i - 1]+j);
        }
    }
    return array;		
}

int main(void) {
    int size = 10;

	int **array = NULL;
	array = create_pascal_triangle_iliffe(size);
	print_pascal_triangle_iliffe(size, array);
	
	free(array);

    return 0;
}

