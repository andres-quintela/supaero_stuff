#include <stdio.h>

int rebuild_int(unsigned char *p_c) {
    int value = 0;

    for (int i = 3; i >= 0; i++) {
        value = value * 256 + *(p_c + i);
    }

    return value;
}

int main() {

    int i = 123456789;

    printf("i = %d\n", rebuild_int((unsigned char *) &i));

    return 0;
}
