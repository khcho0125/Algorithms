#include<stdio.h>
#include<stdlib.h>

typedef struct number {
    int idx;
    struct number* link;
}num;

typedef struct Singer {
    int V;
    num* link;
    num* back;
}singer;

singer Order[1000];
int queue[1000] = {0,};
int front = 0, back = 0;

void sort(int N) {
    num* query = (num*)malloc(sizeof(num));
    for(int i = 0; i < N; i++) {
        if(!Order[i].V) {
            queue[back++] = i;
        }
    }
    while(front != back) {
        query = Order[queue[front++]].link;
        while(query != NULL) {
            Order[query->idx].V--;
            if(!Order[query->idx].V) {
                queue[back++] = query->idx;
            }
            query = query->link;
        }
    }
    if(back == N) {
        for(int i = 0; i < N; i++) {
            printf("%d\n", queue[i] + 1);
        }
    }
    else {
        printf("0");
    }
}

int main() {
    int N, M, K, O, A;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        Order[i].V = 0;
        Order[i].link = NULL;
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &K, &A);
        for(int j = 1; j < K; j++) {
            scanf("%d", &O);
            num* newNode = (num*)malloc(sizeof(num));
            newNode->idx = O - 1;
            newNode->link = NULL;
            Order[O - 1].V++;
            if(Order[A - 1].link == NULL) {
                Order[A - 1].link = newNode;
                Order[A - 1].back = newNode;
            }
            else {
                Order[A - 1].back->link = newNode;
                Order[A - 1].back = newNode;
            }
            A = O;
        }
    }
    sort(N);
}