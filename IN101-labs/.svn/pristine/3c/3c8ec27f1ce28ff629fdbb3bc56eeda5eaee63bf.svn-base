GCC = gcc
CFLAGS = -g -std=c99 -Wall -I ./include

.PHONY: clean syntax-check run-stack run-queue
.DEFAULT_GOAL := syntax-check

syntax-check: src/linked_list_int.c src/stack_int.c src/queue_int.c \
	src/app-stack-int.c src/app-queue-int.c
	$(GCC) $(CFLAGS) -c $^

app-stack-int: src/linked_list_int.c src/stack_int.c src/app-stack-int.c
	$(GCC) $(CFLAGS) -o $@ $^

run-stack: app-stack-int
	./app-stack-int

app-queue-int: src/linked_list_int.c src/queue_int.c src/app-queue-int.c
	$(GCC) $(CFLAGS) -o $@ $^

run-queue: app-queue-int
	./app-queue-int

clean:
	rm -f app-stack-int app-queue-int *.o
