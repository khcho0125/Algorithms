#include<stdio.h>

typedef struct dp {
    int turn;
    int next;
}dp;

dp list[1000001] = {0,};
int queue[1000001];
int front = 0, back = 0;

void BFS(int N) {
    int x;
    while(front != back && !list[N].turn) {
        
        x = queue[front++];
        if(x * 3 <= N && !list[x * 3].turn) {
            queue[back++] = x * 3;
            list[x * 3].next = x;
            list[x * 3].turn = list[x].turn + 1;
        }

        if(x * 2 <= N && !list[x * 2].turn) {
            queue[back++] = x * 2;
            list[x * 2].next = x;
            list[x * 2].turn = list[x].turn + 1;
        }

        if(x + 1 <= N && !list[x + 1].turn) {
            queue[back++] = x + 1;
            list[x + 1].next = x;
            list[x + 1].turn = list[x].turn + 1;
        }
    }
}

void tracking(int N) {
    printf("%d ", N);
    if(list[N].next) {
        tracking(list[N].next);
    }
}

int main() {
    int N; 
    scanf("%d", &N);
    queue[back++] = 1;
    BFS(N);
    printf("%d\n", list[N].turn);
    tracking(N);
}