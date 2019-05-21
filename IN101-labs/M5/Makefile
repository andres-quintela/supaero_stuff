CC = gcc
CFLAGS = -std=c99


syntax_check:
	$(CC) -c linked_list_int.c

compile: linked_list_int.c
	$(CC) $(CFLAGS) -o linked_list_int linked_list_int.c

clean:
	rm -f linked_list_int

run: linked_list_int
	./linked_list_int
