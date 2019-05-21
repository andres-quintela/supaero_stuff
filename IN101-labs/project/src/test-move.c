#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#include "sokoban.h"
#include "loader.h"




int main(void) {


	//define input and comparison file sizes
	
	char input_map[21];
	char output_map[23];
	char directions[4]= "EWNS";
	
	
	FILE* in_map = NULL;
	FILE* result_map = NULL;
	
	//case 1 soko_move_1 and 2
	
	
	for(int i = 1; i <=2; i++){
	//open each map
	 sprintf(input_map,"./data/soko_move_%d.in", i);
	 
	 //iterate over directions
	 for(int j=0; j<4; j++){
		 
		 
		 /*Loading the original file*/
		 in_map = fopen(input_map,"r");
		 
		 printf("Original map \n");
		 game_map* map_struct = load(in_map);
		 print_map(map_struct);
		 
		 //Making a move in the original map
		 game_map* newmap_struct = move(map_struct,directions[j]);
		 printf("Original map + movement \n");
		 print_map(newmap_struct);
		 
		 //open and print result file
		 sprintf(output_map,"./data/soko_move_%d_%c.in", i, directions[j]);
		 
		 result_map = fopen(output_map,"r");
		 game_map* resultmap_struct = load(result_map);
		 printf("Expeced map \n");
		 print_map(resultmap_struct);
		 
		 //comparing if maps are the same
		 
		 //comparing using assert function
		   for (int w=0; w < (*newmap_struct).width; w++){
			 for (int h=0; h < (*newmap_struct).height; h++){
				 assert((*resultmap_struct).map_array[w + (*newmap_struct).width *h] == ((*newmap_struct).map_array)[w + (*newmap_struct).width*h]);
			 }
		 }
 		//freeing opened maps	

		 
		 free((*newmap_struct).map_array);
		 free(newmap_struct);
		
		 free((*resultmap_struct).map_array);
		 free(resultmap_struct);
		 
		 
		 
		}
	}
	
	////////////////////////////////////////////////////
	//case soko_move_ 3 4 5 6
	
	
	for(int I = 3; I <=6; I++){
	
	 
	 //iterate over directions
	 for(int J=1; J<=4; J++){
		 
		 //open each map
		sprintf(input_map,"./data/soko_move_%d_%d.in",I,J);
		 
		 
		 /*Loading the original file*/
		 in_map = fopen(input_map,"r");
		 
		 printf("Original map \n");
		 game_map* map_struct = load(in_map);
		 print_map(map_struct);
		 
		 //Making a move in the original map
		 game_map* newmap_struct = move(map_struct,directions[I-3]);
		 printf("Original map + movement \n");
		 print_map(newmap_struct);
		 
		 //open and print result file
		 sprintf(output_map,"./data/soko_move_%d_%d_%c.in", I,J, directions[I-3]);
		 
		 result_map = fopen(output_map,"r");
		 game_map* resultmap_struct = load(result_map);
		 printf("Expeced map \n");
		 print_map(resultmap_struct);
		 
		 //comparing if maps are the same
		 
		 //comparing using assert function
		   for (int w=0; w < (*newmap_struct).width; w++){
			 for (int h=0; h < (*newmap_struct).height; h++){
				 assert((*resultmap_struct).map_array[w + (*newmap_struct).width *h] == ((*newmap_struct).map_array)[w + (*newmap_struct).width*h]);
			 }
		 }
		 
 		//freeing opened maps	

		 free((*newmap_struct).map_array);
		 free(newmap_struct);
		
		 free((*resultmap_struct).map_array);
		 free(resultmap_struct);
		 
		 
		}
	}
	
	/////////////////////////////////////////////////:
	// case soko_move_W_
	
	for(int i = 1; i <=2; i++){
		//open each map
		sprintf(input_map,"./data/soko_move_W_%c.in",directions[i-1]);
	 
		 /*Loading the original file*/
		 in_map = fopen(input_map,"r");
		 
		 printf("Original map \n");
		 game_map* map_struct = load(in_map);
		 print_map(map_struct);
		 
		 //Making a move in the original map
		 game_map* newmap_struct = move(map_struct,directions[i-1]);
		 printf("Original map + movement \n");
		 print_map(newmap_struct);
		 
		 result_map = fopen(input_map,"r");
		 game_map* resultmap_struct = load(result_map);
		 printf("Expeced map \n");
		 print_map(resultmap_struct);
		 
		 //comparing if maps are the same
		 
		 //comparing using assert function
		   for (int w=0; w < (*newmap_struct).width; w++){
			 for (int h=0; h < (*newmap_struct).height; h++){
				 assert((*resultmap_struct).map_array[w + (*newmap_struct).width *h] == ((*newmap_struct).map_array)[w + (*newmap_struct).width*h]);
			 }
		 }
		//freeing opened maps	

		 free((*newmap_struct).map_array);
		 free(newmap_struct);
		
		 free((*resultmap_struct).map_array);
		 free(resultmap_struct);
		 
		 
	}
	
	/////////////////////////////////////////////////
	
		// case soko_move_B_W

	
	for(int i = 1; i <=2; i++){
		//open each map
		sprintf(input_map,"./data/soko_move_B_W_%c.in",directions[i-1]);
	 
		 /*Loading the original file*/
		 in_map = fopen(input_map,"r");
		 
		 printf("Original map \n");
		 game_map* map_struct = load(in_map);
		 print_map(map_struct);
		 
		 //Making a move in the original map
		 game_map* newmap_struct = move(map_struct,directions[i-1]);
		 printf("Original map + movement \n");
		 print_map(newmap_struct);
		 
		 result_map = fopen(input_map,"r");
		 game_map* resultmap_struct = load(result_map);
		 printf("Expeced map \n");
		 print_map(resultmap_struct);
		 
		 //comparing if maps are the same
		 
		 //comparing using assert function
		   for (int w=0; w < (*newmap_struct).width; w++){
			 for (int h=0; h < (*newmap_struct).height; h++){
				 assert((*resultmap_struct).map_array[w + (*newmap_struct).width *h] == ((*newmap_struct).map_array)[w + (*newmap_struct).width*h]);
			}
		}
		//freeing opened maps	

		 free((*newmap_struct).map_array);
		 free(newmap_struct);
		
		free((*resultmap_struct).map_array);
		 free(resultmap_struct);
		 	 
	}
	
	/////////////////////////////////////////////////
	
		// case soko_move_B_B

	
	for(int i = 1; i <=2; i++){
		//open each map
		sprintf(input_map,"./data/soko_move_B_B_%c.in",directions[i-1]);
	 
		 /*Loading the original file*/
		 in_map = fopen(input_map,"r");
		 
		 printf("Original map \n");
		 game_map* map_struct = load(in_map);
		 print_map(map_struct);
		 
		 //Making a move in the original map
		 game_map* newmap_struct = move(map_struct,directions[i-1]);
		 printf("Original map + movement \n");
		 print_map(newmap_struct);
		 
		 result_map = fopen(input_map,"r");
		 game_map* resultmap_struct = load(result_map);
		 printf("Expeced map \n");
		 print_map(resultmap_struct);
		 
		 //comparing if maps are the same
		 
		 //comparing using assert function
		   for (int w=0; w < (*newmap_struct).width; w++){
			 for (int h=0; h < (*newmap_struct).height; h++){
				 assert((*resultmap_struct).map_array[w + (*newmap_struct).width *h] == ((*newmap_struct).map_array)[w + (*newmap_struct).width*h]);
			}
		}
		//freeing opened maps	
		 free((*newmap_struct).map_array);
		 free(newmap_struct);
		
		 free((*resultmap_struct).map_array);
		 free(resultmap_struct);
		 	 
	}
	
	printf("ALL MAPS WERE CHECKED CORRECTLY\n");
	
    return EXIT_SUCCESS;
}




