#include<stdio.h>
#include<math.h>

#define min(a, b) ((a > b) ? b : a)
#define ll long long

typedef struct vector {
    int first;
    int second;
}vector;

vector V[20] = {0,};

double tracking(int idx, int sum, int sub, int Limit, ll x, ll y) {
    if(idx == Limit) {
        return sqrt((double)(x * x) + (double)(y * y));
    }
    double m = 1e10, t;
    if(sum < Limit / 2) {
        t = tracking(idx + 1, sum + 1, sub, Limit, x + V[idx].first, y + V[idx].second);
        m = min(m, t);
    }
    if(sub < Limit / 2) {
        t = tracking(idx + 1, sum, sub + 1, Limit, x - V[idx].first, y - V[idx].second);
        m = min(m, t);
    }
    return m;
}

int main() {
    int N, T; 
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            scanf("%d %d", &V[i].first, &V[i].second);
        }
        printf("%.8lf\n", tracking(0, 0, 0, N, 0, 0));
    }
}