#include<stdio.h>
#include<string.h>

#define MOD 10007

int comb[53][53] = {0,};

void combination() {
    for(int i = 0; i < 53; i++) {
        comb[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
}

int figure(int N) {
    int result = 0;
    for(int set = 1; set <= N / 4; set++) {
        result = (result + (set % 2 ? 1 : -1) * (comb[13][set] * comb[52 - set * 4][N - set * 4] % MOD) + MOD) % MOD;
    }
    return result;
}

int main() {
    int N;
    combination();
    scanf("%d", &N);
    printf("%d", figure(N));
}