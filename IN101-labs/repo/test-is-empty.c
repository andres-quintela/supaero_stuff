#include <assert.h>
#include <stdio.h>
#include "minmax_list.h"
#include "test_utils.h"

void test_is_empty_nil() {
    printf("     verifying if [] is empty...\n");

    minmax_list *p_list = empty_list();

    assert (is_list_empty(p_list));

    printf("     [] is empty: OK!\n");
}

void test_is_empty_singleton() {
    printf("     verifying if [1] is not empty...\n");

    minmax_list *p_list = singleton_list();

    assert (! is_list_empty(p_list));

    printf("     [1] is not empty: OK!\n");
}

void test_is_empty_simple_list() {
    printf("     verifying if [-1, 2, 4] is not empty...\n");

    minmax_list *p_list = simple_list();

    assert (! is_list_empty(p_list));

    printf("     [-1, 2, 4] is not empty: OK!\n");
}


int main(void) {
    printf("--- tests for is_list_empty\n");

    test_is_empty_nil();
    test_is_empty_singleton();
    test_is_empty_simple_list();

    printf("--- tests for is_list_empty: OK!\n");
    return 0;
}
