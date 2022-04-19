#include<stdio.h>
#include<stdlib.h>

typedef struct XY {
    int x;
    int y;
}xy;

int compare(const void* a, const void* b) {
    xy *n, *m;
    n = (xy*)a;
    m=(xy*)b;

    if(n->y > m->y) {
        return 1;
    }
    else if(n->y < m->y) {
        return -1;
    }
    else if(n->y == m->y) {
        if(n->x > m->x) {
            return 1;
        } else {
            return -1;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    xy* arr = (xy*)malloc(sizeof(xy) * N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    qsort(arr, N, sizeof(arr[0]), compare);

    for(int i = 0; i < N; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}