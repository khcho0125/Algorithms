#include<stdio.h>
#include<string.h>

#define MOD 9901

#define fill(src, val) {src = (src + val) % MOD;}

int dp[17][1 << 14];
int temp[1 << 14];
int all;

void way(int grid, int next, int val) {
    for(int k = next; k <= all; k <<= 1) {
        if((grid & k) == 0) {
            fill(temp[grid | k], val);
            way(grid | k, k << 2, val);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    all = (1 << N) - 1;

    dp[0][0] = 1;
    for(int i = 0; i < M; i++) {
        memset(temp, 0, sizeof(temp));
        for(int b = 0; b <= all; b++) {
            way(b, 3, dp[i][b]);
        }

        for(int b = 0; b <= all; b++) {
            fill(dp[i][b], temp[b]);
            fill(dp[i + 1][b ^ all], dp[i][b]);
        }
    }

    printf("%d", dp[M - 1][all]);
}