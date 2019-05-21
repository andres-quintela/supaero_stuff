CC = gcc
CFLAGS = -g -std=c99 -Wall
FILE = minmax_list
OBJ_FILES = $(FILE).o linked_list_int.o test_utils.o

.PHONY: clean all doc

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

doc:
	doxygen conf/doxygen.conf
	firefox doc/html/index.html &

syntax-check: $(FILE).o

create: $(OBJ_FILES) test-create.o
	$(CC) $(CFLAGS) -o test-$@ $^
	./test-create

is-empty: $(OBJ_FILES) test-is-empty.o
	$(CC) $(CFLAGS) -o test-$@ $^
	./test-is-empty

get-max: $(OBJ_FILES) test-get-max.o
	$(CC) $(CFLAGS) -o test-$@ $^
	./test-get-max

get-min: $(OBJ_FILES) test-get-min.o
	$(CC) $(CFLAGS) -o test-$@ $^
	./test-get-min

add-first: $(OBJ_FILES) test-add-first.o
	$(CC) $(CFLAGS) -o test-$@ $^
	./test-add-first

append: $(OBJ_FILES) test-append.o
	$(CC) $(CFLAGS) -o test-$@ $^
	./test-append

reverse: $(OBJ_FILES) test-reverse.o
	$(CC) $(CFLAGS) -o test-$@ $^
	./test-reverse

clean:
	rm -f *.o test-create test-is-empty test-get-max test-get-min test-add-first test-append test-reverse

all: create is-empty get-max get-min add-first  append reverse
