#include<stdio.h>
#include<stdlib.h>

#define min(a, b) ((a < b) ? a : b)
#define INF 10001

typedef struct App {
    int bite;
    int cost;
}app;

app Application[100] = {0,};
int dp[101][10001] = {0,};

int main() {
    int N, M, result = INF;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &Application[i].bite);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &Application[i].cost);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 10001; j++) {
            if(j >= Application[i].cost && dp[i][j - Application[i].cost] + Application[i].bite > dp[i][j]) {
                dp[i + 1][j] = dp[i][j - Application[i].cost] + Application[i].bite;
            }
            else {
                dp[i + 1][j] = dp[i][j];
            }
            if(dp[i + 1][j] >= M) {
                result = min(result, j);
            }
        }
    }
    printf("%d", result);
}