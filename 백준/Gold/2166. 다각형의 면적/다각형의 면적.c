#include<stdio.h>

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)
#define abs(a) ((a < 0) ? a * -1 : a)

typedef struct P {
    double x, y;
}P;

P core[10000];

double ccw(P* a, P* b, P* c) {
    double res = a->x * b->y + b->x * c->y + c->x * a->y;
    res += (-a->y * b->x - b->y * c->x - c->y * a->x);
    return res / 2;
}

int main() {
    int N;
    double result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lf %lf", &core[i].x, &core[i].y);
    }
    for(int i = 1; i < N - 1; i++) {
        result += ccw(&core[0], &core[i], &core[i + 1]);
    }
    printf("%.1lf", abs(result));
}