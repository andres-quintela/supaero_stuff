#include <stdbool.h>
#include <stdio.h>

int fib(int last){	
		
		if (last==0){
		return 0;
		}
		else if (last==1){
		return 1;}
		
		int n_2 = 0; 
		int n_1 = 1;
		int n;
		for (int i = 2; i <= last; i++){
			n = n_2 + n_1;
			n_2 = n_1;
			n_1 = n;
		}
		return n;
	}

int fib_rec(int last){	
	if (last==0){
		return 0;
	}
	else if (last==1){
		return 1;
	}
	else
		return fib_rec(last-1)+fib_rec(last-2);
		
	}
	
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
