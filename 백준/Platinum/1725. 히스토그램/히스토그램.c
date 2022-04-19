#include<stdio.h>

long long arr[100000] = {0,};

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long min(long long a, long long b) {
    return a > b ? b : a;
}

long long histogram(int start, int end) {
    if(start == end) return arr[start];
    int m = (start + end) / 2;
    long long p = max(histogram(start, m), histogram(m + 1, end));
    int L = m, R = m;
    long long temp = arr[m];
    while(start < L || R < end) {
        if(start < L && (R == end || arr[L - 1] > arr[R + 1])) {
            temp = min(arr[--L], temp);
        }
        else {
            temp = min(arr[++R], temp);
        }
        p = max(p, temp * (R - L + 1));
    }
    return p;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);    
    }
    printf("%d", histogram(0, n - 1));
}
