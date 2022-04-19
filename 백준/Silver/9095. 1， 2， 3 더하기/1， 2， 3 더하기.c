#include<stdio.h>


int dp[11] = {1, 2, 4, 0};

int func(int n) {

    if(dp[n - 1]) {
        return dp[n - 1];
    }

    if(n <= 3) {
        return dp[n - 1];
    }
    else if(n > 3) {
        for(int i = 3; i < n; i++) {
            dp[i] = dp[i - 3] + dp[i - 2] + dp [i - 1];
        }
        return dp[n - 1];
    }
}

int main() {
    int n, T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%d\n", func(n));
    }
}