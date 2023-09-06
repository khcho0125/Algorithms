#include<stdio.h>

#define N_MAX 1000001
#define ll long long

typedef struct Line {
    ll a, b;
}L;

ll unit[N_MAX];
ll dp[N_MAX];
ll a, b, c;

L stack[N_MAX];
int size = 0;

long double cross(const L* a, const L* b) {
    return (long double)(b->b - a->b) / (a->a - b->a);
}

void insert(ll x, ll d) {
    stack[size] = (L) {
        .a = -2 * a * x + b,
        .b = a * x * x - b * x + d
    };
    while(size > 1 && cross(&stack[size - 2], &stack[size - 1]) > cross(&stack[size - 1], &stack[size])) {
        stack[size - 1] = stack[size];
        size--;
    }
    size++;
}

ll lower_bound(ll x) {
    int l = 0, r = size;
    while(l + 1 < r) {
        int m = (l + r) >> 1;
        if(cross(&stack[m - 1], &stack[m]) <= x) l = m;
        else r = m;
    }
    return stack[l].a * x + stack[l].b;
}

int main() {
    ll n, soldier;
    scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &soldier);
        unit[i] = unit[i - 1] + soldier;
    }

    insert(0, 0);
    for(int i = 1; i <= n; i++) {
        dp[i] = c + a * unit[i] * unit[i] + lower_bound(unit[i]);
        insert(unit[i], dp[i]);
    }

    printf("%lld", dp[n]);
}