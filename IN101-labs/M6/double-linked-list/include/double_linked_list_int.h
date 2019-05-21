/**
 * @file double_linked_list_int.h
 *
 * @brief Simple definition of double linked list containing `int` values
 *
 * @author Christophe Garion
 *
 * This is a simple definition of a double linked list containing `int`
 * values implemented using cells linked by pointers. Warning: the cells
 * pointers should not be shared as deallocation of a double linked list
 * deallocates the memory space reserved for the cells!
 *
 * The API of the linked list is defined as follows:
 *
 * - a function to create an empty list
 * - a function to append an element at the beginning of the list
 * - a function to append an element at the end of the list
 * - a function to return the size of a list
 * - a function to check if a list is empty or not
 * - a function to get the element at a specified position
 * - a function to insert an element at a specified position in
 *   the list
 * - a function to remove an element at a specified position
 *   in the list
 * - a function to deallocate a list
 * - a function to print a list
 */

#ifndef DOUBLE_LINKED_LIST_INT_H
#define DOUBLE_LINKED_LIST_INT_H

#include <stdbool.h>

/**
 * @brief An alias for the structure representing the cells
 */
typedef struct cell_int cell_int;

/**
 * @brief The structure representing the cells of the list
 */
struct cell_int {
    /** the value in the cell */
    int      value;
    /** the next cell in the list */
    cell_int *next;
    /** the previous cell in the list */
    cell_int *previous;
};

/**
 * @brief An alias for the structure representing the
 *        double linked list
 */
typedef struct double_linked_list_int double_linked_list_int;

/**
 * @brief The structure representing a double linked list
 */
struct double_linked_list_int {
    /** the size of the list */
    int      size;
    /** the first cell in the list */
    cell_int *first;
    /** the last cell in the list */
    cell_int *last;
};

/**
 * @brief Creates an empty list
 *
 * @param p_list  a pointer to a pointer to the list
 *                to be set to nil
 *
 * @post After the call, p_list points to a
 *       `double_linked_list_int` with size equals to 0 and `first`
 *       and `last` pointers NULL
 */
void nil(double_linked_list_int **p_list);

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
void cons(double_linked_list_int *p_list, int value);

/**
 * @brief Append an element at the end of a list
 *
 * @param p_list  a pointer to the list to be modified
 * @param value   the value to be added in the list
 *
 * @post The last cell of the list is now a new cell
 *       containing the value passed as parameter. The
 *       other cells of the list are not modified and the
 *       new last cell has the previously last cell for
 *       previous cell.
 */
void snoc(double_linked_list_int *p_list, int value);

/**
 * @brief The length of a list
 *
 * @param p_list  a pointer to the list whose length is wanted
 *
 * @return the length of the list (i.e. the number of distinct cells
 *         in the list)
 */
int size(const double_linked_list_int *p_list);

/**
 * @brief Is the list empty?
 *
 * @param p_list  a pointer to the list
 *
 * @return true is the list is empty, false else
 */
bool is_empty(const double_linked_list_int *p_list);

/**
 * @brief Get an element in the list at a specified position
 *
 * @param p_list  a pointer to the list to be queried
 * @param pos     the position of the wanted element
 * @pre   `pos` should be comprised between 0 and the length of
 *         the list (excluded)
 *
 * @return the value stored at position `pos`
 */
int get_element(const double_linked_list_int *p_list, int pos);

/**
 * @brief Insert an element in the list at a specified position
 *
 * @param p_list  a pointer to the list in which the element is inserted
 * @param pos     the position of the wanted element
 * @param value   the value of the new element
 * @pre   `pos` should be comprised between 0 and the length of
 *         the list
 *
 * @post Consider a call `insert_element(p_l, pos, value)`
 *       and let us suppose that the list before the call is
 *       represented by `old_list` and `length` represents the length of
 *       the list after call then:
 *       - \f$\forall i \in [0, ..., pos - 1]\f$ `get_element(*p_l, i) ==
 *       get_element(old_list, i)`
 *       - `get_element(*p_l, pos) == value`
 *       - \f$\forall i \in [pos + 1, ..., length]\f$
 *       `get_element(*p_l, i) == get_element(old_list, i - 1)`
 */
void insert_element(double_linked_list_int *p_list, int pos, int value);

/**
 * @brief Remove an element in the list at a specified position
 *
 * @param p_list  a pointer to the list from which the element is to be removed
 * @param pos     the position of the element
 * @pre   `pos` should be comprised between 0 and the length of
 *         the list (excluded)
 *
 * @post Consider a call `insert_element(p_l, pos, value)` and
 *       let us suppose that the list before the call is represented
 *       by `old_list` and `length` represents the length of
 *       the list after call, then:
 *       - \f$\forall i \in [0, ..., pos - 1]\f$ `get_element(*p_l, i) ==
 *       get_element(old_list, i)`
 *       - \f$\forall i \in [pos, ..., length - 1]\f$
 *       `get_element(*p_l, i) == get_element(old_list, i + 1)`
 */
void remove_element(double_linked_list_int *p_list, int pos);

/**
 * @brief Deallocate a list
 *
 * @param p_list  a pointer to the list to be deallocated
 *
 * @post After the call to `deallocate_list`, all cells composing `list`
 *       are deallocated AND the structure representing the list is also
 *       deallocated. `p_list` is `NULL` after the call.
 */
void deallocate_list(double_linked_list_int *p_list);

/**
 * @brief Print a list
 *
 * @param p_list  a pointer to the list to be printed
 *
 * @post After the call to `print_list`, the list is printed on the console
 *       in classical format using `[]`.
 */
void print_list(const double_linked_list_int *p_list);

#endif
