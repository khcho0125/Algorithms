#include<stdio.h>
#include<string.h>

#define min(a, b) (a < b ? a : b)

int dp[10001] = {0,};

int main() {
    memset(dp, -1, sizeof(dp));
    int N, M, coin;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &coin);
        for(int k = 1, c = coin; c <= M; k++, c += coin) 
            dp[c] = (dp[c] == -1 ? k : min(dp[c], k));
    }

    for(int i = 2; i <= M; i++) {
        for(int j = 1; j <= i - j; j++) {
            if(dp[j] != -1 && dp[i - j] != -1)
                dp[i] = (dp[i] == -1 ? dp[j] + dp[i - j] : min(dp[i], dp[j] + dp[i - j]));
        }
    }

    printf("%d", dp[M]);
}