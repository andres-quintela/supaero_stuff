UNITYLIB = $(dir $(shell locate --regexp "lib/libunity.so$$"))
UNITYINC = $(dir $(shell locate --regexp "include/unity.h$$"))
GCC = gcc
CFLAGS = -g -std=c99 -Wall -I $(UNITYINC) -I ./include
LDFLAGS = -L $(UNITYLIB) -l unity

.PHONY: clean all nil cons length get insert remove syntax_check doc
.DEFAULT_GOAL := all

doc: conf/doxygen.conf
	doxygen conf/doxygen.conf

syntax-check: src/double_linked_list_int.c
	$(GCC) $(CFLAGS) -c $<

app-double-linked-list-int: src/app-double-linked-list-int.c src/double_linked_list_int.c
	$(GCC) $(CFLAGS) -o $@ $^

run: src/app-double-linked-list-int
	./app-double-linked-list-int

tests-double-linked-list:	tests/double_linked_list_int_tests.c src/double_linked_list_int.c
	$(GCC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f tests-double-linked-list app-double-linked-list *.o

all nil cons snoc length get_element insert_element remove_element:	tests
	./tests-double-linked-list --$@
