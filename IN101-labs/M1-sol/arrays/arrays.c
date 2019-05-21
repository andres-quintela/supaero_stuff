#include <stdio.h>

int main(void) {

    int my_array[15];
    int my_snd_array = {1, 2, 3};

    my_array[0] = 12;
    my_array[2] = 13;

    printf("%d", my_array[0] * 2);
    printf("%d", my_array[1]);
    printf("%d", my_array[15]);

    return 0;
}
