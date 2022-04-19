#include <stdio.h>

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    for(int i = 5; i <= N; i*=5) {
        sum += N / i;
    }
    printf("%d", sum);
}