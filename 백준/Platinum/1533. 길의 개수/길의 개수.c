#include<stdio.h>
#include<string.h>

#define MOD 1000003
#define ll long long

ll dp[50][50] = {0,};
ll map[50][50] = {0,};
ll temp[50][50];
int N;

void operator(ll (*A1)[50], ll (*A2)[50]) {
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            temp[x][y] = 0;
            for(int i = 0; i < N; i++) {
                temp[x][y] += A1[x][i] * A2[i][y];
                temp[x][y] %= MOD;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        memcpy(A1[i], temp[i], sizeof(A1[i]));
    }
}

int main() {
    int S, E, T, value;
    scanf("%d %d %d %d", &N, &S, &E, &T);
    N *= 5;
    for(int i = 0; i < N; i++) {
        dp[i][i] = 1;
    }

    for(int i = 0; i < N; i += 5) {
        for(int j = 0; j < N; j += 5) {
            scanf("%1d", &value);
            if(value) map[i][j + value - 1] = 1;
        }
        for(int j = 1; j < 5; j++) {
            map[i + j][i + j - 1] = 1;
        }
    }

    while(T) {
        if(T & 1) {
            operator(dp, map);
        }
        operator(map, map);
        T = T >> 1;
    }

    printf("%lld", dp[(S - 1) * 5][(E - 1) * 5]);
}