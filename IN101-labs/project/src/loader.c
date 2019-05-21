#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "loader.h"
#include "sokoban.h"


game_map* load(FILE *p_file){

    // read dimensions on first line
    int width         = 0;
    int height        = 0;
    int fscanf_result = 0;

    fscanf_result = fscanf(p_file, "%d %d\n", &width, &height);

    if (fscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }

    // read following lines
    // line_buffer contains a line and is a correct string
    // width + 2 is needed to get the carriage return symbol
    char line_buffer[width + 2];
    
     //allocate memory for the map structure
    game_map *map_struct=malloc(sizeof(game_map));
    
	
	 //allocate memory for the map itself
	char *map_array=malloc(sizeof(char)*((width+2)*height));
    
    for (int i = 0; i < height; i++) {
        fgets(line_buffer, width + 2, p_file);  //get each line from file
        
        for (int j = 0; j <= width; j++){       //get all characters except the carriage return
			map_array[i*width+j]=line_buffer[j];
			if ((line_buffer[j]==BOY) || (line_buffer[j]==BOY_ON)){
				    (*map_struct).position=(i*width+j); //get player position, remember counting starts from 0
				}
		}
    }
    fclose(p_file);
    //save obtained data into the map structure    
    (*map_struct).width=width;
    (*map_struct).height=height;
    (*map_struct).map_array=map_array;
     //return map structure
    return map_struct;
}



