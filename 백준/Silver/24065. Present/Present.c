#include<stdio.h>

#define ll long long
#define pow(a) ((a) * (a))

ll solve(int M, int N, int A) {
    if(N == 0) return 0;
    ll result = 0;
    for(int i = 0; i < N; i++) {
        if(pow(i) + pow(N - i) >= A) {
            result += pow(M - N);
        }
    }
    return solve(M, N - 1, A) + result;
}

int main() {
    int T, N, A;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d %d", &N, &A);
        printf("%lld\n", solve(N, N - 1, A));
    }
}