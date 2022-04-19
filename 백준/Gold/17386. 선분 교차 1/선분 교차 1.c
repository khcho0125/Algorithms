#include<stdio.h>

#define ll long long

typedef struct pair {
    ll x, y;
}pair;

int ccw(pair one, pair two, pair three) {
    ll a = (one.x * two.y) + (two.x * three.y) + (three.x * one.y);
    ll b = (one.y * two.x) + (two.y * three.x) + (three.y * one.x);
    ll value = a - b;
    return (value > 0) ? 1 : (value < 0 ? -1 : 0);
}

int Intersect(pair L1_first, pair L1_second, pair L2_first, pair L2_second) {
    int d1, d2, d3, d4;
    d1 = ccw(L1_first, L2_first, L2_second);
    d2 = ccw(L1_second, L2_first, L2_second);
    d3 = ccw(L2_first, L1_first, L1_second);
    d4 = ccw(L2_second, L1_first, L1_second);
    if(d1 * d2 < 0 && d3 * d4 < 0) return 1;

    return 0;
}

int main() {
    pair P[4];
    for(int i = 0; i < 4; i++) {
        scanf("%lld %lld", &P[i].x, &P[i].y);
    }
    printf("%d", Intersect(P[0], P[1], P[2], P[3]));
}