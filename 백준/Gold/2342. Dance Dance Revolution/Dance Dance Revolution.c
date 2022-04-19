#include<stdio.h>
#include<string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define INF 987654321

int cost[5][5] = {
    {0, 0, 0, 0, 0},
    {2, 1, 3, 4, 3},
    {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3},
    {2, 3, 4, 3, 1}
};

int dp[5][5][100001];
int input[100001] = {0,};

int DFS(int idx, int one, int two) {

    if(dp[one][two][idx] != -1) {
        return dp[one][two][idx];
    }

    if(input[idx] == 0) {
        return 0;
    }

    dp[one][two][idx] = INF;

    if(one == input[idx] || two == input[idx]) {
        dp[one][two][idx] = min(dp[one][two][idx], DFS(idx + 1, one, two) + 1);
    }
    else {
        dp[one][two][idx] = min(dp[one][two][idx], min(DFS(idx + 1, input[idx], two) + cost[input[idx]][one], DFS(idx + 1, one, input[idx]) + cost[input[idx]][two]));
    }

    return dp[one][two][idx];
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &input[0]);
    for(int pre = 0; input[pre++];) {
        scanf("%d", &input[pre]);
    }
    printf("%d", DFS(0, 0, 0));
}