#include<stdio.h>
#include<string.h>

#define max(a, b) (((a) > (b)) ? a : b)

int N;
long result = 0;

void tracking(long map[][20], int turn) {
    if(turn == 5) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                result = max(result, map[i][j]);
            }
        }
        return;
    }
    long newMap[20][20] = {0,};
    int used[20][20] = {0,};
    int temp;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j]) {
                temp = i;
                while(temp != 0) {
                    if(newMap[temp - 1][j]) {
                        if(newMap[temp - 1][j] == map[i][j] && !used[temp - 1][j]) {
                            temp--;
                            used[temp][j] = 1;
                        }
                        break;
                    }
                    temp--;
                }
                newMap[temp][j] += map[i][j];
            }
        }
    }
    tracking(newMap, turn + 1);

    memset(newMap, 0, sizeof(newMap));
    memset(used, 0, sizeof(used));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[j][i]) {
                temp = i;
                while(temp != 0) {
                    if(newMap[j][temp - 1]) {
                        if(newMap[j][temp - 1] == map[j][i] && !used[j][temp - 1]) {
                            temp--;
                            used[j][temp] = 1;
                        }
                        break;
                    }
                    temp--;
                }
                newMap[j][temp] += map[j][i];
            }
        }
    }
    tracking(newMap, turn + 1);

    memset(newMap, 0, sizeof(newMap));
    memset(used, 0, sizeof(used));
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            if(map[j][i]) {
                temp = i;
                while(temp + 1 != N) {
                    if(newMap[j][temp + 1]) {
                        if(newMap[j][temp + 1] == map[j][i] && !used[j][temp + 1]) {
                            temp++;
                            used[j][temp] = 1;
                        }
                        break;
                    }
                    temp++;
                }
                newMap[j][temp] += map[j][i];
            }
        }
    }
    tracking(newMap, turn + 1);

    memset(newMap, 0, sizeof(newMap));
    memset(used, 0, sizeof(used));
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            if(map[i][j]) {
                temp = i;
                while(temp + 1 != N) {
                    if(newMap[temp + 1][j]) {
                        if(newMap[temp + 1][j] == map[i][j] && !used[temp + 1][j]) {
                            temp++;
                            used[temp][j] = 1;
                        }
                        break;
                    }
                    temp++;
                }
                newMap[temp][j] += map[i][j];
            }
        }
    }
    tracking(newMap, turn + 1);
}

int main() {
    long map[20][20] = {0,};
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%ld", &map[i][j]);
        }
    }
    tracking(map, 0);
    printf("%ld", result);
}