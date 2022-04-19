#include<stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if(!N && !M) {
        printf("Not a moose");
    } else if(N == M) {
        printf("Even %d", N + M);
    } else {
        printf("Odd %d", N > M ? N * 2 : M * 2);
    }
}