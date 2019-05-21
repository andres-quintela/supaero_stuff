/**
 * @file bst-map.h
 *
 * @brief Simple definition of BST containing map values
 *
 */

#ifndef BST_MAP_H
#define BST_MAP_H

#include <stdbool.h>
#include "sokoban.h"



/**
 * @brief An alias to the structure representing the nodes of
 *        the tree.
 */
typedef struct bst_node bst_node;

/**
 * @brief A binary tree is just a pointer to the root node
 *        of the tree.
 */
typedef  bst_node *bst_tree;

/**
 * @brief The structure representing the nodes of the
 *        binary tree.
 */
struct bst_node {
    /** The left subtree of the node */
    bst_tree big;
    /** The value/key in the node */
    game_map  *map_struct;
    /** The right subtree of the node */
    bst_tree small;
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
bst_tree *nil_tree(void);

/**
 * @brief Insert a value in the tree.
 *
 * @param p_tree  a pointer to the tree in which
 *                the value is to be inserted
 * @param map_struct   the map to be inserted
 *
 * @post map is added
 * 
 * @return bool true is map has been explored
 */
bool insert(bst_tree *p_tree, game_map *map_struct);


/**
 * @brief free the tree
 *
 * @param p_tree  a pointer to the tree
 * 
 * @post tree is freed
 * 
 */
void deallocate_tree(bst_tree *p_tree);
#endif
