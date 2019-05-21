#include <stdlib.h>
#include <stdio.h>
#include "linked_list_int.h"
#include "test_utils.h"

minmax_list *empty_list() {
    minmax_list *p_list = malloc(sizeof(minmax_list));

    p_list->linked_list = NULL;
    p_list->nb          = 0;
    p_list->min         = 100;
    p_list->max         = -100;

    return p_list;
}

minmax_list *singleton_list() {
    minmax_list *p_list = malloc(sizeof(minmax_list));

    p_list->linked_list        = malloc(sizeof(cell_int));
    p_list->linked_list->value = 1;
    p_list->linked_list->next  = NULL;

    p_list->nb   = 1;
    p_list->min  = 1;
    p_list->max  = 1;

    return p_list;
}

minmax_list *simple_list() {
    minmax_list *p_list = malloc(sizeof(minmax_list));

    p_list->linked_list = malloc(sizeof(cell_int));
    p_list->linked_list->value = -1;
    p_list->linked_list->next  = malloc(sizeof(cell_int));

    p_list->linked_list->next->value = 2;
    p_list->linked_list->next->next  = malloc(sizeof(cell_int));

    p_list->linked_list->next->next->value = 4;
    p_list->linked_list->next->next->next  = NULL;

    p_list->nb   = 3;
    p_list->min  = -1;
    p_list->max  = 4;

    return p_list;
}

bool same_sequence(minmax_list *p_list, int tab[], int size) {
    int i = 0;

    cell_int *p_cell = p_list->linked_list;

    while (p_cell != NULL) {
        if (! (p_cell->value == tab[i])) {
            return false;
        }

        p_cell = p_cell->next;
        i++;
    }

    return (i == size);
}
