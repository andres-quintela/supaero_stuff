#include <stdio.h>

typedef struct time time;

struct time {
    int minutes;
    int seconds;
};

void add_times(time t1, time t2, time *res) {
    res->seconds = (t1.seconds + t2.seconds) % 60;
    res->minutes = t1.minutes + t2.minutes +
        (t1.seconds + t2.seconds) / 60;
}

int main(void) {
    time my_time;

    my_time.minutes = 20;
    my_time.seconds = 15;

    time my_time_2;

    my_time_2.minutes = 10;
    my_time_2.seconds = 50;

    time my_time_res;

    add_times(my_time, my_time_2, &my_time_res);

    printf("minutes: %d\nseconds: %d\n",
           my_time_res.minutes,
           my_time_res.seconds);

    return 0;
}
