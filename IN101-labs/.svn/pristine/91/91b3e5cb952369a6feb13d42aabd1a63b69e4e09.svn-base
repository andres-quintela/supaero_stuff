GCC = gcc
CFLAGS = -g -std=c99 -Wall -I ./include
LDFLAGS = -lm

.PHONY: clean syntax-check run-stack run-queue
.DEFAULT_GOAL := syntax-check

syntax-check: src/linked_list_int.c src/stack_int.c  \
	src/app-stack-int.c
	$(GCC) $(CFLAGS) -c $^

app-stack-int: src/linked_list_int.c src/stack_int.c src/app-stack-int.c
	$(GCC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run-stack: app-stack-int
	./app-stack-int

clean:
	rm -f app-stack-int *.o
