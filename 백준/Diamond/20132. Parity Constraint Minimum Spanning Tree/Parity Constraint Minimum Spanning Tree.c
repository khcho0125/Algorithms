#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ll long long
#define max(a, b) ((a) > (b) ? a : b)
#define min(a, b) ((a) < (b) ? a : b)
#define swap(a, b) {int i = a; a = b; b = i;}

typedef struct Way {
    int u, v;
    ll w;
}Way;

typedef struct Edge {
    int v;
    ll w;
    struct Edge* link;
}Edge;

typedef struct Vertex {
    Edge* link;
    Edge* back;
}Vertex;

typedef struct pair {
    ll o;
    ll e;
}pair;

typedef struct LCA {
    int v;
    pair p;
}LCA;

int UnionFind[100001];
LCA parent[18][100001];
int depth[100001];
Way E[300000];
Vertex mst[100001];

ll even = -1, odd = -1;

int compare(const void* a, const void* b) {
    Way num1 = *(Way*)a;
    Way num2 = *(Way*)b;

    if(num1.w > num2.w) {
        return 1;
    }
    if(num1.w < num2.w) {
        return -1;
    }
    return 0;
}

int find(int idx) {
    if(UnionFind[idx] < 0) {
        return idx;
    }
    return UnionFind[idx] = find(UnionFind[idx]);
}

int Union(int u, int v) {
    u = find(u);
    v = find(v);

    if(u == v) return 0;

    if(UnionFind[u] > UnionFind[v]) {
        UnionFind[v] += UnionFind[u];
        UnionFind[u] = v;
    }
    else {
        UnionFind[u] += UnionFind[v];
        UnionFind[v] = u;
    }
    return 1;
}

void build(int u, int v, ll w) {
    Edge* one = (Edge*)malloc(sizeof(Edge));
    one->link = NULL;
    one->v = v;
    one->w = w;
    if(mst[u].link == NULL) {
        mst[u].link = one;
    }
    else {
        mst[u].back->link = one;
    }
    mst[u].back = one;

    Edge* two = (Edge*)malloc(sizeof(Edge));
    two->link = NULL;
    two->v = u;
    two->w = w;
    if(mst[v].link == NULL) {
        mst[v].link = two;
    }
    else {
        mst[v].back->link = two;
    }
    mst[v].back = two;
}

void DFS(int idx) {
    Edge* cnt = (Edge*)malloc(sizeof(Edge));
    cnt = mst[idx].link;
    while(cnt != NULL) {
        if(depth[cnt->v] == -1) {
            depth[cnt->v] = depth[idx] + 1;
            parent[0][cnt->v].v = idx;
            if(cnt->w & 1) {
                parent[0][cnt->v].p.o = cnt->w;
            }
            else {
                parent[0][cnt->v].p.e = cnt->w;
            }
            DFS(cnt->v);
        }
        cnt = cnt->link;
    }
}

pair oper(pair a, pair b) {
    a.o = max(a.o, b.o);
    a.e = max(a.e, b.e);
    return a;
}

void update(ll p) {
    if(p & 1) {
        if(odd != -1) {
            odd = min(p, odd);
            return;
        }
        odd = p;
        return;
    }
    
    if(even != -1) {
        even = min(p, even);
        return;
    }
    even = p;
}

int main() {
    memset(UnionFind, -1, sizeof(UnionFind));
    int N, M, temp = 1;
    ll cost = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %lld", &E[i].u, &E[i].v, &E[i].w);
    }
    qsort(E, M, sizeof(Way), compare);
    for(int i = 0; i < M && temp != N; i++) {
        if(Union(E[i].u, E[i].v)) {
            cost += E[i].w;
            temp++;
            build(E[i].u, E[i].v, E[i].w);
        }
    }
    if(temp != N) {
        printf("-1 -1");
        return 0;
    }

    cost & 1 ? (odd = cost) : (even = cost);
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));

    depth[1] = 0;
    DFS(1);

    for(int i = 1; i < 18; i++) {
        for(int j = 2; j <= N; j++) {
            if(parent[i - 1][j].v != -1) {
                parent[i][j].v = parent[i - 1][parent[i - 1][j].v].v;
                if(parent[i][j].v != -1) {
                    parent[i][j].p = oper(parent[i - 1][j].p, parent[i - 1][parent[i - 1][j].v].p);
                }
            }
        }
    }

    int sub, u, v;
    pair set;
    for(int i = 1; i < M; i++) {
        u = E[i].u;
        v = E[i].v;
        if(depth[u] < depth[v]) {
            swap(u, v);
        }
        sub = depth[u] - depth[v];
        set = (pair){-1, -1};
        for(int k = 0; sub; k++) {
            if(sub & 1) {
                set = oper(set, parent[k][u].p);
                u = parent[k][u].v;
            }
            sub >>= 1;
        }

        if(u != v) {
            for(int k = 17; k >= 0; k--) {
                if(parent[k][u].v != -1 && parent[k][u].v != parent[k][v].v) {
                    set = oper(parent[k][v].p, set);
                    set = oper(parent[k][u].p, set);
                    v = parent[k][v].v;
                    u = parent[k][u].v;
                }
            }

            set = oper(parent[0][v].p, set);
            set = oper(parent[0][u].p, set);
        }

        if(set.e != -1) update(cost - set.e + E[i].w);
        if(set.o != -1) update(cost - set.o + E[i].w);
    }

    printf("%lld %lld", odd, even);
}