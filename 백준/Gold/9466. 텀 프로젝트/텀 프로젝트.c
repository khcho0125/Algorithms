#include<stdio.h>
#include<string.h>

int cycle[100001];
int visit[100001] = {0,};
int dp[100001] = {0,};
int have = 0;

void DFS(int idx, int start, int sum) {
    if(visit[cycle[idx]] == start) {
        have += (sum - dp[cycle[idx]]);
        return;
    }

    if(visit[cycle[idx]]) {
        return;
    }

    dp[cycle[idx]] = sum;
    visit[cycle[idx]] = start;
    DFS(cycle[idx], start, sum + 1);
}

int main() {
    int T, N;
    scanf("%d", &T);
    for(int k = 0; k < T; k++) {
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) {
            scanf("%d", &cycle[i]);
        }
        for(int i = 1; i <= N; i++) {
            if(!visit[i]) {
                dp[i] = 0;
                visit[i] = i;
                DFS(i, i, 1);
            }
        }
        printf("%d\n", N - have);
        have = 0;
        memset(visit, 0, sizeof(visit));
        memset(dp, 0, sizeof(dp));
    }
}