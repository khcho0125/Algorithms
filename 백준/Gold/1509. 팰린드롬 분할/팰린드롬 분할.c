#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define INF 987654321

bool dp[2501][2501] = {0,};

int main() {
    char str[2501];
    int count[2501];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        dp[i][i] = true;
    }
    for(int i = 1; i < len; i++) {
        if(str[i] == str[i - 1]) {
            dp[i - 1][i] = true;
        }
    }
    for(int i = 2; i < len; i++) {
        for(int j = 0; j < len; j++) {
            int k = i + j;
            if(str[j] == str[k] && dp[j + 1][k - 1]) {
                dp[j][k] = true;
            }
        }
    }
    count[0] = 0;
    for(int i = 1; i <= len; i++) {
        count[i] = INF;
        for(int j = 0; j < i; j++) {
            if(dp[j][i - 1] && count[i] > count[j] + 1) {
                count[i] = count[j] + 1;
            }
        }
    }
    printf("%d", count[len]);
}