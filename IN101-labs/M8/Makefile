CC = gcc
CFLAGS = -std=c99 -Wall -g -I ./include

.PHONY: doc clean indent app valgrind
.DEFAULT_GOAL := run

doc: conf/doxygen.conf
	doxygen conf/doxygen.conf
	firefox doc/html/index.html

%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

syntax-check: graph_char.o

app-graph-char: graph_char.o app-graph-char.o
	$(CC) $(CFLAGS) -o $@ $^

run: app-graph-char
	./app-graph-char

valgrind: app-graph-char
	valgrind --leak-check=full ./app-graph-char

clean:
	- rm -f *.o app-graph-char
