#include<stdio.h>
#include<stdlib.h>

#define max(a, b) ((a) > (b) ? a : b)

typedef struct Vector {
    int x, y;
}Vector;

Vector set[100000];

Vector convexHull[100000];
int temp = 2;

Vector p;

int dist(const Vector* a, const Vector* b) {
    return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

int ccw(const Vector* a, const Vector* b, const Vector* c) {
    int direct = (b->x - a->x) * (c->y - a->y) - (c->x - a->x) * (b->y - a->y);

    return direct < 0 ? -1 : direct > 0;
}

int cccw(const Vector* a, const Vector* b, const Vector* c, const Vector* d) {
    int direct = (a->x - b->x) * (d->y - c->y) - (d->x - c->x) * (a->y - b->y);

    return direct < 0 ? -1 : direct > 0;
}


int order(const void* a, const void* b) {
    Vector* A = (Vector*)a;
    Vector* B = (Vector*)b;

    if (A->y != B->y) return A->y > B->y ? 1 : -1;
    return A->x > B->x ? 1 : -1;
}

int compare(const void* a, const void* b) {
    Vector* A = (Vector*)a;
    Vector* B = (Vector*)b;

    int direct = ccw(&p, A, B);

    if (direct == 0) return dist(&p, A) > dist(&p, B) ? 1 : -1;

    return -direct;
}

void bulidConvexHull(int N) {
    qsort(set, N, sizeof(Vector), order);

    p = set[0];

    qsort(set, N, sizeof(Vector), compare);

    convexHull[0] = set[0];
    convexHull[1] = set[1];
    for(int i = 2; i < N; i++) {
        do {
            int direct = ccw(&convexHull[temp - 2], &convexHull[temp - 1], &set[i]);

            if (direct > 0) break;

        } while(--temp > 1);

        convexHull[temp++] = set[i];
    }
}

int rotatingCalipers(int N) {
    bulidConvexHull(N);

    int C = 1;

    int maxDistance = 0, measure;
    for(int A = 0; A < temp; A++) {
        while((C + 1) != A && cccw(&convexHull[A], &convexHull[(A + 1) % temp], &convexHull[C % temp], &convexHull[(C + 1) % temp]) < 0) {
            
            measure = dist(&convexHull[A], &convexHull[C % temp]);
            maxDistance = max(maxDistance, measure);

            C++;
        }
        
        measure = dist(&convexHull[A], &convexHull[C % temp]);
        maxDistance = max(maxDistance, measure);
    }

    return maxDistance;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &set[i].x, &set[i].y);
    }

    printf("%d", rotatingCalipers(N));
}