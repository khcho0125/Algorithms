#include<stdio.h>

#define TRUE 1
#define N_MAX 3000001
#define GRUNDY_MAX 16

int grundy[N_MAX];
int mex[GRUNDY_MAX];

void g(int x) {
    int a = 1, b = 1, t;
    while(b <= x) {
        mex[grundy[x - b]] = x;
        t = b;
        b += a;
        a = t;
    }
    for(int i = 0; TRUE; i++) if(mex[i] != x) {
        grundy[x] = i;
        return;
    }
}

int main() {
    for(int i = 1; i < N_MAX; g(i++));

    int N, P, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &P);
        result ^= grundy[P];
    }
    printf(result ? "koosaga" : "cubelover");
}