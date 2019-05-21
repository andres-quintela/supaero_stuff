/**
 * @file linked_list_map.h
 *
 * @brief Simple definition of linked list containing pointers to `game_struct` values
 *
 * @author Andrés Quintela
 */

#ifndef LINKED_LIST_MAP_H
#define LINKED_LIST_MAP_H

#include <stdbool.h>
#include "sokoban.h"


/**
 * @brief An alias for the structure representing the cells
 */
typedef struct cell_map cell_map;

/**
 * @brief The structure representing the cells of the list
 */
struct cell_map {
    /** the value in the cell */
    game_map  *map_struct;
    /** the next cell in the list */
    cell_map *next;
};

/**
 * @brief An alias for the structure representing the
 *        linked list
 */
typedef cell_map *linked_list_map;

/**
 * @brief Creates an empty list
 *
 * @post After the call, p_list points to a NULL cell.
 */
linked_list_map *nil();

/**
 * @brief Append an element at the beginning of a list
 *
 * @param p_list  a pointer to the list to be modified
 * @param value   the value to be added in the list
 *
 * @post The first cell of the list is now a new cell
 *       containing the value passed as parameter. The
 *       other cells of the list are not modified and the
 *       new first cell has the previously first cell for
 *       next cell.
 */
void cons(linked_list_map *p_list, game_map *map_struct);

/**
 * @brief The length of a list
 *
 * @param p_list  a pointer to the list whose length is wanted
 *
 * @return the length of the list (i.e. the number of distinct cells
 *         in the list)
 */
int size(linked_list_map *list);

/**
 * @brief Is the list empty?
 *
 * @param p_list  a pointer to the list
 *
 * @return true is the list is empty, false else
 */
bool is_empty(linked_list_map *list);

/**
 * @brief Deallocate a list
 *
 * @param p_list  a pointer to the list to be deallocated
 *
 * @post After the call to `deallocate_list`, all cells composing `list`
 *       are deallocated AND the structure representing the list is also
 *       deallocated. `p_list` is `NULL` after the call.
 */
void deallocate_list(linked_list_map *list);

/**
 * @brief Print a list
 *
 * @param p_list  a pointer to the list to be printed
 *
 * @post After the call to `print_list`, the list is printed on the console
 *       in classical format using `[]`.
 */
void *print_list(linked_list_map *list);

#endif
