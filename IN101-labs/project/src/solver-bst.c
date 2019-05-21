#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "sokoban.h"
#include "bst-map.h"
#include "queue_map.h"
#include "solver-bst.h"
#include "loader.h"


//contains all functions used by the bst solver


qcell_map *create_children(qcell_map *current_configuration,bst_tree *explored_tree,queue *search_queue){
	
	char directions[4]={'N','S','W','E'};
	//print_queue(search_queue);
	for (int i =0;i<4;i++){
		char dir = directions[i];
		
		
		
		//perform movement on the map
		//printf("%s\n",(*(*current_configuration).map_struct).map_array);
		game_map *map_struct=move_solver((*current_configuration).map_struct,dir);
		
		bool explored=insert(explored_tree,map_struct);
		
		//if map has already been explored to nothing
		if (explored==true){
			//free newly created map beacuse it is the same
			free((*map_struct).map_array);
			free(map_struct);
			}
		//if map has not bee explored create new configuration cell and add it to search queue
		else {

		//create new configuration cell
		qcell_map *configuration=malloc(sizeof(qcell_map));
		(*configuration).map_struct=map_struct;
		(*configuration).mother=current_configuration;
		(*configuration).action=dir;
		(*configuration).depth=(*current_configuration).depth+1;
		
		
		//add unexplored configuration to seach queue
		enqueue(search_queue, configuration);
		
		
		//check if is winning map
		bool win = is_winning_map(configuration);
		if (win==true){
			return configuration;
			}
		}
	}
	
	return NULL;
}
	



bool is_winning_map(qcell_map *current_configuration){
	
	//get data from map structure
	char *map_array=(*(*current_configuration).map_struct).map_array;
	int width=(*(*current_configuration).map_struct).width;
    int height=(*(*current_configuration).map_struct).height;

    //check if map is winning map or not
	for (int i = 0; i < (width*height); i++){
		
		
		if (map_array[i]==BOX){
			return false;
		}
	}
	return true;
}

char *obtain_path(qcell_map *current_configuration){
	
	//allocate string of winning map
	char *movements=malloc(sizeof(char)*(*current_configuration).depth);
	qcell_map *loop=current_configuration;
	
	for (int i = (*current_configuration).depth; i >0;i--){
			
			char c = (*loop).action;
			
			
			movements[i-1]=c;
			
			loop=(*loop).mother;
			
	}
	return movements;		
}


stats *solve(game_map *map_struct ){   
	
	
    clock_t t = clock();
	stats *data=malloc(sizeof(stats));
	/** intialize queues and lists
	 **/
	queue *search_queue=qnil();
 
	queue *dequeue_queue=qnil();
	
	bst_tree *explored_tree = nil_tree();
 

	 /**create initial configuration**/
	
	qcell_map *first_configuration=malloc(sizeof(qcell_map));
	
	(*first_configuration).map_struct=map_struct;
	(*first_configuration).next=NULL;
	(*first_configuration).mother=NULL;
	(*first_configuration).action='\0';
	(*first_configuration).depth=0;
	
	//enqueue first configuration
	enqueue(search_queue,first_configuration);
	
	//add to explored list initial map
	bool explored = insert(explored_tree,(*first_configuration).map_struct);
	
	if (explored==false){
	printf("\n");
	}
	qcell_map *win=NULL;
	
	qcell_map *current_configuration;

	
	while ((*search_queue).first!=NULL){
		
		//obtain current configuration from search queue
		current_configuration =dequeue(search_queue);
		//add current configuration to dequeued queue
		enqueue(dequeue_queue,current_configuration);
		
		
		//explore children 
		win = create_children(current_configuration,explored_tree,search_queue);
		
		if (win != NULL){
			
			char *movements=obtain_path(win);
			//fill in stats data
			(*data).solution=true;
			(*data).length=(*win).depth;
			(*data).plan=movements;
			
			
			//~ //free plan string
			//~ free(movements);
			break;
		}
		
		
		}
		
		
		if (win == NULL){
			(*data).solution=false;
			(*data).length=0;
			(*data).plan='\0';
			}
			
//deallocate lists and queues
deallocate_tree(explored_tree);
free_queue(search_queue);
free_queue(dequeue_queue);

t = clock() - t; 
(*data).time = ((double)t)/CLOCKS_PER_SEC; // in seconds 

return data;
}


void print_stats(stats *data){
	
	if ((*data).solution==true){
		
		printf("Map has been solved.\n");
		printf("Plan lenght = %d\n",(*data).length);
		
		printf("Plan: \n");
		
		for (int i=0;i<(*data).length;i++){
			printf("%c",(*data).plan[i]);
		}
		printf("\n");
	
		
		printf("The computation time was: = %f seconds\n",(*data).time);
		
		}
	else{
		
		printf("Map does not have a solution.\n");
		}
	
	
	
	}

