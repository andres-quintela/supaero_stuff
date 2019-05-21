#include <stdio.h>

typedef struct point point;

typedef struct point {
    double x;
    double y;
} point;

void print_point(point p) {
    printf("(%f, %f)", p.x, p.y);
}

int point_cmp(point p1, point p2) {
    if (p1.x < p2.x) {
        return -1;
    } else if (p1.x > p2.x) {
        return 1;
    } else if (p1.y < p2.y) {
        return -1;
    } else if (p1.y > p2.y) {
        return 1;
    } else {
        return 0;
    }
}

void print_cmp(point p1, point p2) {
    printf("(%f, %f) < (%f, %f)? %s\n",
           p1.x, p1.y, p2.x, p2.y,
           point_cmp(p1, p2) < 0 ? "true" : "false");
}

void point_trans(point *p, point vec) {
    p->x = p->x + vec.x;
    p->y = p->y + vec.y;
}

int main(void) {
    point origin;
    origin.x = 0.0;
    origin.y = 0.0;

    point p1;
    p1.x = 1.0;
    p1.y = 0.0;

    point p2;
    p2.x = 1.0;
    p2.y = 1.0;

    print_cmp(origin, p1);
    print_cmp(p1, origin);

    print_cmp(p1, p2);
    print_cmp(p2, p1);

    point vec;
    vec.x = -2.0;
    vec.y = 3.0;

    point_trans(&origin, vec);

    printf("translating origin with (-2, 3): (%f, %f)\n",
           origin.x, origin.y);
}
