#include <stdio.h>

int main(void) {
	float my_array[10];
	int k;
	int j;
	float min;
	int location;


	for (k = 0; k < 10; k++){
		scanf("%f",my_array[k]);
	}

	for (k = 0; k < 10; k++){
	printf("%f",my_array[k]);
	}
	

	for (k = 0; k < 10; k++){
	
		for (j = 0; j < 10; j++){
			if (my_array[k]<my_array[j]){
				min = my_array[k];
				location = k;
			}else {
				continue;
			}	
		}
	}
	printf("The minimum is %f and is located at index %n \n",min,location);




	return 0;
}


