#include <stdbool.h>
#include <stdio.h>


int is_leap(int n) {
		int leap = 0;
		if ((n%4==0)&&(n%100!=1)){
			leap = 1 ;
		}
		return(leap);
}



int main(void){
	
	
	printf("Enter year\n");
	int n = 1;
	scanf("%d", &n);
	
	int leap=is_leap(n);
	if (leap==1){
		printf("The year %d is a leap year\n" ,n);
	}
	else {
		printf("The year %d is not a leap year\n" ,n);
		}
	return 0;
}
