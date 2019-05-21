#include "queue_map.h"
#include <stdio.h>
#include "loader.h"
#include <stdlib.h>



int main(void){
	
	//import first configuration
	FILE *p_file = NULL;
	p_file = fopen("./data/soko1.in","r");
	game_map *map_struct=load(p_file);
	
	
	qcell_map *first_configuration=malloc(sizeof(qcell_map));
	
	(*first_configuration).map_struct=map_struct;
	(*first_configuration).next=NULL;
	(*first_configuration).mother=NULL;
	(*first_configuration).action='\0';
	(*first_configuration).depth=0;
	
	
	queue *map_queue = qnil();
	
	//add first configuration to queue
	
	enqueue(map_queue,first_configuration);
	
	//second configuration

	FILE *p_file2 = NULL;
	p_file2 = fopen("./data/soko_dumb.in","r");
	game_map *map_struct2=load(p_file2);

	qcell_map *second_configuration=malloc(sizeof(qcell_map));
	
	(*second_configuration).map_struct=map_struct2;
	(*second_configuration).next=NULL;
	(*second_configuration).mother=NULL;
	(*second_configuration).action='\0';
	
	// enqueue second config
	enqueue(map_queue,second_configuration);
	
	
	//print queue
	print_queue(map_queue);
	
	
	//dequeue config
	qcell_map *configuration2= dequeue(map_queue);
	
	//free dequeued cell
	free_qcell(configuration2);
	
	//free queue
	free_queue_comp(map_queue);
	
	
	return 0;
	} 
