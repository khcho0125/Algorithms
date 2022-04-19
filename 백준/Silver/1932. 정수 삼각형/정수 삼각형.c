#include<stdio.h>

int arr[500][500] = {0,};
int dp[500][500] = {0,};

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int N;
    int result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i + 1; j++) {
            scanf("%d", &arr[i][j]);
            if(j == 0 && i != 0)
                dp[i][j] = arr[i][j] += dp[i - 1][j];
            else if(j == i && i != 0) {
                dp[i][j] = arr[i][j] += dp[i - 1][j - 1];
            }
            else if(i != 0) {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
            }
            else {
                dp[i][j] = arr[i][j];
            }
            result = max(dp[i][j], result);
        }
    }
    printf("%d", result);
}