#include<stdio.h>

#define MOD 1000000000

int dp[201][201] = {0,};

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    dp[0][0] = 1;
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }

    printf("%d", dp[K][N]);
}