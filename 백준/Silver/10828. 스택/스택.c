#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int N, M, pre = 1;
    char str[6];
    scanf("%d", &N);
    int* stack = (int*)malloc(sizeof(int) * (N + 1));
    stack[0] = -1;
    for(int i = 0; i < N; i++) {
        scanf("%s", str);
        if(!strcmp(str, "push")){
            scanf("%d", &M);
            stack[pre] = M;
            pre++;
        }
        else if(!strcmp(str, "pop")) {
            printf("%d\n", stack[pre - 1]);
            if(pre != 1) {
                pre--;
            }
        }
        else if(!strcmp(str, "top")) {
            printf("%d\n", stack[pre - 1]);
        }
        else if(!strcmp(str, "size")) {
            printf("%d\n", pre - 1);
        }
        else if(!strcmp(str, "empty")) {
            printf("%d\n", stack[pre - 1] == -1);
        }
    }
}