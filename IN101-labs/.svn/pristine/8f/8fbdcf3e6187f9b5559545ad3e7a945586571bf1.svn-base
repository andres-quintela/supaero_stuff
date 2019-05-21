#include <stdio.h>
#include <stdbool.h>

int factorial(int x1) {
	
	float x2 = 1;
	
	for (int i = 1; i <= x1; i++ ) {
		x2 = x2*i;  	
	}
	return x2;
}

void print(int size, int array[size]){
		
		for (int i = 0;i< size ;i++){
				printf("%d\n",array[i]);
		}
}




bool fact(int n,int *res){

	if (n<13){
		
		*res = factorial(n); 
		
		return true;
	}
	else {
		return false;
	}
}

int main(){
	
	int f[20];
	int *res;
	
	for (int i=0;i<=20;i++){
		fact(i,res);
		f[i]=*res;
	}
	
	print(20,f);
	


return 0;
}
