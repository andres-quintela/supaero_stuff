/**
 * @file double_linked_list_int_tests.c
 *
 * @brief Unit tests for double linked list containing `int` values.
 *
 * @author Christophe Garion
 */

#define _GNU_SOURCE
#include "unity_fixture.h"
// do not use Unity malloc and free versions!
#undef malloc
#undef free

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <error.h>

#include "double_linked_list_int.h"

static double_linked_list_int *p_test_list;

// utility function to create test lists
void create_test_list(int length) {
    for (int i = 0; i < length; i++) {
        cell_int *p_cell = (cell_int *) malloc(sizeof(cell_int));
        p_cell->value = i;
        p_cell->next = p_test_list->first;

        if (p_test_list->first != NULL) {
            p_test_list->first->previous = p_cell;
        }

        p_test_list->first = p_cell;

        if (i == 0) {
            p_test_list->last = p_cell;
        }
    }

    p_test_list->size = length;
}

// utility function to test list content
void test_list_content(cell_int **p_p_cell,
                       int start, int end, int offset,
                       char *msg) {
    for (int i = start; i < end ; i++) {
        TEST_ASSERT_EQUAL_INT_MESSAGE(offset - i,
                                      (*p_p_cell)->value, msg);
        *p_p_cell = (*p_p_cell)->next;
    }
}

// utility function to print lists
char *list_to_string(double_linked_list_int *p_list) {
    cell_int *p_current_cell = p_list->first;

    char *buf;
    char *temp;

    asprintf(&buf, "[ ");

    while (p_current_cell != NULL) {
        asprintf(&temp, "%s%d", buf, p_current_cell->value);
        free(buf);
        buf = temp;

        p_current_cell = p_current_cell->next;

        if (p_current_cell != NULL) {
            asprintf(&temp, "%s,", buf);
            free(buf);
            buf = temp;
        }

        asprintf(&temp, "%s ", buf);
        free(buf);
        buf = temp;
    }

    asprintf(&temp, "%s]", buf);
    free(buf);
    buf = temp;

    return buf;
}

/* Tests for nil */

TEST_GROUP(nil);

TEST_SETUP(nil) {
    nil(&p_test_list);
};

TEST_TEAR_DOWN(nil) {
    deallocate_list(p_test_list);
};

TEST(nil, double_linked_list_int_nil) {
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, p_test_list->size,
                                  "the size of the list should be 0!");
    TEST_ASSERT_NULL_MESSAGE(p_test_list->first,
                             "the first element of the list should be NULL!");
    TEST_ASSERT_NULL_MESSAGE(p_test_list->first,
                             "the first element of the list should be NULL!");
}

TEST_GROUP_RUNNER(nil) {
    printf("\n--------------------\n");
    printf("Testing nil function\n\n");

    RUN_TEST_CASE(nil, double_linked_list_int_nil);
};

/* Tests for cons */

TEST_GROUP(cons);

TEST_SETUP(cons) {
    nil(&p_test_list);
};

TEST_TEAR_DOWN(cons) {
    deallocate_list(p_test_list);
};

// A macro to test cons on linked list
#define TEST_DOUBLE_LINKED_LIST_INT_CONS(THE_SIZE)                      \
    TEST(cons, double_linked_list_int_cons_##THE_SIZE) {                \
        create_test_list(THE_SIZE);                                     \
                                                                        \
        char *list_before = list_to_string(p_test_list);                \
                                                                        \
        printf("testing cons(%s, 255)\n", list_before);                 \
                                                                        \
        free(list_before);                                              \
                                                                        \
        cons(p_test_list, 255);                                         \
                                                                        \
        char *list_after = list_to_string(p_test_list);                 \
        char *msg;                                                      \
        char *msg_length;                                               \
                                                                        \
        asprintf(&msg,                                                  \
                 "Your list is %s\n",                                   \
                 list_after);                                           \
                                                                        \
                                                                        \
        free(list_after);                                               \
                                                                        \
        asprintf(&msg_length,                                           \
                 "list length should be %d!\n",                         \
                 THE_SIZE + 1);                                         \
                                                                        \
        cell_int *p_cell = p_test_list->first;                          \
                                                                        \
        TEST_ASSERT_EQUAL_INT_MESSAGE(THE_SIZE + 1,                     \
                                      p_test_list->size,                \
                                      msg_length);                      \
                                                                        \
        free(msg_length);                                               \
                                                                        \
        TEST_ASSERT_EQUAL_INT(255, p_cell->value);                      \
                                                                        \
                                                                        \
        if (p_cell->next != NULL) {                                     \
            p_cell = p_cell->next;                                      \
                                                                        \
        }                                                               \
                                                                        \
        test_list_content(&p_cell, 1, THE_SIZE + 1, THE_SIZE, msg);     \
                                                                        \
        free(msg);                                                      \
    };

TEST_DOUBLE_LINKED_LIST_INT_CONS(0);
TEST_DOUBLE_LINKED_LIST_INT_CONS(1);
TEST_DOUBLE_LINKED_LIST_INT_CONS(2);
TEST_DOUBLE_LINKED_LIST_INT_CONS(3);
TEST_DOUBLE_LINKED_LIST_INT_CONS(4);
TEST_DOUBLE_LINKED_LIST_INT_CONS(5);
TEST_DOUBLE_LINKED_LIST_INT_CONS(6);
TEST_DOUBLE_LINKED_LIST_INT_CONS(7);
TEST_DOUBLE_LINKED_LIST_INT_CONS(8);
TEST_DOUBLE_LINKED_LIST_INT_CONS(9);
TEST_DOUBLE_LINKED_LIST_INT_CONS(10);

TEST_GROUP_RUNNER(cons) {
    printf("\n---------------------\n");
    printf("Testing cons function\n\n");

    RUN_TEST_CASE(cons, double_linked_list_int_cons_0);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_1);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_2);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_3);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_4);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_5);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_6);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_7);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_8);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_9);
    RUN_TEST_CASE(cons, double_linked_list_int_cons_10);
};

/* Tests for snoc */

TEST_GROUP(snoc);

TEST_SETUP(snoc) {
    nil(&p_test_list);
};

TEST_TEAR_DOWN(snoc) {
    deallocate_list(p_test_list);
};

// A macro to test snoc on linked list
#define TEST_DOUBLE_LINKED_LIST_INT_SNOC(THE_SIZE)                      \
    TEST(snoc, double_linked_list_int_snoc_##THE_SIZE) {                \
        create_test_list(THE_SIZE);                                     \
                                                                        \
        char *list_before = list_to_string(p_test_list);                \
                                                                        \
        printf("testing snoc(%s, 255)\n", list_before);                 \
                                                                        \
        free(list_before);                                              \
                                                                        \
        snoc(p_test_list, 255);                                         \
                                                                        \
        char *list_after = list_to_string(p_test_list);                 \
        char *msg;                                                      \
        char *msg_length;                                               \
                                                                        \
        asprintf(&msg,                                                  \
                 "Your list is %s\n",                                   \
                 list_after);                                           \
                                                                        \
                                                                        \
        free(list_after);                                               \
                                                                        \
        asprintf(&msg_length,                                           \
                 "list length should be %d!\n",                         \
                 THE_SIZE + 1);                                         \
                                                                        \
        cell_int *p_cell = p_test_list->first;                          \
                                                                        \
        TEST_ASSERT_EQUAL_INT_MESSAGE(THE_SIZE + 1,                     \
                                      p_test_list->size,                \
                                      msg_length);                      \
                                                                        \
        free(msg_length);                                               \
                                                                        \
                                                                        \
        test_list_content(&p_cell, 0, THE_SIZE, THE_SIZE - 1, msg);     \
                                                                        \
        if (p_cell->next != NULL) {                                     \
            p_cell = p_cell->next;                                      \
                                                                        \
        }                                                               \
                                                                        \
        TEST_ASSERT_EQUAL_INT(255, p_cell->value);                      \
                                                                        \
        free(msg);                                                      \
    };

TEST_DOUBLE_LINKED_LIST_INT_SNOC(0);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(1);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(2);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(3);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(4);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(5);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(6);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(7);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(8);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(9);
TEST_DOUBLE_LINKED_LIST_INT_SNOC(10);

TEST_GROUP_RUNNER(snoc) {
    printf("\n---------------------\n");
    printf("Testing snoc function\n\n");

    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_0);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_1);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_2);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_3);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_4);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_5);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_6);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_7);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_8);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_9);
    RUN_TEST_CASE(snoc, double_linked_list_int_snoc_10);
};

/* Tests for size of list */

TEST_GROUP(size);

TEST_SETUP(size) {
    nil(&p_test_list);
};

TEST_TEAR_DOWN(size) {
    deallocate_list(p_test_list);
};

// A macro to test length on linked list
#define TEST_DOUBLE_LINKED_LIST_INT_SIZE(THE_SIZE)              \
    TEST(size, double_linked_list_int_size_##THE_SIZE) {        \
        create_test_list(THE_SIZE);                             \
                                                                \
        char *list_rep = list_to_string(p_test_list);           \
                                                                \
        printf("testing list %s\n", list_rep);                  \
                                                                \
        free(list_rep);                                         \
                                                                \
        TEST_ASSERT_EQUAL_INT(THE_SIZE,                         \
                              size(p_test_list));               \
    };

TEST_DOUBLE_LINKED_LIST_INT_SIZE(0);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(1);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(2);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(3);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(4);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(5);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(6);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(7);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(8);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(9);
TEST_DOUBLE_LINKED_LIST_INT_SIZE(10);

TEST_GROUP_RUNNER(size) {
    printf("\n---------------------\n");
    printf("Testing size function\n\n");

    RUN_TEST_CASE(size, double_linked_list_int_size_0);
    RUN_TEST_CASE(size, double_linked_list_int_size_1);
    RUN_TEST_CASE(size, double_linked_list_int_size_2);
    RUN_TEST_CASE(size, double_linked_list_int_size_3);
    RUN_TEST_CASE(size, double_linked_list_int_size_4);
    RUN_TEST_CASE(size, double_linked_list_int_size_5);
    RUN_TEST_CASE(size, double_linked_list_int_size_6);
    RUN_TEST_CASE(size, double_linked_list_int_size_7);
    RUN_TEST_CASE(size, double_linked_list_int_size_8);
    RUN_TEST_CASE(size, double_linked_list_int_size_9);
    RUN_TEST_CASE(size, double_linked_list_int_size_10);
};

/* Tests for is_empty of list */

TEST_GROUP(is_empty);

TEST_SETUP(is_empty) {
    nil(&p_test_list);
};

TEST_TEAR_DOWN(is_empty) {
    deallocate_list(p_test_list);
};

// A macro to test is_empty on linked list
#define TEST_LINKED_LIST_INT_IS_EMPTY(THE_LENGTH)               \
    TEST(is_empty, linked_list_int_is_empty_##THE_LENGTH) {     \
        create_test_list(THE_LENGTH);                           \
                                                                \
        char *list_rep = list_to_string(p_test_list);           \
                                                                \
        printf("testing list %s\n", list_rep);                  \
                                                                \
        free(list_rep);                                         \
                                                                \
        if (THE_LENGTH == 0) {                                  \
            TEST_ASSERT_TRUE(is_empty(p_test_list));            \
        } else {                                                \
            TEST_ASSERT_FALSE(is_empty(p_test_list));           \
        }                                                       \
    };

TEST_LINKED_LIST_INT_IS_EMPTY(0);
TEST_LINKED_LIST_INT_IS_EMPTY(1);
TEST_LINKED_LIST_INT_IS_EMPTY(2);
TEST_LINKED_LIST_INT_IS_EMPTY(3);
TEST_LINKED_LIST_INT_IS_EMPTY(4);
TEST_LINKED_LIST_INT_IS_EMPTY(5);
TEST_LINKED_LIST_INT_IS_EMPTY(6);
TEST_LINKED_LIST_INT_IS_EMPTY(7);
TEST_LINKED_LIST_INT_IS_EMPTY(8);
TEST_LINKED_LIST_INT_IS_EMPTY(9);
TEST_LINKED_LIST_INT_IS_EMPTY(10);

TEST_GROUP_RUNNER(is_empty) {
    printf("\n-------------------------\n");
    printf("Testing is_empty function\n\n");

    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_0);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_1);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_2);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_3);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_4);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_5);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_6);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_7);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_8);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_9);
    RUN_TEST_CASE(is_empty, linked_list_int_is_empty_10);
};

/* Tests for function for getting value in list */

TEST_GROUP(get_element);

TEST_SETUP(get_element) {
    nil(&p_test_list);
};

TEST_TEAR_DOWN(get_element) {
    deallocate_list(p_test_list);
};

// A macro to test getting element in linked list
#define TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(THE_SIZE, THE_POS)      \
    TEST(get_element, double_linked_list_int_##THE_SIZE##_get_element_##THE_POS) { \
        create_test_list(THE_SIZE);                                     \
                                                                        \
        char *list_before = list_to_string(p_test_list);                \
                                                                        \
        printf("testing get_element(%s, %d)\n",                         \
               list_before,                                             \
               THE_POS);                                                \
                                                                        \
        free(list_before);                                              \
                                                                        \
        char *msg_element;                                              \
                                                                        \
        asprintf(&msg_element,                                          \
                 "the element should be %d!",                           \
                 THE_SIZE - 1 - THE_POS);                               \
                                                                        \
                                                                        \
        TEST_ASSERT_EQUAL_INT_MESSAGE(THE_SIZE - 1 - THE_POS,           \
                                      get_element(p_test_list, THE_POS), \
                                      msg_element);                     \
                                                                        \
        free(msg_element);                                              \
                                                                        \
        char *list_after = list_to_string(p_test_list);                 \
        char *msg;                                                      \
        char *msg_length;                                               \
                                                                        \
        asprintf(&msg,                                                  \
                 "Your list is %s",                                     \
                 list_after);                                           \
                                                                        \
        free(list_after);                                               \
                                                                        \
        asprintf(&msg_length,                                           \
                 "list length should be %d!\n",                         \
                 THE_SIZE - 1);                                         \
                                                                        \
        cell_int *p_cell = p_test_list->first;                          \
                                                                        \
        TEST_ASSERT_EQUAL_INT_MESSAGE(THE_SIZE,                         \
                                      size(p_test_list),                \
                                      msg_length);                      \
                                                                        \
        free(msg_length);                                               \
                                                                        \
        test_list_content(&p_cell, 0, THE_SIZE, THE_SIZE - 1, msg);     \
                                                                        \
        free(msg);                                                      \
    };

TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(1, 0);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(2, 0);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(2, 1);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(3, 0);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(3, 1);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(3, 2);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(4, 0);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(4, 1);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(4, 2);
TEST_DOUBLE_LINKED_LIST_INT_GET_ELEMENT(4, 3);

TEST_GROUP_RUNNER(get_element) {
    printf("\n----------------------------\n");
    printf("Testing get_element function\n\n");

    RUN_TEST_CASE(get_element, double_linked_list_int_1_get_element_0);
    RUN_TEST_CASE(get_element, double_linked_list_int_2_get_element_0);
    RUN_TEST_CASE(get_element, double_linked_list_int_2_get_element_1);
    RUN_TEST_CASE(get_element, double_linked_list_int_3_get_element_0);
    RUN_TEST_CASE(get_element, double_linked_list_int_3_get_element_1);
    RUN_TEST_CASE(get_element, double_linked_list_int_3_get_element_2);
    RUN_TEST_CASE(get_element, double_linked_list_int_4_get_element_0);
    RUN_TEST_CASE(get_element, double_linked_list_int_4_get_element_1);
    RUN_TEST_CASE(get_element, double_linked_list_int_4_get_element_2);
    RUN_TEST_CASE(get_element, double_linked_list_int_4_get_element_3);
};

/* Tests for function for inserting element in list */

TEST_GROUP(insert_element);

TEST_SETUP(insert_element) {
    nil(&p_test_list);
};

TEST_TEAR_DOWN(insert_element) {
    deallocate_list(p_test_list);
};

// A macro to test insertion of element in linked list
#define TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(THE_SIZE, THE_POS)   \
    TEST(insert_element, double_linked_list_int_##THE_SIZE##_insert_element_##THE_POS) { \
        create_test_list(THE_SIZE);                                     \
                                                                        \
        char *list_before = list_to_string(p_test_list);                \
                                                                        \
        printf("testing insert_element(%s, %d, 255)\n",                 \
               list_before,                                             \
               THE_POS);                                                \
                                                                        \
        free(list_before);                                              \
                                                                        \
        insert_element(p_test_list, THE_POS, 255);                      \
                                                                        \
        char *list_after = list_to_string(p_test_list);                 \
        char *msg;                                                      \
        char *msg_length;                                               \
                                                                        \
        asprintf(&msg,                                                  \
                 "Your list is %s",                                     \
                 list_after);                                           \
                                                                        \
        free(list_after);                                               \
                                                                        \
        asprintf(&msg_length,                                           \
                 "list length should be %d!\n",                         \
                 THE_SIZE + 1);                                         \
                                                                        \
                 cell_int *p_cell = p_test_list->first;                 \
                                                                        \
                 TEST_ASSERT_EQUAL_INT_MESSAGE(THE_SIZE + 1,            \
                                               size(p_test_list),       \
                                               msg_length);             \
                                                                        \
                 free(msg_length);                                      \
                                                                        \
                 test_list_content(&p_cell, 0, THE_POS, THE_SIZE - 1, msg); \
                                                                        \
                 TEST_ASSERT_EQUAL_INT(255, p_cell->value);             \
                                                                        \
                 p_cell = p_cell->next;                                 \
                                                                        \
                 test_list_content(&p_cell, THE_POS, THE_SIZE,          \
                                   THE_SIZE - 1, msg);                  \
                                                                        \
                 free(msg);                                             \
    };

TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(0, 0);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(1, 0);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(1, 1);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(2, 0);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(2, 1);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(2, 2);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(3, 0);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(3, 1);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(3, 2);
TEST_DOUBLE_LINKED_LIST_INT_INSERT_ELEMENT(3, 3);

TEST_GROUP_RUNNER(insert_element) {
    printf("\n-------------------------------\n");
    printf("Testing insert_element function\n\n");

    RUN_TEST_CASE(insert_element, double_linked_list_int_0_insert_element_0);
    RUN_TEST_CASE(insert_element, double_linked_list_int_1_insert_element_0);
    RUN_TEST_CASE(insert_element, double_linked_list_int_1_insert_element_1);
    RUN_TEST_CASE(insert_element, double_linked_list_int_2_insert_element_0);
    RUN_TEST_CASE(insert_element, double_linked_list_int_2_insert_element_1);
    RUN_TEST_CASE(insert_element, double_linked_list_int_2_insert_element_2);
    RUN_TEST_CASE(insert_element, double_linked_list_int_3_insert_element_0);
    RUN_TEST_CASE(insert_element, double_linked_list_int_3_insert_element_1);
    RUN_TEST_CASE(insert_element, double_linked_list_int_3_insert_element_2);
    RUN_TEST_CASE(insert_element, double_linked_list_int_3_insert_element_3);
};

/* Tests for function for removing element in list */

TEST_GROUP(remove_element);

TEST_SETUP(remove_element) {
    nil(&p_test_list);
};

TEST_TEAR_DOWN(remove_element) {
    deallocate_list(p_test_list);
};

// A macro to test removing element in linked list
#define TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(THE_SIZE, THE_POS)   \
    TEST(remove_element, double_linked_list_int_##THE_SIZE##_remove_element_##THE_POS) { \
        create_test_list(THE_SIZE);                                     \
                                                                        \
        char *list_before = list_to_string(p_test_list);                \
                                                                        \
        printf("testing remove_element(%s, %d)\n",                      \
               list_before,                                             \
               THE_POS);                                                \
                                                                        \
        free(list_before);                                              \
                                                                        \
        remove_element(p_test_list, THE_POS);                           \
                                                                        \
        char *list_after = list_to_string(p_test_list);                 \
        char *msg;                                                      \
        char *msg_length;                                               \
                                                                        \
        asprintf(&msg,                                                  \
                 "Your list is %s",                                     \
                 list_after);                                           \
                                                                        \
        free(list_after);                                               \
                                                                        \
        asprintf(&msg_length,                                           \
                 "list length should be %d!\n",                         \
                 THE_SIZE - 1);                                         \
                                                                        \
        cell_int *p_cell = p_test_list->first;                          \
                                                                        \
        TEST_ASSERT_EQUAL_INT_MESSAGE(THE_SIZE - 1,                     \
                                      size(p_test_list),                \
                                      msg_length);                      \
                                                                        \
        free(msg_length);                                               \
                                                                        \
        test_list_content(&p_cell, 0, THE_POS, THE_SIZE - 1, msg);      \
                                                                        \
        test_list_content(&p_cell, THE_POS, THE_SIZE - 1,               \
                          THE_SIZE - 2, msg);                           \
                                                                        \
        free(msg);                                                      \
    };

TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(1, 0);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(2, 0);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(2, 1);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(3, 0);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(3, 1);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(3, 2);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(4, 0);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(4, 1);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(4, 2);
TEST_DOUBLE_LINKED_LIST_INT_REMOVE_ELEMENT(4, 3);

TEST_GROUP_RUNNER(remove_element) {
    printf("\n-------------------------------\n");
    printf("Testing remove_element function\n\n");

    RUN_TEST_CASE(remove_element, double_linked_list_int_1_remove_element_0);
    RUN_TEST_CASE(remove_element, double_linked_list_int_2_remove_element_0);
    RUN_TEST_CASE(remove_element, double_linked_list_int_2_remove_element_1);
    RUN_TEST_CASE(remove_element, double_linked_list_int_3_remove_element_0);
    RUN_TEST_CASE(remove_element, double_linked_list_int_3_remove_element_1);
    RUN_TEST_CASE(remove_element, double_linked_list_int_3_remove_element_2);
    RUN_TEST_CASE(remove_element, double_linked_list_int_4_remove_element_0);
    RUN_TEST_CASE(remove_element, double_linked_list_int_4_remove_element_1);
    RUN_TEST_CASE(remove_element, double_linked_list_int_4_remove_element_2);
    RUN_TEST_CASE(remove_element, double_linked_list_int_4_remove_element_3);
};

/* run functions */

static void runNilTests(void) {
    RUN_TEST_GROUP(nil);
}

static void runConsTests(void) {
    RUN_TEST_GROUP(cons);
}

static void runSnocTests(void) {
    RUN_TEST_GROUP(snoc);
}

static void runSizeTests(void) {
    RUN_TEST_GROUP(size);
}

static void runIsEmptyTests(void) {
    RUN_TEST_GROUP(is_empty);
}

static void runGetElementTests(void) {
    RUN_TEST_GROUP(get_element);
}

static void runInsertElementTests(void) {
    RUN_TEST_GROUP(insert_element);
}

static void runRemoveElementTests(void) {
    RUN_TEST_GROUP(remove_element);
}

static void runAllTests(void) {
    RUN_TEST_GROUP(nil);
    RUN_TEST_GROUP(cons);
    RUN_TEST_GROUP(snoc);
    RUN_TEST_GROUP(size);
    RUN_TEST_GROUP(is_empty);
    RUN_TEST_GROUP(get_element);
    RUN_TEST_GROUP(insert_element);
    RUN_TEST_GROUP(remove_element);
}

/* main */

int main(int argc, char * argv[]) {
    int  c;
    bool has_passed_test = false;

    while (1) {
        static struct option long_options[] = {
            {"nil",            no_argument, 0, 'N'},
            {"cons",           no_argument, 0, 'C'},
            {"snoc",           no_argument, 0, 'S'},
            {"size",           no_argument, 0, 'L'},
            {"is_empty",       no_argument, 0, 'E'},
            {"get_element",    no_argument, 0, 'G'},
            {"insert_element", no_argument, 0, 'I'},
            {"remove_element", no_argument, 0, 'R'},
            {"all",            no_argument, 0, 'A'},
            {0, 0, 0, 0}
        };

        int option_index = 0;

        c = getopt_long_only(argc, argv, "NCLEGIRA",
                             long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c) {
        case 'N':
            printf("starting tests for nil\n");
            UnityMain(argc, (const char **) argv, runNilTests);
            has_passed_test = true;
            break;

        case 'C':
            printf("starting tests for cons\n");
            UnityMain(argc, (const char **) argv, runConsTests);
            has_passed_test = true;
            break;

        case 'S':
            printf("starting tests for snoc\n");
            UnityMain(argc, (const char **) argv, runSnocTests);
            has_passed_test = true;
            break;

        case 'L':
            printf("starting tests for size\n");
            UnityMain(argc, (const char **) argv, runSizeTests);
            has_passed_test = true;
            break;

        case 'E':
            printf("starting tests for is_empty\n");
            UnityMain(argc, (const char **) argv, runIsEmptyTests);
            has_passed_test = true;
            break;

        case 'G':
            printf("starting tests for get_element\n");
            UnityMain(argc, (const char **) argv, runGetElementTests);
            has_passed_test = true;
            break;

        case 'I':
            printf("starting tests for insert_element\n");
            UnityMain(argc, (const char **) argv, runInsertElementTests);
            has_passed_test = true;
            break;

        case 'R':
            printf("starting tests for remove_element\n");
            UnityMain(argc, (const char **) argv, runRemoveElementTests);
            has_passed_test = true;
            break;

        case 'A':
            printf("starting all tests\n");
            UnityMain(argc, (const char **) argv, runAllTests);
            has_passed_test = true;
            break;

        default:
            break;
        }
    }

    if (! has_passed_test) {
        error(1, 0, "\nusage: double_linked_list_int_tests [--nil|--cons|--snoc|--size|--is_empty|--get_element|"
              "--insert_element|--remove_element|--all]\n"
              "    --all starts all tests\n"
              "    other options only start tests on the specified function\n"
              "    options can also be chosen by their first letter: -C, -L etc.\n"
            );
    }
}
