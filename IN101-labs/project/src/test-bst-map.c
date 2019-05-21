#include "bst-map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sokoban.h"
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
	
	
	bst_tree *tree=nil_tree();
	
	bool explored = insert(tree,map_struct);
	
	explored = insert(tree,map_struct2);
	
	if (explored==true){
		printf("Map explored\n");	
		}
		else{
		printf("Map not explored\n");	

		}
	
	printf("Works fine!\n");
	
	
	deallocate_tree(tree);
	


return 0;
}
