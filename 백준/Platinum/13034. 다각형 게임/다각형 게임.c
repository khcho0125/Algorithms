#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 1001
#define GRUNDY_MAX 10

int dp[N_MAX];
bool mex[GRUNDY_MAX];

int main() {
    int N;
    scanf("%d", &N);

    dp[0] = dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int p = 4; p <= N; p++) {
        memset(mex, false, sizeof(mex));
        for(int i = 0, j = p - 2; i <= j; i++, j--) mex[dp[i] ^ dp[j]] = true;
        for(int g = 0; mex[dp[p] = g]; g++);
    }

    printf("%d", dp[N] ? 1 : 2);
}