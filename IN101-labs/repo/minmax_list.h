/**
 * @file minmax_list.h
 *
 * @author C. Garion
 */

#ifndef LIST_H
#define LIST_H

#include "linked_list_int.h"

typedef struct minmax_list minmax_list;

struct minmax_list {
    linked_list_int linked_list;
    int nb;
    int max;
    int min;
};

/**
 * Create a new empty list.
 *
 * @return a pointer to a dynamically created `minmax_list`
 *         struct such that:
 *         <ul><li>the linked list inside is nil</li>
 *             <li>the number of elements is 0</li>
 *             <li>the max value is -100</li>
 *             <li>the min value is 100</li></ul>
 */
minmax_list *create_empty_list();

/**
 * Is the list empty?
 *
 * @param p_list a pointer to the list to be tested
 *
 * @pre `p_list` is not `NULL`
 *
 * @return `true` if the list pointed by `p_list` is empty,
 *         `false` otherwise
 */
bool is_list_empty(minmax_list *p_list);

/**
 * The maximum value in a list.
 *
 * @param p_list a pointer to the list
 *
 * @pre `p_list` is not `NULL`
 *
 * @return the maximum value contained in the list
 */
int get_max(minmax_list *p_list);

/**
 * The minimum value in a list.
 *
 * @param p_list a pointer to the list
 *
 * @pre `p_list` is not `NULL`
 *
 * @return the minimum value contained in the list
 */
int get_min(minmax_list *p_list);

/**
 * Add an element in front of the list.
 *
 * @param p_list  a pointer to the list
 * @param element the element to be added
 *
 * @pre `p_list` is not `NULL` and `element` is
 *       comprised between `-100`and `100`
 *
 * @post The list pointed by `p_list` as `element`
 *       for first element and the encapsulated number
 *       of elements, maximum and minimum are updated accordingly.
 */
void add_first(minmax_list *p_list, int element);

/**
 * Append two lists.
 *
 * @param p_list_1 a pointer to the list
 * @param p_list_2 a pointer to the list to append
 *
 * @pre `p_list_1` and `p_list_2`are not `NULL
 *
 * @post The list pointed by `p_list_2` is not changed. The list
 *       pointed by `p_list_1` is such that
 *       <ul><li>the initial elements of the list are not
 *               changed</li>
 *           <li>the list pointed by `p_list_2` is linked
 *               to the end of the list</li>
 *           <li>`nb`, `max` and `min` are updated accordingly</li></ul>
 */
void append(minmax_list *p_list_1, minmax_list *p_list_2);

/**
 * Reverse a list.
 *
 * @param p_list  a pointer to the list to be reversed
 *
 * @pre `p_list` is not `NULL`
 *
 * @post The list pointed by `p_list` is reversed. The
 *       operation is performed only by changing cell links inside
 *       the list.
 */
void reverse(minmax_list *p_list);

#endif
