#include <assert.h>
#include <stdio.h>
#include "minmax_list.h"
#include "test_utils.h"

void test_get_min_singleton() {
    printf("     verifying min of [1] is 1...\n");

    minmax_list *p_list = singleton_list();

    assert (get_min(p_list) == 1);

    printf("     min of [1] is 1: OK!\n");
}

void test_get_min_simple_list() {
    printf("     verifying min of [-1, 2, 4] is -1...\n");

    minmax_list *p_list = simple_list();

    assert (get_min(p_list) == -1);

    printf("     min of [-1, 2, 4] is -1: OK!\n");
}


int main(void) {
    printf("--- tests for get_min\n");

    test_get_min_singleton();
    test_get_min_simple_list();

    printf("--- tests for get_min: OK!\n");
    return 0;
}
