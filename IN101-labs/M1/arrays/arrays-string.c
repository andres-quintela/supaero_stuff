#include <stdio.h>

int main(void) {
	char array[100];
	scanf("%s",array);
	int k =0;
	
	while (array[k] != '\0'){
		printf("%c \n",array[k]);
		k=k+1;
	}
    return 0;
}
