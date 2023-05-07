#include<stdio.h>
#include<string.h>

#define LIMIT 500001
#define PIECE_LIMIT 50
#define max(a, b) ((a) > (b) ? a : b)

int dp[PIECE_LIMIT + 1][LIMIT];
int piece[PIECE_LIMIT];

void memorization(int idx, int dif) {
    dp[idx + 1][dif] = max(dp[idx + 1][dif], dp[idx][dif]);
    
    dp[idx + 1][dif + piece[idx]] = max(dp[idx + 1][dif + piece[idx]], dp[idx][dif] + piece[idx]);

    if(dif == 0) return;

    if(dif < piece[idx]) {
        dp[idx + 1][piece[idx] - dif] = max(dp[idx + 1][piece[idx] - dif], dp[idx][dif] - dif + piece[idx]);
    }
    else {
        dp[idx + 1][dif - piece[idx]] = max(dp[idx + 1][dif - piece[idx]], dp[idx][dif]);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &piece[i]);
    }

    dp[0][0] = 0;
    memorization(0, 0);
    for(int i = 1; i < N; i++) {
        for(int d = 0; d < LIMIT; d++) {
            if(dp[i][d] != -1) memorization(i, d);
        }
    }

    printf("%d", dp[N][0] ? dp[N][0] : -1);
}