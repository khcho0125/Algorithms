#include<stdio.h>

int color[1000][3] = {0,};

int min(int x, int y) {
    return x > y ? y : x;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);
        if(i != 0) {
            color[i][0] += min(color[i - 1][1], color[i - 1][2]);
            color[i][1] += min(color[i - 1][0], color[i - 1][2]);
            color[i][2] += min(color[i - 1][0], color[i - 1][1]);
        }
    }
    printf("%d", min(min(color[N - 1][0], color[N - 1][1]), color[N - 1][2]));
}