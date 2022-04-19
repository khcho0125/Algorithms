#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int idx;
    struct node* link;
}node;

typedef struct V {
    int v;
    node* link; 
    node* back;
}E;

E student[32000];
int queue[32000] = {0,};
int back = 0, front = 0;

void sort(int N) {
    node* query = (node*)malloc(sizeof(node));
    for(int i = 0; i < N; i++) {
        if(!student[i].v) {
            queue[back++] = i;
        }
    }
    while(front != back) {
        printf("%d ", queue[front] + 1);
        query = student[queue[front]].link;
        while(query != NULL) {
            student[query->idx].v--;
            if(!student[query->idx].v) {
                queue[back++] = query->idx;
            }
            query = query->link;
        }
        front++;
    }
}

int main() {
    int N, M, s, e;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        student[i].link = NULL;
        student[i].v = 0;
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &s, &e);
        node* newNode = (node*)malloc(sizeof(node));
        newNode->idx = e - 1;
        newNode->link = NULL;
        student[e - 1].v++;
        if(student[s - 1].link == NULL) {
            student[s - 1].link = newNode;
            student[s - 1].back = newNode;
        }
        else {
            student[s - 1].back->link = newNode;
            student[s - 1].back = newNode;
        }
    }
    sort(N);
}