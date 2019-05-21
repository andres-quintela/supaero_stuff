#include <stdbool.h>
#include <stdio.h>

double compute_pi(int n) {
    double  sum        = 4.0;
    bool    minus_flag = true;

    for (int i = 1; i <= n; i++) {
        sum += 4.0 *
            (minus_flag ? -1.0 : 1.0) /
            (2.0 * i + 1);
        minus_flag = !minus_flag;
    }

    return sum;
}

int main(void) {
    printf("PI value for n=500: %f\n", compute_pi(500));
}
