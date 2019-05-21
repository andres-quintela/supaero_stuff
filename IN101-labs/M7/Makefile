UNITYLIB = $(dir $(shell locate --regexp "lib/libunity.so$$"))
UNITYINC = $(dir $(shell locate --regexp "include/unity.h$$"))
CC = gcc
CFLAGS = -std=c99 -Wall -g -I ./include -I $(UNITYINC)
LDFLAGS = -L $(UNITYLIB) -l unity

.PHONY: init clean syntax-check syntax-check-app simple-app tests \
	all nil is_empty size height value left_child right_child retrieve insert delete
.DEFAULT_GOAL := all

doc: conf/doxygen.conf
	doxygen $<
	firefox doc/html/index.html

syntax-check: src/binary_search_tree_int.c src/app-bst-int.c
	$(CC) $(CFLAGS) -c $^

app-bst-int: src/binary_search_tree_int.c src/app-bst-int.c
	$(CC) $(CFLAGS) -o $@ $^

run: app-bst-int
	./app-bst-int

tests:	tests/binary_search_tree_int_tests.c src/binary_search_tree_int.c
	$(CC) $(CFLAGS) -o tests-bst $^ $(LDFLAGS)

clean:
	rm -Rf *.o ./app-bst-int ./tests-bst

all nil is_empty size height value left_child right_child retrieve insert delete: tests
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$(UNITYLIB) ./tests-bst --$@
