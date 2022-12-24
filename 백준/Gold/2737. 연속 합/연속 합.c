#include<stdio.h>

int main() {
    int T, N;
    scanf("%d", &T);
    for(int i = 0, count = 0; i < T; i++, count = 0) {
        scanf("%d", &N);

        for(int k = 3; k / 2 < N / k; k += 2) {
            count += !(N % k);
        }

        for(int k = 2; k / 2 < (N + k / 2) / k; k += 2) {
            count += !((N + k / 2) % k);
        }

        printf("%d\n", count);
    }
}