#include<stdio.h>

#define abs(a) ((a) < 0 ? (a) * -1 : a)
#define INF 987654321
#define min(a, b) (a < b ? a : b)
#define ll long long

int map[20][20];

int solve(ll bit, int N) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i != j ) {
                if((bit & 1LL << i) && (bit & 1LL << j)) sum += map[i][j];
                if((~bit & 1LL << i) && (~bit & 1LL << j)) sum -= map[i][j];
            }
        }
    }
    return abs(sum);
}

int main() {
    int N, result = INF, ret;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(ll i = 1; i < (1LL << N); i++) {
        ret = solve(i, N);
        result = min(result, ret);
    }

    printf("%d", result);
}