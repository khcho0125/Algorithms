#include<stdio.h>

#define ll long long

enum COMMAND {
    UPDATE, SUM
};

int map[1025][1025];
int segtree[2050][2050];

int sub_tree_init(int node, int sub_node, int start, int end, int xstrip) {
    if (start == end) return segtree[node][sub_node] = map[xstrip][start];

    int mid = (start + end) / 2;

    int Ltree = sub_tree_init(node, sub_node * 2, start, mid, xstrip);
    int Rtree = sub_tree_init(node, sub_node * 2 + 1, mid + 1, end, xstrip);

    return segtree[node][sub_node] = Ltree + Rtree;
}

void tree_init(int node, int start, int end, int N) {
    if (start == end) {
        sub_tree_init(node, 1, 1, N, start);
        return;
    }

    int mid = (start + end) / 2;

    tree_init(node * 2, start, mid, N);
    tree_init(node * 2 + 1, mid + 1, end, N);

    for(int sub_node = 1; sub_node <= N * 2; sub_node++) {
        segtree[node][sub_node] = segtree[node * 2][sub_node] + segtree[node * 2 + 1][sub_node];
    }
}
    

int sub_update(int node, int sub_node, int start, int end, int y, int value) {
    if (y < start || end < y) return segtree[node][sub_node];

    if (start == y && y == end) return segtree[node][sub_node] = value;

    int mid = (start + end) / 2;

    int Ltree = sub_update(node, sub_node * 2, start, mid, y, value);
    int Rtree = sub_update(node, sub_node * 2 + 1, mid + 1, end, y, value);

    return segtree[node][sub_node] = Ltree + Rtree;
}

void update(int node, int start, int end, int x, int y, int value, int N) {
    if (x < start || end < x) return;

    if (start == x && x == end) {
        sub_update(node, 1, 1, N, y, value);
        return;
    }

    int mid = (start + end) / 2;

    update(node * 2, start, mid, x, y, value, N);
    update(node * 2 + 1, mid + 1, end, x, y, value, N);

    for(int sub_node = 1; sub_node <= N * 2; sub_node++) {
        segtree[node][sub_node] = segtree[node * 2][sub_node] + segtree[node * 2 + 1][sub_node];
    }
}

int sub_query(int node, int sub_node, int start, int end, int sy, int ey) {
    if (end < sy || ey < start) return 0;

    if (sy <= start && end <= ey) return segtree[node][sub_node];

    int mid = (start + end) / 2;

    int Ltree = sub_query(node, sub_node * 2, start, mid, sy, ey);
    int Rtree = sub_query(node, sub_node * 2 + 1, mid + 1, end, sy, ey);

    return Ltree + Rtree;
}

int query(int node, int start, int end, int sx, int ex, int y1, int y2, int N) {
    if (end < sx || ex < start) return 0;
    
    if (sx <= start && end <= ex) return sub_query(node, 1, 1, N, y1, y2);

    int mid = (start + end) / 2;

    int Ltree = query(node * 2, start, mid, sx, ex, y1, y2, N);
    int Rtree = query(node * 2 + 1, mid + 1, end, sx, ex, y1, y2, N);

    return Ltree + Rtree;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) { 
            scanf("%d", &map[i][j]);
        }
    }

    tree_init(1, 1, N, N);

    int w, c, x1, y1, x2, y2;
    for(int i = 0; i < M; i++) {
        scanf("%d", &w);
        switch(w) {
            case UPDATE:
                scanf("%d %d %d", &x1, &y1, &c);
                update(1, 1, N, x1, y1, c, N);
                break;

            case SUM:
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                printf("%d\n", query(1, 1, N, x1, x2, y1, y2, N));
                break;
        }
    }

}