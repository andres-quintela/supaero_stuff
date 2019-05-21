#include <assert.h>
#include <stdio.h>
#include "minmax_list.h"
#include "test_utils.h"

void test_get_max_singleton() {
    printf("     verifying max of [1] is 1...\n");

    minmax_list *p_list = singleton_list();

    assert (get_max(p_list) == 1);

    printf("     max of [1] is 1: OK!\n");
}

void test_get_max_simple_list() {
    printf("     verifying max of [-1, 2, 4] is 4...\n");

    minmax_list *p_list = simple_list();

    assert (get_max(p_list) == 4);

    printf("     max of [-1, 2, 4] is 4: OK!\n");
}


int main(void) {
    printf("--- tests for get_max\n");

    test_get_max_singleton();
    test_get_max_simple_list();

    printf("--- tests for get_max: OK!\n");
    return 0;
}
