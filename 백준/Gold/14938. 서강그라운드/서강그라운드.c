#include<stdio.h>
#include<stdlib.h>

#define max(a, b) ((a > b) ? a : b)
#define INF 1501

int Route[100][100] = {0,};
int item[100];

void Floyd(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(Route[j][i] + Route[i][k] < Route[j][k]) {
                    Route[j][k] = Route[j][i] + Route[i][k];
                }
            }
        }
    }
}

int main() {
    int n, m, r, a, b, l, result = 0, sum;
    scanf("%d %d %d", &n, &m, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &item[i]);
        for(int j = 0; j < n; j++) {
            Route[i][j] = INF;
        }
    }
    for(int i = 0; i < r; i++) {
        scanf("%d %d %d", &a, &b, &l);
        Route[a - 1][b - 1] = l;
        Route[b - 1][a - 1] = l;
    }
    Floyd(n);
    for(int i = 0; i < n; i++) {
        sum = item[i];
        for(int j = 0; j < n; j++) {
            if(i != j && Route[i][j] <= m) {
                sum += item[j];
            }
        }
        result = max(sum, result);
    }
    printf("%d", result);
}