#include<stdio.h>

int Queue[100001] = {0,};
int back = 0, front = 0;
int visit[100001] = {0,};
int K;

void find(int X) {
    if(X != 100000 && (!visit[X + 1] || visit[X] + 1 < visit[X + 1])) {
        Queue[back++] = X + 1;
        visit[X + 1] = visit[X] + 1;
    }
    if(X != 0 && (!visit[X - 1] || visit[X] + 1 < visit[X + 1])) {
        Queue[back++] = X - 1;
        visit[X - 1] = visit[X] + 1;
    }
    if(X != 0 && X < K && X * 2 <= 100000 && (!visit[X * 2] || visit[X] < visit[X * 2])) {
        visit[X * 2] = visit[X];
        find(X * 2);
    }
}

void bfs() {
    int pre = back;
    while(front != pre) {
        find(Queue[front++]);
    }
}

int main() {
    int N;
    scanf("%d %d", &N, &K);
    Queue[back++] = N;
    visit[N] = 1;
    while(front != back) {
        bfs();
    }
    printf("%d", visit[K] - 1);
}