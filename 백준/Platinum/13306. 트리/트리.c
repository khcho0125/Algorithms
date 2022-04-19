#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 200000

int parent[MAX] = {
    0,
};
int UnionFind[MAX] = {
    -1, 0
};
int query[MAX * 2][3] = {
    0,
};
bool result[MAX * 2];
int pre = 0;

int find(int x)
{
    if (UnionFind[x] < 0)
    {
        return x;
    }
    else
    {
        int y = find(UnionFind[x]);
        UnionFind[x] = y;
        return y;
    }
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x == y)
        return;

    if (UnionFind[x] < UnionFind[y])
    {
        UnionFind[x] += UnionFind[y];
        UnionFind[y] = x;
    }
    else
    {
        UnionFind[y] += UnionFind[x];
        UnionFind[x] = y;
    }
}

int main()
{
    int N, Q, x, b, c, d, temp;
    scanf("%d %d", &N, &Q);
    Q += N - 1;
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &parent[i]);
        parent[i]--;
        UnionFind[i]--;
    }
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &query[i][0], &query[i][1]);
        query[i][1]--;
        if (query[i][0])
        {
            pre++;
            scanf("%d", &query[i][2]);
            query[i][2]--;
        }
    }
    temp = pre;

    for (int i = Q - 1; i >= 0; i--)
    {
        if (query[i][0])
        {
            result[--pre] = (find(query[i][1]) == find(query[i][2]));
        }
        else
        {
            Union(query[i][1], parent[query[i][1]]);
        }
    }
    for (int i = 0; i < temp; i++)
    {
        printf("%s\n", (result[i] ? "YES" : "NO"));
    }
}