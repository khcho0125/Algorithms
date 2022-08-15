#include<stdio.h>

#define INF 987654321
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) ((a) < 0 ? (a) * -1 : a)

int map[201][201];
int maximum[201][201] = {0,};

void floyd(int N) {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i != j) map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
            }
        }
    }
}

int main() {
    int M, N, S, E, L, temp;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            map[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &S, &E, &L);
        map[S][E] = map[E][S] = min(map[E][S], L);
        maximum[S][E] = maximum[E][S] = max(maximum[E][S], L);
    }

    floyd(N);

    for(int i = 1; i <= N; i++) {
        map[i][i] = 0;
    }

    double remain, all, result = INF;
    for(int s = 1; s <= N; s++) {
        remain = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= i; j++) {
                if(maximum[i][j] != 0) {
                    all = max(map[s][i], map[s][j]);
                    temp = abs(map[s][i] - map[s][j]);
                    remain = max(all + ((double)maximum[i][j] - temp) / 2, remain);
                }
            }
        }
        result = min(remain, result);
    }

    printf("%.1f", result);
}