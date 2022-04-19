#include<stdio.h>

int dp[1025][1025] = {0,};

int main() {
    int N, M, x1, x2, y1, y2;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &dp[i][j]);
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] += dp[i][j - 1];
        }
    }
    for(int i = 1; i <= N;i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] += dp[i - 1][j];
        }
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x2][y1 - 1] - dp[x1 - 1][y2]);
    }
}