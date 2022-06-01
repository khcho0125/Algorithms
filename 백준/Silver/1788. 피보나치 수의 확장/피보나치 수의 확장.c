#include<stdio.h>
#include<string.h>

#define abs(a) (a < 0 ? (a * -1) : a)
#define MOD 1000000000

int dp[1000001] = {0, 1};

int main() {
    int N, sign;
    scanf("%d", &N);
    sign = (N == 0) ? 0 : (N < 0 && N % 2 == 0) ? -1 : 1;
    N = abs(N);
    for(int i = 2; i <= N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    printf("%d\n%d", sign, dp[N]);
}