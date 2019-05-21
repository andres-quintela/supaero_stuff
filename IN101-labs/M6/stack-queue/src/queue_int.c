#include <stdio.h>
#include "linked_list_int.h"
#include "queue_int.h"

linked_list_int create_empty_queue(void){
	return NULL;
}

bool is_queue_empty(linked_list_int list){
	

	if (list == NULL) {
		return true;
		}
	else {
		return false;
		}
}

linked_list_int dequeue(linked_list_int list){


	linked_list_int list_loop= list; 
	
	while( (list_loop->next)->next != NULL){
			
			list_loop = (*list_loop).next;
			}
		
	int value = (list_loop->next)->value;
	printf("Deleted value %d\n",value);
	free((*list_loop).next);
	(*list_loop).next = NULL;
	
	return list;

}
linked_list_int enqueue(linked_list_int list ,int value){
	
	linked_list_int element = malloc(sizeof(cell_int));
	
	(*element).value = value;
	(*element).next=list;

	return element;
}
void deallocate_queue(linked_list_int list){

	linked_list_int list_loop=list;
	linked_list_int list_loop2=list;

	while (list_loop != NULL){
		list_loop2=(*list_loop).next;
		free(list_loop);
		list_loop=list_loop2;
		}

}
void print_queue(linked_list_int list){
	linked_list_int list_loop= list; 
	while (list_loop != NULL) {
		printf("%d\n",(*list_loop).value);
		list_loop = (*list_loop).next;
	}
}

