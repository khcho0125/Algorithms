#include<stdio.h>

int main() {
    int N = 2000, M, result = -50;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &M);
        if(N > M) {
            N = M;
        }
    }
    result += N;
    scanf("%d %d", &N, &M);
    printf("%d", (N < M ? N : M) + result);
}
