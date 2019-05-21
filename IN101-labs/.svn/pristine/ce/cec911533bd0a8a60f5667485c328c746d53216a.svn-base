#include <stdlib.h>
#include <stdbool.h>


#include "sokoban.h"
#include "gui.h"
#include "loader.h"

void print_level(game_map *map_struct ) {
	
	int width=(*map_struct).width;
	int height=(*map_struct).height;
	char *map_array=(*map_struct).map_array;

	int counter=0;
    for (int line = 0; line < height; line++){
        for (int col = 0; col < width; col++){
            GUI_Show(col, line, map_array[counter]);
            counter+=1;
		}
	}
}



int main(int argc, char *argv[]) {

    // testing if a filename has been given
    if (argc != 2) {
        fprintf(stderr, "You must provide a file name!\n");
        exit(EXIT_FAILURE);
    }

    // open file. The filename is the first argument on the command
    // line, hence stored in argv[1]
    FILE *p_file = NULL;

    p_file = fopen(argv[1], "r");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    //call load function and get map structure
    game_map *map_struct=load(p_file);
    
    char movement;
    bool stop = false;

    
    // initialize GUI window with map dimensions
    GUI_Init("Sokoban", (*map_struct).width, (*map_struct).height);
    
    //avoid movement when other keys are pressed
    int do_nothing=0;
    
    while (true){
			
			//update map
			print_level(map_struct);
		
			switch (GUI_GetKey()) {
				
			case SDLK_UP:
				movement=NORTH;
				break;
			case SDLK_DOWN:
				movement=SOUTH;
				break;
			case SDLK_RIGHT:
				movement=EAST;
				break;
			case SDLK_LEFT:
				movement=WEST;
				break;
			case 'q':  // a for french keyboards
				stop = true;
				break;
			case 'a':  // a for french keyboards
				stop = true;
				break;
				
			default:
				do_nothing=1;
			}
		
		if (stop) {
            break;
			}
		if (do_nothing!=1)	{
			game_map *map_struct1=move(map_struct,movement);
			map_struct=map_struct1;
		}
		do_nothing=0;
	}
	
	//free last map
	free((*map_struct).map_array);
	free(map_struct);
	
	GUI_Close(EXIT_SUCCESS);
	return EXIT_SUCCESS;
} 
