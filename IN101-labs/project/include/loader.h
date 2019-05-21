/**
 * @file loader.h
 *
 * @brief load function definition
 *
 * @author Andres Quintela
 *
 */


#ifndef LOADER_H
#define LOADER_H

#include "sokoban.h"

// import map file and adapt it to game_map structure
/**
 * IN:
 * -pointer to file
 * 
 * OUT:
 * -pointer to map structre
 * 
 * **/
 
 /**
 * @brief Function import map from file
 * 
 * @param *p_file pointer to a file containing the map
 * @pre *p_file can not be null and has to be an accessible directory
 *  
 * @return pointer to a map structure containing the map from the file
 */
game_map *load(FILE *p_file);
#endif
