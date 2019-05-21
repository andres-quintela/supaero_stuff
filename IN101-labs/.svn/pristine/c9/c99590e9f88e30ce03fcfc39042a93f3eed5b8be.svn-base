#include <stdbool.h>
#include <stdio.h>


float compute_pi(int n) {
		float my_sum=4.0;

		for (int i = 1; i <= n + 1; i++) {
			
			my_sum += 4.0 * (i%2==0?1:-1)/ (2.0 *i + 1);
		}	
		
		return my_sum;
}



int main(void){
	
	
	printf("Enter n");
	int n = 1;
	scanf("%d", &n);
	
	float pi=compute_pi(n);
	printf("PI = %f with n = %d\n", pi, n);
	
	return 0;

}
