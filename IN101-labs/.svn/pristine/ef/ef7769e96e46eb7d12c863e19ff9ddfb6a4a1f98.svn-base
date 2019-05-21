/**
 * @file queue_map.c
 *
 *
 * @brief Simple implementation of a queue.
 *
 * The implementation of a queue.
 */

#include "queue_map.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

queue *qnil(void) {
	
	queue *p_queue = malloc(sizeof(queue));
	(*p_queue).first=NULL;
	(*p_queue).last=NULL;
	return p_queue;
}

void *enqueue(queue *p_queue,qcell_map *cell){
	

	if ((*p_queue).first==NULL){
		(*p_queue).first=cell;
		(*p_queue).last=cell;
		(*cell).next=NULL;
	}
	else{
		
		(*(*p_queue).last).next=cell;
		(*p_queue).last=cell;
		(*cell).next=NULL;
		}
		return EXIT_SUCCESS;
}

qcell_map *dequeue(queue *p_queue){
	
	qcell_map *first_cell=(*p_queue).first;
	
	//when queue is empty
	if ((*p_queue).first==NULL){
	
		printf("queue is empty, cant dequeue\n");
		return NULL;
		}
	
	//when queue has only one cell
	else if ((*first_cell).next==NULL) {
	
	
	(*p_queue).first=NULL;
	(*p_queue).last=NULL;
	
	return first_cell;
	
	}
	else{
	(*p_queue).first=(*first_cell).next;
	return first_cell;
	
	}
}
	
void print_queue(queue *p_queue){
	
	
	if ((*p_queue).first==NULL){
		printf("queue is empty, cant print\n");

		return;
		}
	qcell_map *list_loop= (*p_queue).first; 
	
	//iterate over cells
	while (list_loop != NULL) {
		print_map((*list_loop).map_struct);
		list_loop = (*list_loop).next;
	
	}
}


void free_queue(queue *p_queue){
	
	
	if ((*p_queue).first==NULL){
		free(p_queue);
		return;
		}
	
	qcell_map *list_loop2;
	qcell_map *list_loop= (*p_queue).first; 
	
	//iterate over cells
	while (list_loop != NULL) {
		
		list_loop2=(*list_loop).next;
		free(list_loop);
		list_loop = list_loop2;

	}
	//free queue cell
	free(p_queue);
}


void free_queue_comp(queue *p_queue){
	
	
	if ((*p_queue).first==NULL){
		free(p_queue);
		return;
		}
	
	qcell_map *list_loop2;
	qcell_map *list_loop= (*p_queue).first; 
	
	//iterate over cells
	while (list_loop != NULL) {
		
		list_loop2=(*list_loop).next;
		
		//free map struct content
		free((*(*list_loop).map_struct).map_array);
		free((*list_loop).map_struct);
		free(list_loop);
		list_loop = list_loop2;

	}
	//free queue cell
	free(p_queue);
}


void free_qcell(qcell_map *configuration){
		//free map struct content	
		free((*(*configuration).map_struct).map_array);
		free((*configuration).map_struct);
		free(configuration);
}
