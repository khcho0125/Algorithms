#include<stdio.h>
#include<stdlib.h>

typedef struct Point {
    int x, y, n;
}Point;

Point p;
Point set[2000];

int dist(Point* A, Point* B) {
    return (A->x - B->x) * (A->x - B->x) + (A->y - B->y) * (A->y - B->y);
}

int ccw(Point* A, Point* B, Point* C) {
    return (B->x - A->x) * (C->y - A->y) - (C->x - A->x) * (B->y - A->y);
}

int order(const void* A, const void* B) {
    Point* p1 = (Point*)A;
    Point* p2 = (Point*)B;

    if(p1->y != p2->y) return p1->y > p2->y;
    return p1->x > p2->x;
}

int compare(const void* A, const void* B) {
    Point* p1 = (Point*)A;
    Point* p2 = (Point*)B;

    int direction = ccw(&p, p1, p2);
    
    if(direction == 0) {
        return dist(&p, p1) > dist(&p, p2);
    }

    return direction < 0 ? 1 : -1;
}

void execute() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &set[i].x, &set[i].y);
        set[i].n = i;
    }
    
    qsort(set, N, sizeof(Point), order);
    p = set[0];

    qsort(set, N, sizeof(Point), compare);

    int reverse = N - 1;
    while (ccw(&p, &set[reverse], &set[reverse - 1]) == 0) reverse--;

    for(int i = 0; i < reverse; i++) {
        printf("%d ", set[i].n);
    }

    for(int i = N - 1; i >= reverse; i--) {
        printf("%d ", set[i].n);
    }

    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) execute();
}