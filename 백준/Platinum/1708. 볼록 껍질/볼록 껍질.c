#include<stdio.h>
#include<stdlib.h>

#define ll long long

typedef struct Point {
    ll x, y;
}Point;

Point input[100000];
Point p;

Point stack[100000];
int pre = 2;

ll dist(Point* a, Point* b) {
    return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

int ccw(Point* one, Point* two, Point* three) {
    ll direct = (two->x - one->x) * (three->y - one->y) - (three->x - one->x) * (two->y  - one->y);
    return direct < 0 ? -1 : (direct > 0);
}

int order(const void* a, const void* b) {
    Point* num1 = (Point*)a;
    Point* num2 = (Point*)b;

    if(num1->y != num2->y) return num1->y > num2->y;
    return num1->x > num2->x ? 1 : -1;
}

int compare(const void* a, const void* b) {
    Point* num1 = (Point*)a;
    Point* num2 = (Point*)b;

    int direct = ccw(&p, num1, num2);

    if(direct == 0) return dist(&p, num1) > dist(&p, num2) ? 1 : -1;

    return direct < 0 ? 1 : -1;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld %lld", &input[i].x, &input[i].y);
    }

    qsort(input, N, sizeof(Point), order);

    p = input[0];

    qsort(input, N, sizeof(Point), compare);

    stack[0] = input[0];
    stack[1] = input[1];
    for(int i = 2; i < N; i++) {
        do {
            int direct = ccw(&stack[pre - 2], &stack[pre - 1], &input[i]);

            if(direct > 0) break;

            pre--;
        } while(pre > 1);

        stack[pre++] = input[i];
    }

    printf("%d", pre);
}