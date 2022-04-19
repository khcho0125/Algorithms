#include<stdio.h>

int dp[300] = {0,};
int stairs[300] = {0,};

int max(int a, int b) {
    return a > b ? a : b;
}

void jaegui(int index) {

    if(index == 0) {
        dp[index] = stairs[index];
        return;
    }

    if(index == 1) {
        dp[index] = max(stairs[index], stairs[index] + stairs[index - 1]);
        return;
    }

    dp[index] = max(dp[index - 2] + stairs[index], dp[index - 3] + stairs[index - 1] + stairs[index]);
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &stairs[i]);
        jaegui(i);
    }
    printf("%d\n", dp[N - 1]);
}