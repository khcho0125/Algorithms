#include<stdio.h>

long long h[100000] = {0,};

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long min(long long a, long long b) {
    return a > b ? b : a;
}

long long tree(int L, int R) {
    if(L == R) return h[L];
    int mid = (L + R) / 2;
    long long sum = max(tree(L, mid), tree(mid + 1, R));
    int a = mid, b = mid;
    long long temp = h[mid];

    while(L < a || b < R) {
        if(L < a && (b == R || h[a - 1] > h[b + 1])) {
            temp = min(h[--a], temp);
        }
        else {
            temp = min(h[++b], temp);
        }
        sum = max(sum, temp * (b - a + 1));
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    while(n) {
        for(int i = 0; i < n; i++) {
            scanf("%lld", &h[i]);
        }
        printf("%lld\n", tree(0, n - 1));
        scanf("%d", &n);
    }
}