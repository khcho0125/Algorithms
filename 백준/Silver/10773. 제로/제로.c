#include<stdio.h>
#include<stdlib.h>

int main() {

    int N, M, pre, result = 0;
    scanf("%d", &N);
    int* stack = (int*)malloc(sizeof(int) * N);
    for(int i = 0, pre = 0; i < N; i++) {
        scanf("%d", &M);
        if(!M) {
            pre--;
            result -= stack[pre];
            stack[pre] = 0;
        } else {
            stack[pre] = M;
            result += M;
            pre++;
        }
    }
    printf("%d", result);
    
}