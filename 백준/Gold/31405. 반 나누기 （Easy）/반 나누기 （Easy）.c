#include<stdio.h>

#define N_MAX 200000
#define ll long long

#define abs(x) ((x) > 0 ? x : -(x))

typedef struct Point {
    ll x, y;
}P;

P shape[N_MAX];
double sum[N_MAX];

double triangle(P *a, P *b, P *c) {
    return abs((b->x - a->x) * (c->y - a->y) - (c->x - a->x) * (b->y - a->y)) / 2.;
}

int binarySearch(int N) {
    int low = 0, high = N - 1;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(sum[mid] < sum[N - 2] / 2) low = mid;
        else high = mid;
    }
    return high;
}

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%lld %lld", &shape[i].x, &shape[i].y);
    }

    for(int i = 1; i < N - 1; i++) {
        sum[i] = triangle(&shape[0], &shape[i], &shape[i + 1]) + sum[i - 1];
    }

    int middle = binarySearch(N);
    double diff = (sum[N - 2] - sum[middle - 1] * 2) / 2;
    double result = diff / triangle(&shape[0], &shape[middle], &shape[middle + 1]);

    printf("YES\n1 %.12f\n", 0.0);
    printf("%d %.12f\n", middle + 1, result);
}