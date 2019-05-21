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
    
    //solve function
    stats *data=solve(map_struct); 	
    
    //print stats
    print_stats(data);
    
    
    //free stats
    free((*data).plan);
    free(data);

return 0;
}
