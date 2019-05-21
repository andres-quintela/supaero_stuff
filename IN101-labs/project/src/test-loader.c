#include <stdio.h>
#include <stdlib.h>


#include "loader.h"
#include "sokoban.h"


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
    
	//call print function
	print_map(map_struct);
	
	
	//free used memory
	free((*map_struct).map_array);
	free(map_struct);

    return EXIT_SUCCESS;
}
