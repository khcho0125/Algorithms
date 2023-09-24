#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define N_MAX 501
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Edge {
    int v;
    struct Edge* link;
}E;

typedef struct Node {
    int w;
    E* link;
    E* back;
}N;

int dp[N_MAX];
N building[N_MAX];

int cost(int idx) {
    if(dp[idx] != -1) return dp[idx];

    dp[idx] = 0;

    for(E* prev = building[idx].link; prev != NULL; prev = prev->link) {
        int t = cost(prev->v);
        dp[idx] = max(dp[idx], t);
    }

    return dp[idx] += building[idx].w;
}

int main() {
    int n, B;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &building[i].w);
        while(TRUE) {
            scanf("%d", &B);

            if(B == -1) break;

            E* one = (E*)malloc(sizeof(E));
            one->v = B;
            one->link = NULL;

            if(building[i].link == NULL) building[i].link = one;
            else building[i].back->link = one;
            building[i].back = one;
        }
    }

    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        printf("%d\n", cost(i));
    }
}