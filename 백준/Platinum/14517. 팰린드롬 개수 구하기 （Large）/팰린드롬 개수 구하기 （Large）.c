#include<stdio.h>

#define MOD 10007

char str[1001];
int dp[1000][1000];

int main() {
    scanf("%s", str);

    int length = 0;
    for(; str[length] != '\0'; length++) {
        dp[length][length] = 1;
    }

    for(int i = 1; i < length; i++) {
        for(int j = 0; j + i < length; j++) {
            dp[j][j + i] = dp[j + 1][j + i] + dp[j][j + i - 1] + (str[j] == str[j + i] ? 1 : -dp[j + 1][j + i - 1] + MOD);
            dp[j][j + i] %= MOD;
        }
    }

    printf("%d", dp[0][length - 1]);
}