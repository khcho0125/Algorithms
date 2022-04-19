#include<stdio.h>
#include<string.h>

#define max(a, b) ((a > b) ? a : b)

int cache[1000] = {0,};
int Delay[1000] = {0,};
int V[1000] = {0,};
int graf[1000][1000];
int Queue[1000];
int front = 0, back = 0, result = 0;

void sort(int N, int W) {
    for(int i = 0; i < N; i++) {
        if(!V[i]) {
            Queue[back++] = i;
            V[i] = 1;
        }
    }
    int idx, D;
    while(front != back) {
        idx = Queue[front++];
        if(idx == W) {
            result = max(result, Delay[idx] + cache[idx]);
        }
        for(int i = 0; i < N; i++) {
            if(graf[idx][i]) {
                V[i]--;
                cache[i] = max(cache[i], Delay[idx] + cache[idx]);
            }
        }
        for(int i = 0; i < N; i++) {
            if(!V[i]) {
                Queue[back++] = i;
                V[i] = 1;
            }
        }
    }
}

int main() {
    int T, N, K, X, Y, W;
    scanf("%d", &T);
    for(int TC = 0; TC < T; TC++, result = 0, front = 0, back = 0) {
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++) {
            scanf("%d", &Delay[i]);
            V[i] = 0;
        }
        for(int i = 0; i < K; i++) {
            scanf("%d %d", &X, &Y);
            V[Y - 1]++;
            graf[X - 1][Y - 1] = 1;
        }
        scanf("%d", &W);
        sort(N, W - 1);
        printf("%d\n", result);
        memset(graf, 0, sizeof(graf));
        memset(cache, 0, sizeof(cache));
    }
}