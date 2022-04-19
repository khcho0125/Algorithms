#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int N, front, back;
    char str[11];
    scanf("%d", &N);
    int* queue = (int*)malloc(sizeof(int) * N * 2);
    for(int i = 0, front = N - 1, back = N; i < N; i++) {
        scanf("%s", str);
        if(!strcmp(str, "push_back")) {
            scanf("%d", &queue[back]);
            back++;
        }
        else if(!strcmp(str, "push_front")) {
            scanf("%d", &queue[front]);
            front--;
        }
        else if(!strcmp(str, "pop_back")) {
            if(front == back - 1) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[back - 1]);
                back--;
            }
        }
        else if(!strcmp(str, "pop_front")) {
            if(front == back - 1) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[front + 1]);
                front++;
            }
        }
        else if(!strcmp(str, "front")) {
            if(front == back - 1) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[front + 1]);
            }
        }
        else if(!strcmp(str, "back")) {
            if(front == back - 1) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[back - 1]);
            }
        }
        else if(!strcmp(str, "size"))
            printf("%d\n", back - front - 1);
        else if(!strcmp(str, "empty")) {
            printf("%d\n", back - 1 == front);
        }
    }
}