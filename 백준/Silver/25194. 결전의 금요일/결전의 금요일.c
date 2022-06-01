#include<stdio.h>

#define MOD 7

int day = 1;

int main() {
    int N, W;
    scanf("%d", &N);
    for(int i = 0, newday = 0; i < N; i++, newday = 0) {
        scanf("%d", &W);
        W %= MOD;
        for(int j = 0; j < 7; j++) {
            if(day & (1 << j)) {
                newday |= (1 << ((j + W) % MOD));
            }
        }
        day |= newday;
    }

    printf(day & (1 << 4) ? "YES" : "NO");
}