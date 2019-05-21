#include <assert.h>
#include <stdio.h>
#include "minmax_list.h"
#include "test_utils.h"

void test_add_first_empty() {
    printf("     trying to add 2 to empty list...\n");

    minmax_list *p_list = empty_list();

    add_first(p_list, 2);
    int tab[] = { 2 };
    assert (p_list->nb  == 1);
    assert (p_list->max == 2);
    assert (p_list->min == 2);
    assert (same_sequence(p_list, tab, 1));

    printf("     adding 2 to empty list: OK!\n");
}

void test_add_first_singleton_1() {
    printf("     trying to add 2 to list [ 1 ]...\n");

    minmax_list *p_list = singleton_list();

    add_first(p_list, 2);
    int tab[] = { 2, 1 };
    assert (p_list->nb  == 2);
    assert (p_list->max == 2);
    assert (p_list->min == 1);
    assert (same_sequence(p_list, tab, 2));

    printf("     adding 2 to list [ 1 ]: OK!\n");
}

void test_add_first_singleton_2() {
    printf("     trying to add -1 to list [ 1 ]...\n");

    minmax_list *p_list = singleton_list();

    add_first(p_list, -1);
    int tab[] = { -1, 1 };
    assert (p_list->nb  == 2);
    assert (p_list->max == 1);
    assert (p_list->min == -1);
    assert (same_sequence(p_list, tab, 2));

    printf("     adding -1 to list [ 1 ]: OK!\n");
}

void test_add_first_simple_list_1() {
    printf("     trying to add 1 to list [ -1, 2, 4 ]...\n");

    minmax_list *p_list = simple_list();

    add_first(p_list, 1);
    int tab[] = { 1, -1, 2, 4 };
    assert (p_list->nb  == 4);
    assert (p_list->max == 4);
    assert (p_list->min == -1);
    assert (same_sequence(p_list, tab, 4));

    printf("     adding 1 to list [ -1, 2, 4 ]: OK!\n");
}

void test_add_first_simple_list_2() {
    printf("     trying to add -3 to list [ -1, 2, 4 ]...\n");

    minmax_list *p_list = simple_list();

    add_first(p_list, -3);
    int tab[] = { -3, -1, 2, 4 };
    assert (p_list->nb  == 4);
    assert (p_list->max == 4);
    assert (p_list->min == -3);
    assert (same_sequence(p_list, tab, 4));

    printf("     adding -3 to list [ -1, 2, 4 ]: OK!\n");
}

void test_add_first_simple_list_3() {
    printf("     trying to add 5 to list [ -1, 2, 4 ]...\n");

    minmax_list *p_list = simple_list();

    add_first(p_list, 5);
    int tab[] = { 5, -1, 2, 4 };
    assert (p_list->nb  == 4);
    assert (p_list->max == 5);
    assert (p_list->min == -1);
    assert (same_sequence(p_list, tab, 4));

    printf("     adding 5 to list [ -1, 2, 4 ]: OK!\n");
}

int main(void) {
    printf("--- tests for add_first\n");

    test_add_first_empty();
    test_add_first_singleton_1();
    test_add_first_singleton_2();
    test_add_first_simple_list_1();
    test_add_first_simple_list_2();
    test_add_first_simple_list_3();

    printf("--- tests for add_first: OK!\n");
    return 0;
}
