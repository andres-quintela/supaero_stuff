#include <stdio.h>

int main(void) {

	int i1;
	int i2;
	
	printf("First integer?");
	scanf("%d",&i1)
	
	printf("Second integer?");
	scanf("%d",&i2)
	
	int A = i1;
	int B = i2;
	
	while (A != B) {
	 
		if ( A > B){
	   		A = A-B;
	 	}
	 	else{
	   		B = B-A;
	 	}
	}
	
	printf("The GCD of %d and %d is %d",i1,i2,A);


	return=0;
}
