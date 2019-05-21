#include "minmax_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


minmax_list *create_empty_list(){
	
	minmax_list *list1=malloc(sizeof(minmax_list));
	
	(*list1).linked_list=nil();
	(*list1).nb=0;
	(*list1).max=-100;
	(*list1).min=+100;

	
return list1; 
}

bool is_list_empty(minmax_list *p_list){
	
	linked_list_int list1=(*p_list).linked_list;
	
	linked_list_int *p_list1=&list1;
	
	bool a=is_empty(p_list1);
	
	return a;
	
}


int get_max(minmax_list *p_list){
	
	int maxval=(*p_list).max;
	
	return maxval;
	}


int get_min(minmax_list *p_list){
	
	int minval=(*p_list).min;
	
	return minval;
	}


void add_first(minmax_list *p_list, int element){
	
	(*p_list).nb +=1;
	cons(&(*p_list).linked_list,element);
	
	if (element > get_max(p_list)){
		(*p_list).max=element;
		
		}
		
	if (element < get_min(p_list)){
		(*p_list).min=element;
		
		}
}

void append(minmax_list *p_list_1, minmax_list *p_list_2){
	
	
	
	
	int size2=(*p_list_2).nb;
	
	int size1=(*p_list_1).nb;

	
	for (int pos=size1;pos<size2+size1;pos++){
		
		int element=get_element(&(*p_list_2).linked_list,pos-size1);
		
		insert_element(&(*p_list_1).linked_list,pos,element);
		
		
		if (element > get_max(p_list_1)){
		(*p_list_1).max=element;
		
		}
		
		if (element < get_min(p_list_1)){
		(*p_list_1).min=element;
		
		}
		
		}
	

		(*p_list_1).nb=(size1+size2);
	}


void reverse(minmax_list *p_list){
	
	int *array[(*p_list).nb];

	for (int i; i<(*p_list).nb; i++){
		
		cell_int *array[i]=(*(*p_list).linked_list).next;
		
		

		
		}
	
	*(*p_list).linked_list
	
	
	
	}




