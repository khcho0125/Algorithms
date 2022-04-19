#include<stdio.h>
#include<string.h>

#define INF 987654321
#define min(a,b) ((a < b) ? a : b) 

int map[16][16];
int dp[16][1 << 16];
int N;

int Dynamic(int now, int num) {
    
    if(num == (1 << N) - 1) {
        if(map[now][0] != 0) {
            return map[now][0];
        }
        return INF;
    }

    if(dp[now][num] != -1) {
        return dp[now][num];
    }
    dp[now][num] = INF;
    for(int i = 0; i < N; i++) {
        if(map[now][i] && !(num & (1 << i))) {
            dp[now][num] = min(map[now][i] + Dynamic(i, num | (1 << i)), dp[now][num]);
        }
    }
    return dp[now][num];
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", Dynamic(0, 1));
}