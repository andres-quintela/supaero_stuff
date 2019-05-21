/**
 * @file binary_search_tree_int.h
 *
 * @brief Simple definition of BST containing `int` values
 *
 * @author Christophe Garion
 *
 * This is a simple definition of a binary search tree containing `int`
 * values implemented using nodes linked by pointers. Warning: the cells
 * pointers should not be shared as deallocation of a BST
 * deallocates the memory space reserved for the cells!
 *
 * The API of the BST is defined as follows:
 *
 * - a function to create an empty BST
 * - a function to check is the BST is empty
 * - a function to get the value at the root of the BST
 * - a function to get the size of the BST
 * - a function to get the height of the BST
 * - a function to get the left child of the BST
 * - a function to get the right child of the BST
 * - a function to retrieve a value in the BST
 * - a function to insert a value in the BST
 * - a function to delete a value in the BST
 * - a function to insert a value in the BST (AVL)
 * - a function to delete a value in the BST (AVL)
 * - a function to print the nodes values in-order
 * - a function to deallocate the BST
 * - a function to print the BST
 */

#ifndef BINARY_SEARCH_TREE_INT_H
#define BINARY_SEARCH_TREE_INT_H

#include <stdbool.h>

/**
 * @brief An alias to the structure representing the nodes of
 *        the tree.
 */
typedef struct bst_node_int bst_node_int;

/**
 * @brief A binary tree is just a pointer to the root node
 *        of the tree.
 */
typedef bst_node_int *bst_int;

/**
 * @brief The structure representing the nodes of the
 *        binary tree.
 */
struct bst_node_int {
    /** The left subtree of the node */
    bst_int left;
    /** The value/key in the node */
    int       value;
    /** The right subtree of the node */
    bst_int right;
};

/**
 * @brief Create a nil binary search tree.
 *
 * @param p_tree  a pointer to the binary search tree to
 *                be set to nil
 *
 * @post After the call, p_tree points to an empty binary
 *       search tree.
 */
void nil(bst_int *p_tree);

/**
 * @brief Is the binary search tree empty?
 *
 * @param p_tree  a pointer to the tree you want to
 *                check the emptiness
 *
 * @return `true` if `p_tree` is empty, `false` else
 */
bool is_empty(bst_int *p_tree);

/**
 * @brief The value in the root of the binary search tree.
 *
 * @param p_tree  a pointer to the tree
 *
 * @pre `p_tree` is not empty.
 *
 * @return the value in the root of the tree
 */
int value(bst_int *p_tree);

/**
 * @brief The number of nodes in the binary search tree.
 *
 * @param p_tree a pointer to the tree
 *
 * @return the number of nodes in the tree
 */
int size(bst_int *p_tree);

/**
 * @brief The height of the binary search tree.
 *
 * @param p_tree a pointer to the tree
 *
 * @return the height of the tree
 */
int height(bst_int *p_tree);

/**
 * @brief The left subtree of the tree.
 *
 * @param p_tree a pointer to the tree
 *
 * @pre `p_tree` is not empty.
 *
 * @return the left subtree of `p_tree`
 */
bst_int left_child(bst_int *p_tree);

/**
 * @brief The right subtree of the tree.
 *
 * @param p_tree a pointer to the tree
 *
 * @pre `p_tree` is not empty.
 *
 * @return the right subtree of `p_tree`
 */
bst_int right_child(bst_int *p_tree);

/**
 * @brief Retrieve a value in the tree.
 *
 * @param p_tree  a pointer to the tree
 * @param value   the value to search
 *
 * @return an empty tree if the value is not in
 *         the binary search tree, the subtree
 *         whose root contains the value otherwise
 */
bst_int retrieve(bst_int *p_tree, int value);

/**
 * @brief Insert a value in the tree.
 *
 * @param p_tree  a pointer to the tree in which
 *                the value is to be inserted
 * @param value   the value to be inserted
 *
 * @post After the call, there is a node containing
 *       `value` in the tree pointed by `p_tree`. This
 *       node is correctly placed with respect to the
 *       binary search tree property. If the node was
 *       already in the tree, no new node is inserted.
 */
void insert(bst_int *p_tree, int value);

/**
 * @brief Delete a value in the tree.
 *
 * @param p_tree  a pointer to the tree in which
 *                the value is to be deleted
 * @param value   the value to be deleted
 *
 * @post After the call, if there was a node containing
 *       `value` in the tree pointed by `p_tree`, it is
 *       deleted. This deletion is such that the binary
 *       search property is verified. If the node was
 *       not in the tree, the tree is the same than before
 *       the call.
 */
void delete(bst_int *p_tree, int value);

/**
 * @brief Traverse the tree depth-first and print the value
 *        in order.
 *
 * @param p_tree  a pointer to the tree to be traversed
 *
 * @post After the call, the values in the nodes are printed
 *       in order.
 */
void in_order_dfs(bst_int *p_tree);

/**
 * @brief Deallocate the binary search tree.
 *
 * @param p_tree  a pointer to the tree to be deallocated
 *
 * @post After the call, all memory regions used for the nodes
 *       are deallocated
 */
void deallocate_bst(bst_int *p_tree);

/**
 * @brief Prints the tree.
 *
 * @param p_tree  a pointer to the tree to be printed
 *
 * @post After the call, the tree is printed.
 */
void print_bst(bst_int *p_tree);

/**
 * @brief Insert a value in a AVL binary search tree
 *
 * @param p_tree  a pointer to the AVL tree in which
 *                the value is to be inserted
 * @param value   the value to be inserted
 * @pre `p_tree` is a pointer to an AVL binary search
 *               tree
 *
 * @post After the call, there is a node containing
 *       `value` in the tree pointed by `p_tree`. This
 *       node is correctly placed with respect to the
 *       AVL binary search tree property. If the node was
 *       already in the tree, no new node is inserted.
 */
void insert_avl(bst_int *p_tree, int value);

/**
 * @brief Delete a value in a AVL binary search tree.
 *
 * @param p_tree  a pointer to the AVL tree in which
 *                the value is to be deleted
 * @param value   the value to be deleted
 *
 * @pre `p_tree` is a pointer to an AVL binary search
 *               tree
 *
 * @post After the call, if there was a node containing
 *       `value` in the tree pointed by `p_tree`, it is
 *       deleted. This deletion is such that the AVL binary
 *       search property is verified. If the node was
 *       not in the tree, the tree is the same than before
 *       the call.
 */
void delete_avl(bst_int *p_tree, int value);

#endif
