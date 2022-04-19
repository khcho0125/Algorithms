#include<stdio.h>
#include<stdlib.h>

#define min(a, b) (((a) > (b)) ? a : b)
#define INF 2147483647

int dp[501][501];
int arr[501];

void list(int N) {
    int k, temp;
    for(int i = 1; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
            dp[j - i][j] = INF;
            for(int k = j - i; k < j; k++) {
                temp = dp[j - i][k] + dp[k + 1][j] + arr[j - i - 1] * arr[k] * arr[j];
                if(dp[j - i][j] > temp)
                    dp[j - i][j] = temp;
            }
        }
    }
}

int main() {
    int N, r, c;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d %d", &r, &c);
        dp[i][i] = 0;
        if(i == 1) {
            arr[0] = r;
        }
        arr[i] = c;
    }
    list(N);
    printf("%d", dp[1][N]);
}