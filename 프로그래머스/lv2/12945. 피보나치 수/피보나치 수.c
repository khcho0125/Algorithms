#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int dp[100001] = {0,};

int solution(int n) {
    if(n < 3) return 1;
    if(!dp[n]) {
        return dp[n] = (solution(n - 1) + solution(n - 2)) % 1234567;
    }
    return dp[n];
}