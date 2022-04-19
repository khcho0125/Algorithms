#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int N, M, front, back;
    char str[6];
    scanf("%d", &N);
    int* queue = (int*)malloc(sizeof(int) * N);
    for(int i = 0, front = 0, back = 0; i < N; i++) {
        scanf("%s", str);
        if(!strcmp(str, "push")) {
            scanf("%d", &M);
            queue[back] = M;
            back++;
        }
        else if(!strcmp(str, "pop")) {
            if(front == back)
                printf("-1\n");
            else {
                printf("%d\n", queue[front]);
                front++;
            }
        }
        else if(!strcmp(str, "front")) {
            if(front == back)
                printf("-1\n");
            else
                printf("%d\n", queue[front]);
        }
        else if(!strcmp(str, "back")) {
            if(back == front)
                printf("-1\n");
            else 
                printf("%d\n", queue[back - 1]);
        }
        else if(!strcmp(str, "size"))
            printf("%d\n", back - front);
        else if(!strcmp(str, "empty")) {
            printf("%d\n", back == front);
        }
    }
}