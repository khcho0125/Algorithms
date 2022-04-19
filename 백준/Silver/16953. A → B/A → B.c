#include<stdio.h>
#include<stdlib.h>

#define ll long long

typedef struct Node {
    ll value;
    struct Node* link;
}node;

typedef struct Queue {
    node* front;
    node* back;
    int F;
    int B;
}Q;

Q queue;
ll M;
int find = 0, count = 1;

void bfs() {
    int pre = queue.B;
    ll x;
    while(queue.F != pre) {
        x = queue.front->value;
        queue.F++;
        if(x == M) {
            find = 1;
            return;
        }
        if(x * 2 <= M) {
            node* newNode = (node*)malloc(sizeof(node));
            newNode->link = NULL;
            newNode->value = x * 2;
            queue.back->link = newNode;
            queue.back = newNode;
            queue.B++;
        }
        if(x * 10 + 1 <= M) {
            node* newNode = (node*)malloc(sizeof(node));
            newNode->link = NULL;
            newNode->value = x * 10 + 1;
            queue.back->link = newNode;
            queue.back = newNode;
            queue.B++;
        }
        queue.front = queue.front->link;
    }
}

int main() {
    ll N;
    scanf("%lld %lld", &N, &M);
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = N;
    newNode->link = NULL;
    queue.back = newNode;
    queue.front = newNode;
    queue.B = 1;
    queue.F = 0;
    while(queue.F != queue.B && !find) {
        bfs();
        count++;
    }
    printf("%d", find ? count - 1 : -1);
}