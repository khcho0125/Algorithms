#include<stdio.h>
#include<string.h>

int tree[10001] = {0,};
int visit[10001] = {0,};

int DFS(int idx) {
    if(visit[idx]) return idx;

    visit[idx] = 1;
    return DFS(tree[idx]);
}

int main() {
    int T, N, A, B, result;
    scanf("%d", &T);
    for(int tc = 0; tc < T; tc++) {
        scanf("%d", &N);
        for(int i = 1; i < N; i++) {
            scanf("%d %d", &A, &B);
            tree[B] = A;
        }

        scanf("%d %d", &A, &B);
        DFS(A);
        result = DFS(B);
        printf("%d\n", result);
        
        memset(visit, 0, sizeof(visit));
        memset(tree, 0, sizeof(tree));
    }
}