#include <assert.h>
#include <stdio.h>
#include "minmax_list.h"
#include "test_utils.h"

void assert_does_not_change(minmax_list *p_list,
                            int nb, int max, int min) {
    assert (p_list->nb == nb);
    assert (p_list->max == max);
    assert (p_list->min == min);
}

void test_reverse_nil() {
    printf("     verifying reverse of [] is []...\n");

    minmax_list *p_list = empty_list();

    reverse(p_list);

    assert_does_not_change(p_list, 0, -100, 100);

    printf("     reverse of [] is []: OK!\n");
}


void test_reverse_singleton() {
    printf("     verifying reverse of [1] is [1]...\n");

    minmax_list *p_list = singleton_list();

    reverse(p_list);

    int tab[] = { 1 };
    assert_does_not_change(p_list, 1, 1, 1);
    assert (same_sequence(p_list, tab, 1));

    printf("     reverse of [1] is [1]: OK!\n");
}

void test_reverse_simple_list() {
    printf("     verifying reverse of [-1, 2, 4] is [4, 2, -1]...\n");

    minmax_list *p_list = simple_list();

    reverse(p_list);

    int tab[] = { 4, 2, -1 };
    assert_does_not_change(p_list, 3, 4, -1);
    assert (same_sequence(p_list, tab, 3));

    printf("     reverse of [-1, 2, 4] is [4, 2, -1]: OK!\n");
}

int main(void) {
    printf("--- tests for reverse\n");

    test_reverse_nil();
    test_reverse_singleton();
    test_reverse_simple_list();

    printf("--- tests for reverse: OK!\n");
    return 0;
}
