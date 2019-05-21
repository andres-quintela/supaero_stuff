#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list_int.h"


// functions from the signature
linked_list_int nil(void) {
	return NULL;
}

linked_list_int cons(linked_list_int list,int elt) {
	
	linked_list_int element = malloc(sizeof(cell_int));
	(*element).value = elt;
	(*element).next = list;
	return element;
}

int size(linked_list_int list) {
	linked_list_int list_loop= list; 
	int counter = 0;
	while (list_loop != NULL){
		counter=counter+1;
		list_loop = (*list_loop).next;
	}
	return counter;
}

bool is_empty(linked_list_int list) {
	
	int n = size(list);
	if (n == 0) {
		return true;
		}
	else {
		return false;
		}
}

int get_element(linked_list_int list, int position) {
	linked_list_int list_loop= list; 
	int counter = position;
	int size1 = size(list);
	int temp = 0;
	if (position > size1){
		printf("ERROR");
		return 0;
	}
	else{
		while(temp < position){
			
			list_loop = (*list_loop).next;
			temp=temp+1;
			}
		
		}
	int value = (*list_loop).value;
	return value;

}

linked_list_int insert_element(linked_list_int list, int position, int value) {
	
	linked_list_int list_loop= list; 
	int counter = position;
	int size1 = size(list);
	int temp = 0;
	
	cell_int *new_element = malloc(sizeof(cell_int));
	(*new_element).value = value;
	
	if (position > size1){
		printf("ERROR");
		return 0;
	}
	else{
		while(temp < position-1){
			
			list_loop = (*list_loop).next;
			temp=temp+1;
			}
		
		}
	cell_int *previous_next_cell;
	previous_next_cell=(*list_loop).next;
	(*list_loop).next=new_element;
	(*new_element).next = previous_next_cell;
	return list;

}

linked_list_int remove_element(list,position) {
	
	linked_list_int list_loop= list; 
	int counter = position;
	int size1 = size(list);
	int temp = 0;
	
	if (position > size1){
		printf("ERROR");
		return 0;
	}
	else{
		while(temp < position-1){
			
			list_loop = (*list_loop).next;
			temp=temp+1;
			}
		
		}
	
	linked_list_int next_list_loop = (*list_loop).next;
	(*list_loop).next= (*next_list_loop).next;
	return list;

}

void deallocate_list(list) {
	
	linked_list_int list_loop=list;
	linked_list_int list_loop2=list;

	while (list_loop != NULL){
		list_loop2=(*list_loop).next;
		free(list_loop);
		list_loop=list_loop2;
	}
	

}

void print_list(linked_list_int list) {
	linked_list_int list_loop= list; 
	while (list_loop != NULL) {
		printf("%d\n",(*list_loop).value);
		list_loop = (*list_loop).next;
	}
}


