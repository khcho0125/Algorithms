#include<stdio.h>

#define max(a, b) (a > b ? a : b)

int card[1001];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &card[i]);
        for(int j = 1; j < i; j++) {
            card[i] = max(card[i], card[j] + card[i - j]);
        }
    }

    printf("%d", card[N]);
}