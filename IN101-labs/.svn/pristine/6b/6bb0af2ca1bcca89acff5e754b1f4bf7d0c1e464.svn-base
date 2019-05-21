/**
 * @file stack_int.h
 *
 * @brief Simple definition of a stack containing `int` values
 *
 * @author Christophe Garion
 *
 * This is a simple definition of a stack containing `int` values
 * implemented using a linked list.
 *
 * The API of the stack is defined as follows:
 *
 * - a function to create an empty stack
 * - a function to verify if the stack is empty
 * - a function to push an element on the stack
 * - a function to pop the element on top of the stack
 * - a funtion to deallocate a stack
 * - a function to print a stack
 */

#ifndef STACK_INT_H
#define STACK_INT_H

#include <stdbool.h>
#include "linked_list_int.h"

/**
 * `stack_int` is an alias for a linked list representing
 * the stack.
 */
typedef linked_list_int stack_int;

/**
 * @brief Initialize an empty stack.
 *
 * @param p_stack  a pointer to the stack to be initialized
 *
 * @post After the call, p_stack is a pointer to an empty stack.
 */
void create_empty_stack(stack_int *p_stack);

/**
 * @brief Is a stack empty?
 *
 * This function returns a boolean indicating if the stack is empty or
 * not.
 *
 * @param p_stack  a pointer to the stack to be queried
 * @return `true` if the stack is empty, `false` if the stack is not
 */
bool is_stack_empty(const stack_int *p_stack);

/**
 * @brief Push an element on top of a stack.
 *
 * This function pushes an element on top of the stack.
 *
 * @param  p_stack a pointer to the stack to be modified
 * @param  element the element to be pushed on top of the stack
 *
 * @post After a call to `push(p_s, v)` with `p_s` pointing
 *       to a stack `s`, then:
 *       - all the previous elements contained in `s` remains in the same order
 *       - the top element of `s` contains the value `v`
 *       - the second element of `s` was the top element of `s` before the call
 */
void push(stack_int *p_stack, int element);

/**
 * @brief Pops the element on top of a stack.
 *
 * This function pops the element on top of the stack. The element is
 * removed from the stack and the value contained in the element is
 * returned.
 *
 * @param  p_stack the stack to be modified
 * @pre `p_stack` cannot point to an empty stack
 *
 * @return the value contained in the top element of the stack
 * @post After a call to `pop(p_s)` with `p_s` pointing to a stack `s`,
 *       the top element of `s` is now the element that was at second
 *       position in `s` before the call. The previously first element
 *       is freed.
 */
int pop(stack_int *p_stack);

/**
 * @brief Deallocate a stack.
 *
 * This function deallocate each cell of the stack. The stack can be empty.
 *
 * @param p_stack  a pointer to the stack to be deallocated
 *
 * @post After a call to `deallocate`, all the cells used to represent the
 *       stack are freed. `p_stack` is also freed and assigned to `NULL`.
 */
void deallocate_stack(stack_int *p_stack);

/**
 * @brief Print a stack.
 *
 * This function prints the given stack to the standard output. The
 * representation is
 *
 *    | 0
 *    | 1
 *    | 2
 *    +----
 *
 * `+----` indicates the bottom of the stack.
 *
 * @param p_stack  a pointer to the stack to be printed
 */
void print_stack(const stack_int *p_stack);

#endif
