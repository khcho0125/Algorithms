#include<stdio.h>

int map[50][50];
int ans[50][50];

void reverse(int x, int y) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            map[x + i][y + j] = !map[x + i][y + j];
        }
    }
}

int main() {
    int N, M, result = 0, i, j;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            scanf("%1d", &ans[i][j]);
        }
    }

    if(N < 3 || M < 3) {
        for(i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
                if(map[i][j] != ans[i][j]) {
                    printf("-1");
                    return 0;
                }
            }
        }
        printf("0");
        return 0;
    }

    for(i = 0; i < N - 2; i++) {
        for(j = 0; j < M - 2; j++) {
            if(map[i][j] != ans[i][j]) {
                reverse(i, j);
                result++;
            }
        }
        for(; j < M; j++) {
            if(map[i][j] != ans[i][j]) {
                printf("-1");
                return 0;
            }
        }
    }
    for(; i < N; i++) {
        for(j = 0; j < M; j++) {
            if(map[i][j] != ans[i][j]) {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", result);
}