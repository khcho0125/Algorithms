#include<stdio.h>

#define INF 987654321
#define N_MAX 101

#define min(a, b) ((a) < (b) ? a : b)

int dist[N_MAX][N_MAX];

void floyd(int N) {
    for (int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int solution(int N) {
    floyd(N);

    int result, temp = INF;
    for (int i = 1, sum = 0; i <= N; i++, sum = 0) {
        for (int j = 1; j <= N; j++) {
            sum += dist[i][j];
        }
        
        if (sum < temp) {
            temp = sum;
            result = i;
        }
    }
    return result;
}

int main()
{
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dist[i][j] = (i == j ? 0 : INF);
        }
    }

    for(int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        dist[A][B] = dist[B][A] = 1;
    }

    printf("%d", solution(N));
}