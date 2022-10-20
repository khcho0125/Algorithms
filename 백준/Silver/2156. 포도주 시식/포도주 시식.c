#include<stdio.h>

#define max(a, b) ((a) > (b) ? a : b)

int dp[10001];
int arr[10001];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], dp[i - 2] + arr[i]);
        dp[i] = max(dp[i], dp[i - 3] + arr[i] + arr[i - 1]);
    }
    printf("%d", dp[N]);
}