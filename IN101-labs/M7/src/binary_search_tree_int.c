#include <stdio.h>

#include "binary_search_tree_int.h"

// auxiliary functions
void print_level(bst_int *p_tree, int level) {
    for (int i = 0; i < level - 1; i++) {
        printf("   ");
    }

    if (*p_tree == NULL) {
        printf("%snil\n", level == 0 ? "" : " +-");
        return;
    }

    printf("%s(%d)\n", level == 0 ? "" : " +-", (*p_tree)->value);
    print_level(&(*p_tree)->left, level + 1);
    print_level(&(*p_tree)->right, level + 1);
}

// functions from the signature
void print_bst(bst_int *p_tree) {
    print_level(p_tree, 0);
}
