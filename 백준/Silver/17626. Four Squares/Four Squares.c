#include<stdio.h>
#include<math.h>

int dp[50001] = {0,};

int main() {
    int N, result = 0, pre = 1;
    scanf("%d", &N);
    for(int M = 1; M * M <= N; M++) {
        dp[M * M] = 1;
    }
    while(!dp[N]) {
        for(int temp = 1; temp < N; temp++) {
            if(dp[temp] == pre) {
                for(int M = 1; temp + M * M <= N; M++) {
                    if(!dp[temp + M * M]) {
                        dp[temp + M * M] = dp[temp] + 1; 
                    }
                }
            }
        }
        pre++;
    }
    printf("%d", dp[N]);
}