#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sokoban.h"
#include "bst-map.h"
#include "loader.h"
#include "queue_map.h"
#include "solver-bst.h"
#include "string.h"


int main(void) {
	
	//open csv file
	
	FILE *p_file = NULL;
	FILE *p_file2 = NULL;
	
	

	p_file = fopen("./data/tests-solver.csv","r");
	
	//allocate sufficient memory for all characters
	char *lines=malloc(sizeof(char)*2000);
	
	//get first line
	fgets(lines,2000,p_file);
	for (int i=0; i<5;i++){
		//get next lines
		fgets(lines,1000,p_file);
		//get line values
		
		char* file = strtok(lines,",");
		char* sol  = strtok(NULL,","); 
		int length  = atoi(strtok(NULL,",")); 
		char* plan  = strtok(NULL,","); 
		
		if (*sol=='t'){
		printf("The given plan is: %s\n",plan);
		printf("The given plan length is: %d\n",length);
		}
		else{
		printf("Map has no solution\n");	
		}
		//get map and solve it using bst
		p_file2=fopen(file,"r");
		game_map *map_struct=load(p_file2);
		
		stats *data=solve(map_struct);
		printf("My solution is:\n");
		print_stats(data);
		
		free((*data).plan);
		free(data);
		}

				
return 0;
}
