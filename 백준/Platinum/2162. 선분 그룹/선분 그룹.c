#include<stdio.h>
#include<string.h>

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

typedef struct P {
    int x, y;
}P;

typedef struct segment {
    P one;
    P two;
}V;

int UnionFind[3001];
V line[3000];

int Find(int x) {
    if(UnionFind[x] < 0) {
        return x;
    }
    return UnionFind[x] = Find(UnionFind[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) {
        return;
    }

    if(UnionFind[x] < UnionFind[y]) {
        UnionFind[x] += UnionFind[y];
        UnionFind[y] = x;
    }
    else {
        UnionFind[y] += UnionFind[x];
        UnionFind[x] = y;
    }
}

int cross(P* a, P* b) {
    return a->x * b->y - a->y * b->x;
}

int dirt(P* one, P* two, P* three) {
    P ca, cb;
    ca.x = one->x - three->x, ca.y = one->y - three->y;
    cb.x = two->x - three->x, cb.y = two->y - three->y;
    int value = cross(&ca, &cb);
    return (value > 0) ? 1 : (value < 0 ? -1 : 0);
}

int onSegment(P* a, P* b, P* c) {
	if(c->x >= min(a->x, b->x) && c->x <= max(a->x,b->x) && c->y >= min(a->y,b->y) && c->y <= max(a->y,b->y)) return 1;
	return 0;
}

int lineIntersect(V* L1, V* L2) {
    int d1 = dirt(&L1->one, &L1->two, &L2->one);
    int d2 = dirt(&L1->one, &L1->two, &L2->two);
    int d3 = dirt(&L2->one, &L2->two, &L1->one);
    int d4 = dirt(&L2->one, &L2->two, &L1->two);
    if(d1 * d2 < 0 && d3 * d4 < 0) {
        return 1;
    }
    else if(!d1 && onSegment(&L1->one, &L1->two, &L2->one)) return 1;
    else if(!d2 && onSegment(&L1->one, &L1->two, &L2->two)) return 1;
    else if(!d3 && onSegment(&L2->one, &L2->two, &L1->one)) return 1;
    else if(!d4 && onSegment(&L2->one, &L2->two, &L1->two)) return 1;
    return 0;
}

int main() {
    int N, x1, x2, y1, y2, result = 0, count = 0;
    scanf("%d", &N);
    memset(UnionFind, -1, sizeof(UnionFind));
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &line[i].one.x, &line[i].one.y, &line[i].two.x, &line[i].two.y);
    }
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(lineIntersect(&line[i], &line[j])) {
                Union(j + 1, i + 1);
            }
        }
    }

    for(int i = 1; i < N + 1; i++) {
        if(UnionFind[i] < 0) {
            count++;
            result = min(UnionFind[i], result);
        }
    }
    printf("%d\n%d", count, result * -1);
}