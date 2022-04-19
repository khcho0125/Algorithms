#include<stdio.h>
#include<string.h>

#define MOD 1000000000

int dp[100][10] = {0,};

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    for(int i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
        dp[i][0] = dp[i - 1][1] % MOD;
        dp[i][9] = dp[i - 1][8] % MOD;
    }
    for(int i = 1; i < 10; i++) {
        sum = (sum + dp[N - 1][i]) % MOD;
    }
    printf("%d", sum % MOD);
}