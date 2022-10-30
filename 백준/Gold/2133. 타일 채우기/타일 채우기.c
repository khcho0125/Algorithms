#include<stdio.h>

typedef struct Wall {
    int none, one, three, onetwo, twothree;
}Wall;

Wall dp[32] = {0,};

int main() {
    int N;
    scanf("%d", &N);
    dp[0].none = 1;
    for(int i = 1; i <= N; i++) {
        dp[i].one = dp[i - 1].twothree;
        dp[i].three = dp[i - 1].onetwo;
        dp[i].onetwo = dp[i - 1].one + dp[i - 1].none;
        dp[i].twothree = dp[i - 1].three + dp[i - 1].none;
        dp[i].none = dp[i - 2].none + dp[i].one + dp[i].three;
    }

    printf("%d", dp[N].none);
}