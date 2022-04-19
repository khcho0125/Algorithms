#include<stdio.h>
#include<string.h>

#define MOD 1000000000

int dp[10][101][1 << 10];

int stair(int start, int len, int num) {

    if(len == 0) {
        return num == (1 << 10) - 1 ? 1 : 0;
    }

    if(dp[start][len][num] != -1) {
        return dp[start][len][num];
    }

    dp[start][len][num] = 0;
    if(start != 0) {
        dp[start][len][num] += stair(start - 1, len - 1, num | 1 << (start - 1));
    }
    if(start != 9) {
        dp[start][len][num] += stair(start + 1, len - 1, num | 1 << (start + 1));
    }
    
    dp[start][len][num] %= MOD;

    return dp[start][len][num];
}

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    if(N > 9) {
        for(int i = 1; i < 10; i++) {
            memset(dp, -1, sizeof(dp));
            sum = (sum + stair(i, N - 1, 1 << i)) % MOD;
        }
    }
    printf("%d", sum);
}