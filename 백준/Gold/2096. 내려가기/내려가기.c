#include<stdio.h>

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int main() {
    int dp[6] = {0,};
    int one, two, three, A, B, C, N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &A, &B, &C);
        one = max(dp[0], dp[1]) + A;
        two = max(dp[0], max(dp[1], dp[2])) + B;
        three = max(dp[1], dp[2]) + C;
        dp[0] = one;
        dp[1] = two;
        dp[2] = three;
        one = min(dp[3], dp[4]) + A;
        two = min(dp[3], min(dp[4], dp[5])) + B;
        three = min(dp[4], dp[5]) + C;
        dp[3] = one;
        dp[4] = two;
        dp[5] = three;
    }
    printf("%d %d", max(dp[0], max(dp[1], dp[2])), min(dp[3], min(dp[4], dp[5])));
}