#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define NUM_MAX 100

#define swap(a, b) {int _ = a; a = b; b = _;}
#define max(a, b) ((a) > (b) ? a : b)

int dp[NUM_MAX][NUM_MAX + 1];

int solve(int start, int end) {

    if(dp[start][end] >= 0) return dp[start][end];

    dp[start][end] = (dp[start][end] * -1) - 1;

    int value = 0, temp;
    for(int i = 0; i < end - start; i++) {
        temp = solve(start, start + i) + solve(start + i + 1, end);
        value = max(value, temp);
    }

    return dp[start][end] += value;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int N, A, B;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B);
        if(A > B) swap(A, B);
        dp[A][B] = -2;
    }
    
    printf("%d", solve(1, 100));
}