#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ll long long
#define INF 1e18
#define Q_MAX 200000
#define X_MAX 1e12
#define swap(a, b, T) {T t = a; a = b; b = t;}
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Line {
    ll a, b;
}L;

typedef struct Node {
    int l, r;
    L area;
}N;

N segment[Q_MAX];
int temp = 0;

ll get(L line, ll x) {
    return line.a * x + line.b;
}

int update(int idx, L shot, ll s, ll e) {
    if(idx == -1) {
        segment[temp] = (N) {
            .area = shot,
            .l = -1,
            .r = -1
        };

        return temp++;
    }

    ll m = (s + e) / 2;

    if(get(segment[idx].area, m) < get(shot, m)) swap(segment[idx].area, shot, L);
    
    if(get(segment[idx].area, s) < get(shot, s)) segment[idx].l = update(segment[idx].l, shot, s, m);
    else if(get(segment[idx].area, e) < get(shot, e)) segment[idx].r = update(segment[idx].r, shot, m + 1, e);

    return idx;
}

ll query(int idx, ll x, ll s, ll e) {
    if(idx == -1) return -INF;

    ll m = (s + e) / 2;

    ll w = get(segment[idx].area, x);
    if(x <= m) {
        ll left = query(segment[idx].l, x, s, m);
        return max(w, left);
    }
    else {
        ll right = query(segment[idx].r, x, m + 1, e);
        return max(w, right);
    }
}

int main() {
    update(-1, (L) {0, -INF}, 0, 0);

    ll Q, n, a, b, x;
    scanf("%lld", &Q);
    for(int i = 0; i < Q; i++) {
        scanf("%lld", &n);
        switch(n) {
            case 1:
                scanf("%lld %lld", &a, &b);
                update(0, (L) {.a = a, .b = b}, -X_MAX, X_MAX);
                break;
            case 2:
                scanf("%lld", &x);
                printf("%lld\n", query(0, x, -X_MAX, X_MAX));
                break;
        }
    }
}