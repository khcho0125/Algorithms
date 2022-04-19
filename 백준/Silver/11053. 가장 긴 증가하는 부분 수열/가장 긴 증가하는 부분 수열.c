#include<stdio.h>

int dp[1000] = {0,};

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, result = 0;
    int arr[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
        result = max(result, dp[i]);
    }
    printf("%d", result + 1);
}