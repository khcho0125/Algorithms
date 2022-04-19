#include<stdio.h>
#include<string.h>

#define MOD 1000000007

long long dp[8] = {1, 0, 0, 0, 0, 0, 0, 0};

/*  정보과학관 : 0
    전산관 : 1
    미래관 : 2
    신양관 : 3
    한경직기념관 : 4
    진리관 : 5
    학생 회관 : 6
    형남공학관 : 7
*/ 
long long* Route() {
    static long long temp[8] = {0,};
    temp[0] = (dp[1] + dp[2]) % MOD;
    temp[1] = (dp[0] + dp[2] + dp[3]) % MOD;
    temp[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % MOD;
    temp[3] = (dp[1] + dp[2] + dp[4] + dp[5]) % MOD;
    temp[4] = (dp[2] + dp[3] + dp[5] + dp[7]) % MOD;
    temp[5] = (dp[3] + dp[4] + dp[6]) % MOD;
    temp[6] = (dp[5] + dp[7]) % MOD;
    temp[7] = (dp[6] + dp[4]) % MOD;
    return temp;
}

int main() {
    int D;
    scanf("%d", &D);
    for(int i = 0; i < D; i++) {
        memcpy(dp, Route(), sizeof(dp));
    }
    printf("%lld", dp[0]);
}