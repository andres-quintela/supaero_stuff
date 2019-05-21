#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool is_leap_year(int year) {
    return (year % 400 == 0) ||
        ((year % 4 == 0) && (year % 100 != 0));
}

void print_is_leap_year(int year) {
    if (is_leap_year(year)) {
        printf("The year %d is a leap year.\n", year);
    } else {
        printf("The year %d is not a leap year.\n", year);
    }
}

int main(void) {
    int size    = 4;
    int years[] = { 1997, 1998, 2000, 2002 };
    int leap[]  = { false, false, true, false};

    for (int i = 0; i < size; i++) {
        assert (is_leap_year(years[i]) == leap[i]);
    }

    // test print
    print_is_leap_year(1987);
    print_is_leap_year(2000);
    print_is_leap_year(2002);
    print_is_leap_year(2016);

    return 0;
}
