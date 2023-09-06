#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 100
#define M_MAX 100
#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Point {
    int x, y;
}P;

P black[N_MAX];
P white[N_MAX];

P bCH[N_MAX];
P wCH[N_MAX];
int bp, wp;

P standard;

int compare(const void* a, const void* b) {
    P A = *(P*)a;
    P B = *(P*)b;

    if (A.y != B.y) return A.y > B.y ? 1 : -1;
    return A.x > B.x ? 1 : -1;
}

int dist(const P* a, const P* b) {
    return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

int ccw(const P* a, const P* b, const P* c) {
    int direct = (b->x - a->x) * (c->y - a->y) - (c->x - a->x) * (b->y - a->y);
    return direct < 0 ? -1 : direct > 0;
}

int vector_ccw(const P* a, const P* b) {
    int direct = a->x * b->y - b->x * a->y;
    return direct < 0 ? -1 : direct > 0;
}

P vector(const P* a, const P* b) {
    return (P){.x = b->x - a->x, b->y - a->y};
}

int clock(const void* a, const void* b) {
    P* A = (P*)a;
    P* B = (P*)b;

    int direct = ccw(&standard, A, B);

    if(direct == 0) return dist(&standard, A) > dist(&standard, B) ? 1 : -1;

    return -direct;
}

int buildConvexHull(P* p_set, int p_set_size, P* CH_set) {
    if(p_set_size <= 2) {
        for(int i = 0; i < p_set_size; i++) {
            CH_set[i] = p_set[i];
        }
        return p_set_size;
    }

    qsort(p_set, p_set_size, sizeof(P), compare);

    standard = p_set[0];

    qsort(p_set, p_set_size, sizeof(P), clock);

    CH_set[0] = p_set[0];
    CH_set[1] = p_set[1];

    int CH_size = 2;
    for(int i = 2; i < p_set_size; i++) {
        do {
            int direct = ccw(&CH_set[CH_size - 2], &CH_set[CH_size - 1], &p_set[i]);

            if (direct > 0) break;
        } while(--CH_size > 1);

        CH_set[CH_size++] = p_set[i];
    }

    return CH_size;
}

bool onSegment(const P* a, const P* b, const P* c) {
    return c->x >= min(a->x, b->x) && c->x <= max(a->x, b->x) && c->y >= min(a->y, b->y) && c->y <= max(a->y, b->y);
}

bool intersect(const P* a1, const P* a2, const P* b1, const P* b2) {
    int d1, d2, d3, d4;
    d1 = ccw(a1, a2, b1);
    d2 = ccw(a1, a2, b2);
    d3 = ccw(b1, b2, a1);
    d4 = ccw(b1, b2, a2);

    if(!d1 && onSegment(a1, a2, b1)) return true;
    if(!d2 && onSegment(a1, a2, b2)) return true;
    if(!d3 && onSegment(b1, b2, a1)) return true;
    if(!d4 && onSegment(b1, b2, a2)) return true;

    return d1 * d2 < 0 && d3 * d4 < 0;
}

bool inConvexPolygon(P* CH, int CH_size, P* p) {
    if(CH_size <= 2) return false;

    P lv = vector(&CH[0], &CH[CH_size - 1]);
    P rv = vector(&CH[0], &CH[1]);
    P pv = vector(&CH[0], p);

    if(vector_ccw(&lv, &pv) > 0) return false;
    if(vector_ccw(&rv, &pv) < 0) return false;

    int r = 1, l = CH_size - 1, m;
    while(r + 1 < l) {
        m = (r + l) / 2;

        P mv = vector(&CH[0], &CH[m]);
        if(vector_ccw(&mv, &pv) > 0) r = m;
        else l = m;
    }

    return ccw(&CH[r], &CH[r + 1], p) > 0;
}

bool classification() {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &black[i].x, &black[i].y);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &white[i].x, &white[i].y);
    }

    bp = buildConvexHull(black, n, bCH);
    wp = buildConvexHull(white, m, wCH);

    for(int i = 0; i < n; i++) {
        if(inConvexPolygon(wCH, wp, &black[i])) return false;
    }

    for(int i = 0; i < m; i++) {
        if(inConvexPolygon(bCH, bp, &white[i])) return false;
    }

    for(int i = 0; i < bp; i++) {
        for(int j = 0; j < wp; j++) {
            if(intersect(&bCH[i], &bCH[(i + 1) % bp], &wCH[j], &wCH[(j + 1) % wp])) return false;
        }
    }

    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        printf(classification() ? "YES\n" : "NO\n");
    }
}