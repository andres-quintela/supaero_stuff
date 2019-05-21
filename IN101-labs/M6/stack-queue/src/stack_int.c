#include <stdio.h>
#include "linked_list_int.h"
#include "stack_int.h"

linked_list_int create_empty_stack(void){
	return NULL;
}

bool is_stack_empty(linked_list_int list){
	

	if (list == NULL) {
		return true;
		}
	else {
		return false;
		}
}

linked_list_int pop(linked_list_int list){

	//add error is size equal to 1

	int value = (*list).value; //get value
	printf("%d\n",value);
	
	list=(*list).next;
	return list;

}
linked_list_int push(linked_list_int list ,int value){
	
	linked_list_int element = malloc(sizeof(cell_int));
	
	(*element).value = value;
	(*element).next=list;

	return element;
}
void deallocate_stack(linked_list_int list){

	linked_list_int list_loop=list;
	linked_list_int list_loop2=list;

	while (list_loop != NULL){
		list_loop2=(*list_loop).next;
		free(list_loop);
		list_loop=list_loop2;
		}

}
void print_stack(linked_list_int list){
	linked_list_int list_loop= list; 
	while (list_loop != NULL) {
		printf("%d\n",(*list_loop).value);
		list_loop = (*list_loop).next;
	}
}

