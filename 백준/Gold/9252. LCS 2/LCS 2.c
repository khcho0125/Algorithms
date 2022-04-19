#include<stdio.h>
#include<string.h>

#define max(a, b) ((a > b) ? a : b)

char squence[2][1001];

int dp[1001][1001] = {0,};

void tracking(int L1, int L2) {
    if(!dp[L1][L2]) {
        return;
    }

    if(dp[L1][L2] == dp[L1 - 1][L2]) {
        tracking(L1 - 1, L2);
    }
    else if(dp[L1][L2] == dp[L1][L2 - 1]) {
        tracking(L1, L2 - 1);
    }
    else {
        if(dp[L1][L2] != 1) {
            tracking(L1 - 1, L2 - 1);
        }
        printf("%c", squence[0][L1 - 1]);
    }
}

int main() {
    int result = 0, Len1, Len2;
    scanf("%s %s", squence[0], squence[1]);
    Len1 = strlen(squence[0]);
    Len2 = strlen(squence[1]);
    for(int i = 0; i < Len1; i++) {
        for(int j = 0; j < Len2; j++) {
            if(squence[0][i] == squence[1][j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                if(result < dp[i + 1][j + 1]) {
                    result = dp[i + 1][j + 1];
                }
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    printf("%d\n", result);
    tracking(Len1, Len2);
}