#include<stdio.h>

int main() {
    int N, P, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &P);
        
        if(P & 1) result ^= ((P + 1) / 2);
        else result ^= (P / 2 - 1);
    }

    printf(result ? "koosaga" : "cubelover");
}