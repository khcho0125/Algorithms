#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define MAX 100000

typedef struct Line {
    ll a, b;
    double s;
}Line;

ll dp[MAX] = {0,};
int a[MAX];
int b[MAX];
Line* F[MAX];
int temp = 0;

double cross(Line* a, Line* b) {
    return (b->b - a->b) / (a->a - b->a);
}

int lowerBound(int idx) {
    int low = 0, high = temp - 1;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(a[idx] < F[mid]->s) high = mid;
        else low = mid;
    }
    return low;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }

    for(int i = 1; i < N; i++) {
        Line* s = (Line*)malloc(sizeof(Line));
        s->a = b[i - 1];
        s->b = dp[i - 1];
        s->s = 0;
        while(temp > 0) {
            s->s = cross(F[temp - 1], s);
            
            if(F[temp - 1]->s < s->s) break;
            
            --temp;
        }
        F[temp++] = s;

        int fpos = temp - 1;
        if(a[i] < F[fpos]->s) fpos = lowerBound(i);

        dp[i] = F[fpos]->a * a[i] + F[fpos]->b;
    }

    printf("%lld", dp[N - 1]);
}