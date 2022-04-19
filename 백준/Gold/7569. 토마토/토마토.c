#include<stdio.h>

typedef struct xyz {
    int H;
    int N;
    int M;
}xyz;

int back = 0, front = 0, result = 0, sum = 0;
int tomato[100][100][100] = {0,};
int visit[100][100][100] = {0,};
xyz queue[1000000] = {0,};


void func(int Hlim, int Mlim, int Nlim) {
    int H, M, N, temp = back;
    while(front < temp) {
        H = queue[front].H;
        M = queue[front].M;
        N = queue[front++].N;

        if((H != Hlim) && tomato[H + 1][N][M] == 0 && !visit[H + 1][N][M]) {
            queue[back].H = H + 1;
            queue[back].M = M;
            queue[back++].N = N;
            visit[H + 1][N][M] = 1;
            sum--;
        }

        if((H != 0) && tomato[H - 1][N][M] == 0 && !visit[H - 1][N][M]) {
            queue[back].H = H - 1;
            queue[back].M = M;
            queue[back++].N = N;
            visit[H - 1][N][M] = 1;
            sum--;
        }

        if((N != Nlim) && tomato[H][N + 1][M] == 0 && !visit[H][N + 1][M]) {
            queue[back].H = H;
            queue[back].M = M;
            queue[back++].N = N + 1;
            visit[H][N + 1][M] = 1;
            sum--;
        }

        if((N != 0) && tomato[H][N - 1][M] == 0 && !visit[H][N - 1][M]) {
            queue[back].H = H;
            queue[back].M = M;
            queue[back++].N = N - 1;
            visit[H][N - 1][M] = 1;
            sum--;
        }

        if((M != Mlim) && tomato[H][N][M + 1] == 0 && !visit[H][N][M + 1]) {
            queue[back].H = H;
            queue[back].M = M + 1;
            queue[back++].N = N;
            visit[H][N][M + 1] = 1;
            sum--;
        }

        if((M != 0) && tomato[H][N][M - 1] == 0 && !visit[H][N][M - 1]) {
            queue[back].H = H;
            queue[back].M = M - 1;
            queue[back++].N = N;
            visit[H][N][M - 1] = 1;
            sum--;
        }
    }
}

int main() {
    int N, M, H;
    scanf("%d %d %d", &M, &N, &H);
    sum = H * M * N;
    for(int h = 0; h < H; h++) {
        for(int n = 0; n < N; n++) {
            for(int m = 0; m < M; m++) {
                scanf("%d", &tomato[h][n][m]);
                if(tomato[h][n][m] == 1) {
                    visit[h][n][m] = 1;
                    queue[back].H = h;
                    queue[back].M = m;
                    queue[back++].N = n;
                }
                if(tomato[h][n][m] != 0) {
                    sum--;
                }
            }
        }
    }
    while(sum && front < back) {
        result++;
        func(H - 1, M - 1, N - 1);
    }
    if(sum) {
        printf("-1");
    } else {
        printf("%d", result);
    }
}