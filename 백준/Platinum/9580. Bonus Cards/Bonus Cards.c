#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define ll long long

#define N_MAX 3001

double dp[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];

double icpc(int n, int i, int j, ll a, ll b) {
    if(a == i && b == j) return 0;
    if(visited[i][j]) return dp[i][j];

    visited[i][j] = true;
    
    double ab = (a - i) * 2 + b - j;
    dp[i][j] = 2 / ab;

    if(i + j + 1 == n) return dp[i][j];

    if(i < a) dp[i][j] += ((a - i - 1) * 2 / ab) * icpc(n, i + 1, j, a, b);
    if(j < b) dp[i][j] += ((b - j) / ab) * icpc(n, i, j + 1, a, b);

    return dp[i][j];
}

double acm(int n, int i, int j, ll a, ll b) {
    if(a == i && b == j) return 0;
    if(visited[i][j]) return dp[i][j];

    visited[i][j] = true;

    double ab = (a - i) * 2 + b - j;
    dp[i][j] = 1 / ab;

    if(i + j + 1 == n) return dp[i][j];

    if(i < a) dp[i][j] += ((a - i) * 2 / ab) * acm(n, i + 1, j, a, b);
    if(j < b) dp[i][j] += ((b - j - 1) / ab) * acm(n, i, j + 1, a, b);

    return dp[i][j];
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    printf("%.10f\n", icpc(n, 0, 0, a + 1, b));

    memset(visited, false, sizeof(visited));
    printf("%.10f", acm(n, 0, 0, a, b + 1));
}