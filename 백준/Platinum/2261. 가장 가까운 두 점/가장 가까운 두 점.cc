#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<set>

using namespace std;

#define min(a, b) (a < b ? a : b)
#define pow(a) ((a) * (a))
#define INF 10000

typedef struct Point {
    int x;
    int y;

    bool operator < (const Point& p) const {
        if(y != p.y) {
            return y < p.y;
        }
        return x < p.x;
    }
}Point;

Point P[100000];

bool cmpX(const Point& a, const Point& b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int Pt(Point a, Point b) {
    return pow(b.x - a.x) + pow(b.y - a.y);
}

int main() {
    int N, ans, d, idx = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &P[i].x, &P[i].y);
    }

    sort(P, P + N, cmpX);

    set<Point> range = {P[0], P[1]};
    ans = Pt(P[0], P[1]);

    for(int i = 2; i < N; i++) {
        while(idx < i && pow(P[idx].x - P[i].x) > ans) {
            range.erase(P[idx]);
            idx++;
        }

        d = (int)(sqrt((double)ans) + 1);
        auto end = range.upper_bound({INF, P[i].y + d});
        auto start = range.lower_bound({-INF, P[i].y - d});
        for(; start != end; start++) {
            d = Pt(P[i], *start);
            if(d < ans) {
                ans = d;
            }
        }
        range.insert(P[i]);
    }

    printf("%d", ans);
}