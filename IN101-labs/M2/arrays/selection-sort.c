#include <stdbool.h>
#include <stdio.h>


void swap(int size, float array[size],int i,int j){
		
		float a = array[i];
		float b = array[j];
		array[i]= b;
		array[j]=a;

}

void print_array(int size, float array[size]){
		
		for (int i = 0;i< size ;i++){
				printf("%f\n",array[i]);
		}
}


void selection_sort(int size ,float array[size]){
	
	for(int i = 0;i < size ;i++){
		for(int j = i;j < size ;j++){
			if (array[j]<array[i]){
				swap(size,array,i,j);
			}
		}
	}
	
}


int main(void){
	
	
	float matrix[4] = {4.0, 3.0, 1.0, 2.0};

	
	selection_sort(4,matrix);
	

    
    print_array(4,matrix);

                           
            
	return 0;
}
