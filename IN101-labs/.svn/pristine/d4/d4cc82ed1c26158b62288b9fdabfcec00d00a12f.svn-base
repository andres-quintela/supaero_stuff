#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc);

    printf("now, the strings:\n");

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    printf("now, the strings (but manipulated as pointers):\n");

    for (int i = 0; i < argc; i++) {
        printf("%s\n", *(argv + i));
    }

    return 0;
}
