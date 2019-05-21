#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double pi         = 0.0;
    bool   minus_flag = false;
    int    n          = 1;

    printf("n value? ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        // beware, do not use 1 and 2 constants !
        pi += (minus_flag ? -1.0 : 1.0) * 4.0 / (2.0 * i + 1);
        minus_flag = ! minus_flag;
    }

    printf("PI = %f with n = %d\n", pi, n);

    return 0;
}
