#include <assert.h>
#include <stdio.h>
#include "minmax_list.h"

int main(void) {
    printf("--- tests for create_empty_list\n");

    minmax_list *p_list = create_empty_list();

    assert (p_list != NULL);

    assert (is_empty(&(p_list->linked_list)));
    assert (p_list->nb == 0);
    assert (p_list->max == -100);
    assert (p_list->min == 100);

    printf("--- tests for create_empty_list: OK!\n");

    return 0;
}
