#include<stdio.h>

char map[1003][1003];
int result[1003][1003] = {0,};
int x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int y[8] = {0, 1, -1, 1, -1, 0, 1, -1};

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] <= '9' && map[i][j] >= '1') {
                for(int num = 0; num < 8; num++) {
                    result[i + x[num]][j + y[num]] += map[i][j] - '0';
                }
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j] <= '9' && map[i][j] >= '1') {
                printf("*");
            }
            else if(result[i][j] >= 10) {
                printf("M");
            }
            else {
                printf("%d", result[i][j]);
            }
        }
        printf("\n");
    }
}