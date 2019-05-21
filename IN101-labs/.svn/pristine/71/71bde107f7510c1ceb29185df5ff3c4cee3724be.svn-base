/**
 * @file sokoban.h
 *
 * @brief All game functions
 *
 * @author Andres Quintela
 *
 */


#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <stdbool.h>


//define map symbols

#define BOY '@'
#define BOY_ON '+'
#define BOX '$'
#define BOX_ON '*'
#define CELL_DEST '.'
#define CELL ' '
#define WALL '#'


//define movements

#define NORTH 'N'
#define SOUTH 'S'
#define EAST 'E'
#define WEST 'W'


//define map structure
/**
 * @brief An alias to the struct representing the map.
 */
typedef struct game_map  game_map;

/**
 * @brief The structure representing the map.
 */
struct game_map {
	    /** The height of the map*/
    int height;
        /** The width of the map */
    int width;
        /** The actual player position */
    int position;  
        /** The pointer to the array containing the map */
    char *map_array;
};

/**
 * @brief Function to print map
 *
 * @param *map_struct pointer to a map structure
 * @pre *map_struct can not be null
 *
 * @post Map printed on terminal
 */
void print_map(game_map *map_struct);


 /**
 * @brief Function to move player
 *
 * @param *map_struct pointer to a map structure in which to perform movement
 * @pre *map_struct can not be null
 * 
 * @param direction direction in which to move the player
 *  
 * @return pointer to a map with movement performed or same map if movement was not possible
 */
game_map *move(game_map *map_struct, char direction);


 /**
 * @brief Function to move player
 *
 * @param *map_struct pointer to a map structure in which to perform movement
 * @pre *map_struct can not be null
 * 
 * @param direction direction in which to move the player
 *  
 * @return pointer to a map with movement performed or same map if movement was not possible
 */
game_map *move_solver(game_map *map_struct, char direction);



/**
 * @brief Function to move player
 *
 * @param *map_struct pointer to a map structure in which to perform movement
 * @pre *map_struct can not be null
 * 
 * @param num_of_mov number of movements to be performed
 * @pre num_of_mov cannot be greater than the length of list_of_movs
 * 
 * @param *list_of_movs string containing the directions of the movements to be performed
 * @pre *list_of_movs characters have to be within the allowed chars
 *  
 * @return pointer to a map with all performed movements
 */
game_map *replay(game_map *map_struct,int num_of_mov,char *list_of_movs);


#endif
