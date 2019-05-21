#include <stdbool.h>
#include <stdio.h>
	
int fib_tab(int last){	
	
	int matrix[last];
	matrix[0]=0;
	matrix[1]=1;
	for (int i = 2; i <= last; i++){
			matrix[i] = matrix[i-1] + matrix[i-2];
		}

		return matrix[last];
	}
	


int main(void){
	
	
	printf("Enter n for the fibonacci series");
	int n = 1;
	scanf("%d", &n);
	
	int number=fib_tab(n);
	printf("%d\n", number);
	
return 0;
}

