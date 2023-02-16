#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a, b) ((a) > (b) ? a : b)
#define min(a, b) ((a) < (b) ? a : b)

typedef struct Point {
    int x, y;
}Point;

Point set[100];

int temp = 0;
Point stack[100];

Point p;

int dist(Point* A, Point* B) {
    return (A->x - B->x) * (A->x - B->x) + (A->y - B->y) * (A->y - B->y);
}

int ccw(Point* A, Point* B, Point* C) {
    return (B->x - A->x) * (C->y - A->y) - (C->x - A->x) * (B->y - A->y);
}

int compare(const void* A, const void* B) {
    Point* pA = (Point*)A;
    Point* pB = (Point*)B;

    int direction = ccw(&p, pA, pB);

    if(direction == 0) {
        return dist(&p, pA) > dist(&p, pB);
    }

    return direction < 0 ? 1 : -1;
}

int order(const void* A, const void* B) {
    Point* pA = (Point*)A;
    Point* pB = (Point*)B;

    if(pA->y != pB->y) return pA->y > pB->y;
    return pA->x > pB->x;
}

void execute(int N, int T) {

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &set[i].x, &set[i].y);
    }
    
    qsort(set, N, sizeof(Point), order);
    
    p = set[0];

    qsort(set, N, sizeof(Point), compare);

    stack[temp++] = set[0];
    stack[temp++] = set[1];
    for(int i = 2; i < N; i++) {
        do {
            int direction = ccw(&stack[temp - 2], &stack[temp - 1], &set[i]);

            if (direction > 0) break;
            
            temp--;
        } while(temp > 1);

        stack[temp++] = set[i];
    }

    double ans = 1e18, d, h, maximum;
    for(int i = 0; i < temp; i++) {
        Point* A = &stack[i];
        Point* B = &stack[(i + 1) % temp];
        d = sqrt((double)dist(A, B));
        maximum = 0;

        for(int k = 0; k < temp; k++) {
            h = fabs((double)ccw(A, B, &stack[k]));
            maximum = max(maximum, h / d);
        }

        ans = min(ans, maximum);
    }

    printf("Case %d: %.2lf\n", T, ceil(ans * 100) / 100);
}

int main() {
    int N, T;
    scanf("%d", &N);
    for(T = 1; N; T++, temp = 0) {
        execute(N, T);
        scanf("%d", &N);
    }
}