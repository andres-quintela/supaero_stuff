#include <stdio.h>

int main(void) {
	int x1;
	printf("Number you want to calculate exponential of: ");
	scanf("%d",&x1);
	
	float x2 = 1;
	
	for (int i = 1; (i <= x1); i++ ) {
		x2 = x2*i;  	
	}
	
	printf(" The value of %d! is %f \n",x1,x2);
	return 0;
}
