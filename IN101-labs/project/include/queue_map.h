/**
 * @file queue_map.h
 *
 * @brief Simple definition of queue containing pointers to `game_struct` values
 *
 * @author Andrés Quintela
 */

#ifndef QUEUE_MAP_H
#define QUEUE_MAP_H

#include <stdbool.h>
#include "sokoban.h"


/**
 * @brief An alias for the structure representing the cells
 */
typedef struct qcell_map qcell_map;

/**
 * @brief The structure representing the cells of the queue
 */
struct qcell_map {
    /** the value in the cell */
    game_map  *map_struct;
    /** the next cell in the list */
    qcell_map *next;
    /** the mother cell that generated the current map*/
    qcell_map *mother;
    /** action that generated current map*/
    char action;
    /** depth of cell in tree*/
    int depth; 
};



/**
 * @brief An alias for the structure representing the
 *        queue.
 */
typedef struct queue queue;
/**
 * @brief The structure representing the the queue
 */
struct queue {
    /** pointer to first qcell in queue */
    qcell_map *first;
    /** pointer to last qcell in queue */
    qcell_map *last;
};



/**
 * @brief Creates an empty queue
 *
 * @post After the call, p_queue points to a NULL cell.
 */
queue *qnil();

/**
 * @brief Append an element at the end of a the queue
 *
 * @param p_queue  a pointer to the queue to be modified
 * @param qcell a pointer to the qcell to be added to the queue
 *
 * @post The last of the list is now a new cell
 *       containing the value passed as parameter. The
 *       other cells of the list are not modified and the
 *       new first cell has the previously first cell for
 *       next cell.
 */
void *enqueue(queue *p_queue,qcell_map *qcell);

/**
 * @brief remove first element from the queue
 *
 * @param p_queue  a pointer to the queue to be modified
 * @return qcell a pointer to the qcell to be removed from the queue
 */
qcell_map *dequeue(queue *p_queue);


/**
 * @brief print queue
 *
 * @param p_queue  a pointer to the queue to be modified
 * @return printed queue
 */
void print_queue(queue *p_queue);

/**
 * @brief free queue
 *
 * @param p_queue  a pointer to the queue to be freed

 */
void free_queue(queue *p_queue);

/**
 * @brief free queue and cell content
 *
 * @param p_queue  a pointer to the queue to be freed

 */

void free_queue_comp(queue *p_queue);

/**
 * @brief free queue cell
 *
 * @param p_queue  a pointer to the queue to be freed

 */
void free_qcell(qcell_map *configuration);
	


#endif
