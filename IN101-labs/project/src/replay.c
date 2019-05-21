#include <stdio.h>
#include <stdlib.h>

#include "sokoban.h"
#include "loader.h"




int main(int argc, char *argv[]) {

 
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
    print_map(map_struct);
    
    int num_of_mov=atoi(argv[2]);
    char *list_of_movs=argv[3];
    
    //call replay function from sokoban.c
    game_map *map_struct1 = replay(map_struct,num_of_mov,list_of_movs);
	
	print_map(map_struct1);
	return EXIT_SUCCESS;	
}
