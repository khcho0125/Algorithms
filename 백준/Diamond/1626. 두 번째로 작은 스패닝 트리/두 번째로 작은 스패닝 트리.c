#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a, b) {int i = a;a = b;b = i;}
#define max(a, b) (((a) > (b)) ? a : b)

typedef struct Edge
{
    int v1;
    int v2;
    int w;
} edge;

typedef struct node
{
    int v;
    int w;
    struct node *link;
} node;

typedef struct Tree
{
    node *link;
    node *back;
} tree;

typedef struct pair {
    int first;
    int second;
}pair;

typedef struct vertex
{
    int parent;
    pair* w;
} X;


int UnionFind[50001];
X parent[17][50001];
int depth[50001];
edge N[200000];
tree T[200000];

int real = 0, result = -1;

int compare(const void *a, const void *b)
{
    edge num1 = *(edge *)a;
    edge num2 = *(edge *)b;

    if (num1.w > num2.w)
    {
        return 1;
    }

    if (num1.w < num2.w)
    {
        return -1;
    }

    return 0;
}

void Tree_In(int v1, int v2, int w)
{
    node *one = (node *)malloc(sizeof(node));
    one->v = v2;
    one->w = w;
    one->link = NULL;
    if (T[v1].link == NULL)
    {
        T[v1].link = one;
        T[v1].back = one;
    }
    else
    {
        T[v1].back->link = one;
        T[v1].back = one;
    }
    node *two = (node *)malloc(sizeof(node));
    two->v = v1;
    two->w = w;
    two->link = NULL;
    if (T[v2].link == NULL)
    {
        T[v2].link = two;
        T[v2].back = two;
    }
    else
    {
        T[v2].back->link = two;
        T[v2].back = two;
    }
}

int find(int x)
{
    if (UnionFind[x] < 0)
    {
        return x;
    }
    return UnionFind[x] = find(UnionFind[x]);
}

int Union(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
    {
        return 0;
    }

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
    return 1;
}

void DFS(int idx)
{
    node *query = (node *)malloc(sizeof(node));
    query = T[idx].link;
    while (query != NULL)
    {
        if (depth[query->v] == -1)
        {
            pair* NewPair = (pair*)malloc(sizeof(pair));
            NewPair->first = query->w;
            NewPair->second = -1;
            depth[query->v] = depth[idx] + 1;
            parent[0][query->v].parent = idx;
            parent[0][query->v].w = NewPair;
            DFS(query->v);
        }
        query = query->link;
    }
}

pair* cop(pair* a, pair* b) {
    pair* newPair = (pair*)malloc(sizeof(pair));
    newPair->first = max(a->first, b->first);

    if(newPair->first != a->first) {
        newPair->second = max(b->second, a->first);
        return newPair;
    }
    if(newPair->first != b->first) {
        newPair->second = max(b->first, a->second);
        return newPair;
    }
    newPair->second = max(a->second, b->second);
    return newPair;
}

int main()
{
    int V, E, u, v, w, temp = 0;
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= V; i++)
    {
        UnionFind[i] = -1;
        depth[i] = -1;
        T[i].link = NULL;
    }
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &N[i].v1, &N[i].v2, &N[i].w);
    }
    qsort(N, E, sizeof(edge), compare);
    for (int i = 0; i < E && temp != V - 1; i++)
    {
        if (Union(N[i].v1, N[i].v2))
        {
            real += N[i].w;
            temp++;
            Tree_In(N[i].v1, N[i].v2, N[i].w);
        }
    }
    if (temp != V - 1 || E == V - 1)
    {
        printf("-1");
        return 0;
    }
    memset(parent, -1, sizeof(parent));
    depth[1] = 0;
    pair* newPair = (pair*)malloc(sizeof(pair));
    newPair->first = -1;
    newPair->second = -1;
    parent[0][1].w = newPair;
    DFS(1);
    for (int i = 0; i < 16; i++)
    {
        for (int j = 2; j <= V; j++)
        {
            if(parent[i][j].parent != -1) {
                parent[i + 1][j].parent = parent[i][parent[i][j].parent].parent;
                if(parent[i + 1][j].parent == -1) continue;
                parent[i + 1][j].w = cop(parent[i][j].w, parent[i][parent[i][j].parent].w);
            }
        }
    }
    for (int t = 0; t < E; t++)
    {
        u = N[t].v1;
        v = N[t].v2;
        w = N[t].w;
        if (depth[u] < depth[v])
            swap(u, v);
        int sub = depth[u] - depth[v];
        pair* ans = (pair*)malloc(sizeof(pair));
        ans->first = -1;
        ans->second = -1;

        for (int i = 0; sub; i++)
        {
            if (sub % 2)
            {
                ans = cop(ans, parent[i][u].w);
                u = parent[i][u].parent;
            }
            sub /= 2;
        }

        if (u != v)
        {
            for (int i = 16; i >= 0; i--)
            {
                if (parent[i][u].parent != -1 && parent[i][u].parent != parent[i][v].parent)
                {
                    ans = cop(parent[i][u].w, ans);
                    ans = cop(parent[i][v].w, ans);
                    u = parent[i][u].parent;
                    v = parent[i][v].parent;
                }
            }

            ans = cop(ans, parent[0][u].w);
            ans = cop(ans, parent[0][v].w);
        }

        if (w != ans->first && ans->first != -1 && (result == -1 || result > real - ans->first + w))
        {
            result = real - ans->first + w;
        }
        else if(w != ans->second && ans->second != -1 && (result == -1 || result > real - ans->second + w)) {
            result = real - ans->second + w;
        }
    }
    printf("%d", result);
}