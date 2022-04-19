#include <stdio.h>

int dp[101][100001] = {
    0,
};
int V[100] = {
    0,
};
int W[100] = {
    0,
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N, K, result = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &W[i], &V[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if(W[i - 1] <= j) {
                dp[i][j] = max(V[i - 1] + dp[i - 1][j - W[i - 1]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i = 1; i <= K; i++) {
        result = max(result, dp[N][i]);
    }
    printf("%d", result);
}