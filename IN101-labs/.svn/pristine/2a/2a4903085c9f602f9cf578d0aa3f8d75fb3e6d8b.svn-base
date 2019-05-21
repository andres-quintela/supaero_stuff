#include "linked_list_map.h"
#include <stdio.h>
#include "loader.h"


int main(void){
	
	//get map 1
	FILE *p_file = NULL;
	p_file = fopen("./data/soko1.in","r");
	game_map *map_struct=load(p_file);
	
	//get map 2
	FILE *p_file2 = NULL;
	p_file2 = fopen("./data/soko_dumb.in","r");
	game_map *map_struct2=load(p_file2);
	
	
	linked_list_map *map_list = nil();
	
	//testing cons
	cons(map_list, map_struct);
	cons(map_list, map_struct2);
	
	//testing if list is empty
	if (is_empty(map_list)){
		
		printf("list empty\n");
		}
	else{
		printf("list not empty\n");
		}
	//printing list
	print_list(map_list);
	
	int sizemap=size(map_list);
	
	printf("%d\n",sizemap);
	
	//deallocate list
	deallocate_list(map_list);
	
	
	return 0;
	} 
