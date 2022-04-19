#include<stdio.h>

int dp[2][100001] = {0,};

int max(int a, int b) {
    return a > b ? a : b;
}

void solve(int N) {
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            if(i == 1) {
                dp[j][i] += dp[!j][i - 1];
            }
            else {
                dp[j][i] += max(dp[!j][i - 2], dp[!j][i - 1]);
            }
        }
    }
}

int main() {
    int N, T;
    scanf("%d", &T);
    for(int TC = 0; TC < T; TC++) {
        scanf("%d", &N);
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%d", &dp[i][j]);
            }
        }
        solve(N);
        printf("%d\n", max(dp[0][N - 1], dp[1][N - 1]));
    }
}