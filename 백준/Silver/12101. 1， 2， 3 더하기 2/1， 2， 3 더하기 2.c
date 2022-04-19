#include<stdio.h>

int dp[11] = {1, 2, 4};
int sum = 0;

void func(int n, int m, int* arr, int pre, int num) {

    int i;
    if(m == n) {
        for(i = 0; i < pre - 1; i++) {
            printf("%d+", arr[i]);
        }
        printf("%d", arr[pre - 1]);
        return;
    }
    else {
        for(i = 1; i < n - m; i++) {
            if(num > sum + dp[n - m - 1 - i]) {
                sum += dp[n - m - 1 - i];
                continue;
            }
            break;
        }
        arr[pre] = i;
        func(n, m + arr[pre], arr, pre + 1, num);
    }
}

int Dynamic(int n) {

    if(dp[n - 1]) {
        return dp[n - 1];
    }

    if(n <= 3) {
        return dp[n - 1];
    }
    
    if(n > 3) {
        for(int i = 3; i < n; i++) {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }
        return dp[n - 1];
    }
}

int main() {
    int n, k, i;
    int arr[11] = {0,};
    scanf("%d %d", &n, &k);
    if(Dynamic(n) < k) {
        printf("-1");
        return 0;
    }
    func(n, 0, arr, 0, k);
}