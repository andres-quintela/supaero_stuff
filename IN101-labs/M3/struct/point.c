#include <stdio.h>


typedef struct point punto;

struct point {
	
float x;
float y;
};

void print_point(punto z){
	
	printf("Coordinate x = %f \n",z.x);
	printf("Coordinate y = %f \n",z.y);

	
}


int point_cmp(punto z1, punto z2){
	
	if (z1.x>z2.x){
	
		return -1;
		}
	else if (z1.x<z2.x){
		return 1;
		}
	else if (z1.x=z2.x){
		
		if (z1.y>z2.y){
			return -1;
			}
		else if (z1.y<z2.y){
			return 1;
			}
		else {
			return 0;
			}
		
		}

} 	
	


void trans(punto *p, punto vect){
	
	
	p->x = (*p).x +vect.x;  
	(*p).y = (*p).y +vect.y;
	
}


int main(){
	
	
	punto z1;
	z1.x= 4;
	z1.y= 2;
	
	punto z2;
	z2.x= 4;
	z2.y= 1;
	
	print_point(z1);
	print_point(z2);
	
	int i;
	
	i=point_cmp(z1,z2);
	printf("Value is %d\n",i);
	
	trans(&z1,z2);
	print_point(z1);
	
	
	
	
	
	
	
	
	
return 0;
	
}
