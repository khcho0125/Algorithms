#include<stdio.h>

int bino_f(int n, int r) {
    if(r > n) {
        return 0;
    }

    if(r == 0 || r == n) {
        return 1;
    }

    return bino_f(n - 1, r) + bino_f(n - 1, r - 1);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%d", bino_f(N, M));
}