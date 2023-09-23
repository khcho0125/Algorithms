#include<stdio.h>

int main() {
    int N, P, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &P);
        result ^= P;
    }

    printf(result ? "koosaga" : "cubelover");
}