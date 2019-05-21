#include <stdio.h>

int main(void) {
	int x1;
	printf("Limit of summation to calculate pi: ");
	scanf("%d",&x1);
	
	double pi = 1;
	int ksign;
	
	for (int k = 0; (k <= x1); k++ ) {
		if (k%2) { 
			ksign= -1;
		} else {
			ksign=1;
		}
		
		pi = pi + ksign/(2*k+1);  	
	}
	
	printf(" The value of pi is %f \n",pi);
	return 0;
}
