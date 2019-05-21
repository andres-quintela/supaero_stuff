#include <assert.h>
#include <stdio.h>
#include "minmax_list.h"
#include "test_utils.h"

void test_append_empty_empty() {
    printf("     trying to append [] to []...\n");

    minmax_list *p_list_1 = empty_list();
    minmax_list *p_list_2 = empty_list();

    append(p_list_1, p_list_2);

    assert (p_list_1->nb  == 0);
    assert (p_list_1->max == -100);
    assert (p_list_1->min == 100);

    printf("     appending [] to []: OK!\n");
}

void test_append_empty_singleton() {
    printf("     trying to append [1] to []...\n");

    minmax_list *p_list_1 = empty_list();
    minmax_list *p_list_2 = singleton_list();

    append(p_list_1, p_list_2);

    int tab_1[] = { 1 };

    assert (p_list_1->nb  == 1);
    assert (p_list_1->max == 1);
    assert (p_list_1->min == 1);
    assert (same_sequence(p_list_1, tab_1, 1));

    int tab_2[] = { 1 };

    assert (p_list_2->nb  == 1);
    assert (p_list_2->max == 1);
    assert (p_list_2->min == 1);
    assert (same_sequence(p_list_2, tab_2, 1));

    printf("     appending [1] to []: OK!\n");
}

void test_append_singleton_empty() {
    printf("     trying to append [] to [1]...\n");

    minmax_list *p_list_1 = singleton_list();
    minmax_list *p_list_2 = empty_list();

    append(p_list_1, p_list_2);

    int tab_1[] = { 1 };

    assert (p_list_1->nb  == 1);
    assert (p_list_1->max == 1);
    assert (p_list_1->min == 1);
    assert (same_sequence(p_list_1, tab_1, 1));

    assert (p_list_2->nb  == 0);
    assert (p_list_2->max == -100);
    assert (p_list_2->min == 100);

    printf("     appending [] to [1]: OK!\n");
}

void test_append_singleton_singleton() {
    printf("     trying to append [1] to [1]...\n");

    minmax_list *p_list_1 = singleton_list();
    minmax_list *p_list_2 = singleton_list();

    append(p_list_1, p_list_2);

    int tab_1[] = { 1, 1 };

    assert (p_list_1->nb  == 2);
    assert (p_list_1->max == 1);
    assert (p_list_1->min == 1);
    assert (same_sequence(p_list_1, tab_1, 2));

    int tab_2[] = { 1 };
    assert (p_list_2->nb  == 1);
    assert (p_list_2->max == 1);
    assert (p_list_2->min == 1);
    assert (same_sequence(p_list_2, tab_2, 1));

    printf("     appending [1] to [1]: OK!\n");
}

void test_append_simple_singleton() {
    printf("     trying to append [1] to [-1, 2, 4]...\n");

    minmax_list *p_list_1 = simple_list();
    minmax_list *p_list_2 = singleton_list();

    append(p_list_1, p_list_2);

    int tab_1[] = { -1, 2, 4, 1 };

    assert (p_list_1->nb  == 4);
    assert (p_list_1->max == 4);
    assert (p_list_1->min == -1);
    assert (same_sequence(p_list_1, tab_1, 4));

    int tab_2[] = { 1 };
    assert (p_list_2->nb  == 1);
    assert (p_list_2->max == 1);
    assert (p_list_2->min == 1);
    assert (same_sequence(p_list_2, tab_2, 1));

    printf("     appending [1] to [-1, 2, 4]: OK!\n");
}

void test_append_singleton_simple() {
    printf("     trying to append [-1, 2, 4] to [1]...\n");

    minmax_list *p_list_1 = singleton_list();
    minmax_list *p_list_2 = simple_list();

    append(p_list_1, p_list_2);

    int tab_1[] = { 1, -1, 2, 4 };

    assert (p_list_1->nb  == 4);
    assert (p_list_1->max == 4);
    assert (p_list_1->min == -1);
    assert (same_sequence(p_list_1, tab_1, 4));

    int tab_2[] = { -1, 2, 4 };
    assert (p_list_2->nb  == 3);
    assert (p_list_2->max == 4);
    assert (p_list_2->min == -1);
    assert (same_sequence(p_list_2, tab_2, 3));

    printf("     appending [-1, 2, 4] to [1]: OK!\n");
}

void test_append_simple_simple() {
    printf("     trying to append [-1, 2, 4] to [-1, 2, 4]...\n");

    minmax_list *p_list_1 = simple_list();
    minmax_list *p_list_2 = simple_list();

    append(p_list_1, p_list_2);

    int tab_1[] = { -1, 2, 4, -1, 2, 4 };

    assert (p_list_1->nb  == 6);
    assert (p_list_1->max == 4);
    assert (p_list_1->min == -1);
    assert (same_sequence(p_list_1, tab_1, 6));

    int tab_2[] = { -1, 2, 4 };
    assert (p_list_2->nb  == 3);
    assert (p_list_2->max == 4);
    assert (p_list_2->min == -1);
    assert (same_sequence(p_list_2, tab_2, 3));

    printf("     appending [-1, 2, 4] to [-1, 2, 4]: OK!\n");
}

int main(void) {
    printf("--- tests for append\n");

    test_append_empty_empty();
    test_append_empty_singleton();
    test_append_singleton_empty();
    test_append_singleton_singleton();
    test_append_simple_singleton();
    test_append_singleton_simple();
    test_append_simple_simple();

    printf("--- tests for append: OK!\n");
    return 0;
}
