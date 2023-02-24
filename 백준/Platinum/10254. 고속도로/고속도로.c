#include<stdio.h>
#include<stdlib.h>

#define ll long long

typedef struct Vector {
    ll x, y;
}Vector;

Vector set[200000];

Vector convexHull[200000];
int temp;

Vector p;

ll dist(const Vector* a, const Vector* b) {
    return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

int ccw(const Vector* a, const Vector* b, const Vector* c) {
    ll direct = (b->x - a->x) * (c->y - a->y) - (c->x - a->x) * (b->y - a->y);

    return direct < 0 ? -1 : direct > 0;
}

int cccw(const Vector* a, const Vector* b, const Vector* c, const Vector* d) {
    ll direct = (a->x - b->x) * (d->y - c->y) - (d->x - c->x) * (a->y - b->y);

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
    temp = 2;

    for(int i = 2; i < N; i++) {
        do {
            int direct = ccw(&convexHull[temp - 2], &convexHull[temp - 1], &set[i]);

            if (direct > 0) break;

        } while(--temp > 1);

        convexHull[temp++] = set[i];
    }
}

void rotatingCalipers(int N) {
    bulidConvexHull(N);

    int C = 1;

    ll maxDistance = 0, measure;
    int p1, p2;
    for(int A = 0; A < temp; A++) {
        while((C + 1) != A && cccw(&convexHull[A], &convexHull[(A + 1) % temp], &convexHull[C % temp], &convexHull[(C + 1) % temp]) < 0) {
            
            measure = dist(&convexHull[A], &convexHull[C % temp]);
            
            if (maxDistance < measure) {
                maxDistance = measure;
                p1 = A;
                p2 = C;
            }

            C++;
        }
        
        measure = dist(&convexHull[A], &convexHull[C % temp]);
        
        if (maxDistance < measure) {
            maxDistance = measure;
            p1 = A;
            p2 = C;
        }
    }

    printf("%lld %lld %lld %lld\n", convexHull[p1].x, convexHull[p1].y, convexHull[p2].x, convexHull[p2].y);
}

int main() {
    int T, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            scanf("%lld %lld", &set[i].x, &set[i].y);
        }

        rotatingCalipers(N);
    }
}