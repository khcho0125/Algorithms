#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define MAX 100000

typedef struct Line {
    ll a;
    ll b;
    double s;
}Line;

ll dp[MAX] = {0,};
ll a[MAX];
ll b[MAX];
Line* F[MAX];
int temp = 0;

double cross(Line* a, Line* b) {
    return (-1) * ((a->b - b->b) / (a->a - b->a));
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%lld", &b[i]);
    }

    int fpos = 0;
    for(int i = 1; i < N; i++) {
        Line* s = (Line*)malloc(sizeof(Line));
        s->a = b[i - 1];
        s->b = dp[i - 1];
        while(temp > 0) {
            s->s = cross(F[temp - 1], s);
            
            if(F[temp - 1]->s < s->s) break;
            
            if(--temp == fpos) fpos--; 
        }
        F[temp++] = s;

        while(fpos + 1 < temp && F[fpos + 1]->s < a[i]) {
            fpos++;
        }

        dp[i] = F[fpos]->a * a[i] + F[fpos]->b;
    }

    printf("%lld", dp[N - 1]);
}