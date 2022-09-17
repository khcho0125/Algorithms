#include<stdio.h>
#include<string.h>

#define abs(a) ((a) < 0 ? (a) * -1 : a)
#define min(a, b) ((a) < (b) ? a : b)
#define INF 987654321

int map[21][21] = {0,};
int dp[20][21][40001];
int N, temp, all = 0;


int solve(int layer, int x, int s) {

    if(layer == N) {
        return abs(all - s * 2);
    }
    
    if(dp[layer][x][s] != -1) {
        return dp[layer][x][s];
    }

    dp[layer][x][s] = INF;

    for(int i = 0; i <= x; i++) {
        temp = solve(layer + 1, i, s + map[i][layer + 1]);
        dp[layer][x][s] = min(temp, dp[layer][x][s]);
    }

    return dp[layer][x][s];

}

void find(int value, int layer, int x, int s) {
    if(layer == N) return;

    for(int i = 0; i <= x; i++) {
        if(dp[layer][i][s + map[i][layer]] == value) {
            printf("%d ", N - i);
            find(value, layer + 1, i, s + map[i][layer]);
            return;
        }
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    int result = INF;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            all += map[i][j];
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < N; j++) {
            map[i + 1][j] += map[i][j];
        }
    }

    for(int i = 0; i <= N; i++) {
        temp = solve(0, i, map[i][0]);
        result = min(temp, result);
    }

    printf("%d\n", result);

    find(result, 0, N, 0);
}