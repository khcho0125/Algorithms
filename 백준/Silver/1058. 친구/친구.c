#include<stdio.h>

#define max(a, b) (a > b ? a : b)

int map[50][50] = {0,};
int sum[50] = {0,};
int N;

void solve(int idx) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i != j && map[idx][i] == 1 && map[idx][j] == 1 && !map[i][j]) {
                map[i][j] = 2;
                map[j][i] = 2;
                sum[i]++;
                sum[j]++;
            }
        }
    }
}

int main() {
    int result = 0;
    char str;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf(" %c", &str);
            map[i][j] = (str == 'Y');
            sum[i] += map[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        solve(i);
    }

    for(int i = 0; i < N; i++) {
        result = max(result, sum[i]);
    }

    printf("%d", result);
}