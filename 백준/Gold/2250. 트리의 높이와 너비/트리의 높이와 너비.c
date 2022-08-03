#include<stdio.h>

#define INF 987654321
#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b) 

int tree[10001][2];
int range[10001][2] = {0,};
int parent[10001] = {0,};
int max = 0, level = 0;

int find(int idx) {
    if(parent[idx] == 0) return idx;
    return find(parent[idx]);
}

int DFS(int idx, int depth, int add) {
    int left = 0, right = 0;
    
    if(tree[idx][0] != -1) left = DFS(tree[idx][0], depth + 1, add);
    if(tree[idx][1] != -1) right = DFS(tree[idx][1], depth + 1, add + left + 1);

    range[depth][0] = min(add + left + 1, range[depth][0]);
    range[depth][1] = max(add + left + 1, range[depth][1]);
    if(range[depth][1] - range[depth][0] + 1 >= max) {
        max = range[depth][1] - range[depth][0] + 1;
        level = depth;
    }
    return left + right + 1;
}

int main() {
    int N, A, B, C;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        range[i][0] = INF;
        scanf("%d %d %d", &A, &B, &C);
        tree[A][0] = B;
        tree[A][1] = C;
        parent[B] = A;
        parent[C] = A;
    }
    DFS(find(1), 1, 0);
    printf("%d %d\n", level, max);
}