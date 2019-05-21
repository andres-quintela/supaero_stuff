/**
 * @file linked_list_map.c
 *
 *
 * @brief Simple implementation of a linked list.
 *
 * The implementation of the linked list.
 */

#include "linked_list_map.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

linked_list_map *nil(void) {
	
	linked_list_map *p_list = malloc(sizeof(linked_list_map));
	*p_list=NULL;
	return p_list;
}

void cons(linked_list_map *p_list,game_map *elt){
	
	cell_map* element = malloc(sizeof(cell_map));

	if (*p_list==NULL){

		(*element).map_struct = elt;
		(*element).next = NULL;
		*p_list=element;
		}
	
	else{
		(*element).map_struct = elt;
		(*element).next = *p_list;
		*p_list=element;
		}
}

int size(linked_list_map *list) {
	linked_list_map list_loop= *list; 
	int counter = 0;
	while (list_loop != NULL){
		counter=counter+1;
		list_loop = (*list_loop).next;
	}
	return counter;
}

bool is_empty(linked_list_map *p_list) {
	
	if (p_list==NULL){
		return true;
		}
	else {
		return false;
		}
}
void deallocate_list(linked_list_map *list) {
	
	linked_list_map list_loop=*list;
	linked_list_map list_loop2=*list;

	while (list_loop != NULL){
		list_loop2=(*list_loop).next;
		
		free((*(*list_loop).map_struct).map_array);
		free((*list_loop).map_struct);
		free(list_loop);
		
		list_loop=list_loop2;
	}
	free(list);

}

void *print_list(linked_list_map *list) {
	linked_list_map list_loop= *list; 
	while (list_loop != NULL) {
		print_map((*list_loop).map_struct);
		list_loop = (*list_loop).next;
	}
	return EXIT_SUCCESS;
}
