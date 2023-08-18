#include<stdio.h>
#include<string.h>

#define N_MAX 14
#define M_MAX 14
#define MOD 9901

#define NOT_VISIT -1

int N, M;
int dp[N_MAX * M_MAX][1 << M_MAX];

int go(int idx, int status) {
    if(idx >= N * M) return status ? 0 : (idx == N * M);

    if(dp[idx][status] != NOT_VISIT) return dp[idx][status];

    dp[idx][status] = 0;

    if(status & (1 << 0)) {
        return dp[idx][status] = go(idx + 1, status >> 1);
    }
    
    if(idx % M < (M - 1) && (status & (1 << 1)) == 0) {
        dp[idx][status] += go(idx + 2, status >> 2);
    }

    dp[idx][status] += go(idx + 1, (status >> 1) | (1 << (M - 1)));

    dp[idx][status] %= MOD;
    return dp[idx][status];
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &N, &M);

    printf("%d", go(0, 0));
}