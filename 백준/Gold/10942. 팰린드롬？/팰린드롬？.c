#include<stdio.h>

int number[2001];
int dp[2001][2001] = {0,};

void list(int N) {
    for(int i = 1; i <= N; i++) {
        dp[i - 1][i] = (number[i - 1] == number[i]);
    }

    for(int i = 2; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
            dp[j - i][j] = (number[j - i] == number[j] && dp[j - i + 1][j - 1]);
        }
    }
}

int main() {
    int N, M, S, E;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &number[i]);
        dp[i][i] = 1;
    }
    list(N);
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &S, &E);
        printf("%d\n", dp[S][E]);
    }
}