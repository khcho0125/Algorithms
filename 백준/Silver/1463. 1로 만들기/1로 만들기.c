#include <stdio.h>

int dp[1000001] = {0,};

int func(int);

int main()
{
    int n;
    scanf("%d", &n);
    dp[2] = 1;
    dp[3] = 1;
    printf("%d", func(n));
}

int func(int n) {
    
    if(dp[n] || n == 1) {
        return dp[n];
    }
    else {
        int min;
        min = func(n - 1);
        if(n % 2 == 0 && min > func(n / 2)) {
            min = func(n / 2);
        }
        if(n % 3 == 0 && min > func(n / 3)) {
            min = func(n / 3);
        }
        dp[n] = min + 1;
        return dp[n];
    }
}