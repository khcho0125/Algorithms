#include<stdio.h>
#include<string.h>

#define TRUE 1
#define N_MAX 100
#define max(a, b) ((a) > (b) ? a : b)
#define min(a, b) ((a) < (b) ? a : b)

int arr[N_MAX];

int diff(int n, int* maximum, int* minimum) {
    *maximum = arr[0], *minimum = arr[0];
    for(int i = 1; i < n; i++) {
        *maximum = max(*maximum, arr[i]);
        *minimum = min(*minimum, arr[i]);
    }

    return *maximum - *minimum;
}

void increase(int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) arr[i]++;
    }
}

int table[N_MAX][N_MAX];
int balTable[N_MAX][N_MAX];
int axis[2][4] = {
    {1, 0, -1, 0},
    {0, 1, 0, -1}
};

void balance(int xs, int xe, int ys, int ye) {
    memset(balTable, 0, sizeof(balTable));
    for(int x = xs; x < xe; x++) {
        for(int y = ys; y < ye; y++) {

            if(table[x][y] == 0) break;

            balTable[x - xs][y - ys] += table[x][y];

            for(int k = 0; k < 4; k++) {
                int i = x + axis[0][k];
                int j = y + axis[1][k];

                if(xs > i || i > xe || ys > j || j > ye || table[i][j] == 0) continue;

                int d = (table[x][y] - table[i][j]) / 5;
                balTable[i - xs][j - ys] += d;
            }
        }
    }
}

void linear(int xs, int xe, int ys, int ye) {
    int idx = 0;
    for(int i = xs; i < xe; i++) {
        for(int j = ys; j < ye; j++) {
            if(balTable[i][j] != 0) arr[idx++] = balTable[i][j];
        }
    }
}

void snail(int n) {
    memset(table, 0, sizeof(table));
    for(int i = 0; i < n; i++) table[i][0] = arr[i];

    int k = 0, x = 0, y = 0;
    while(TRUE) {
        if(n - (k + 1) < y + 1) break;
        for(int i = 0; i <= x; i++) {
            for(int j = 0; j <= y; j++) {
                table[k + j + 1][1 + i] = table[k - i][j];
            }
        }
        k += y + 1;
        ++y;

        if(n - (k + 1) < y + 1) break;
        for(int i = 0; i <= x; i++) {
            for(int j = 0; j <= y; j++) {
                table[k + j + 1][1 + i] = table[k - i][j];
            }
        }
        k += y + 1;
        ++x;
    }

    balance(k - x, n, 0, y + 1);
    linear(0, n - (k - x), 0, y + 1);
}

void divide(int N) {
    memset(table, 0, sizeof(table));
    for(int i = 0; i < N; i++) table[i][0] = arr[i];

    for(int i = 0; i < N / 2; i++) table[N - i - 1][1] = table[i][0];
    for(int i = 0; i < N / 4; i++) {
        for(int j = 0; j < 2; j++) {
            table[N - i - 1][3 - j] = table[N / 2 + i][j];
        }
    }

    balance(N - N / 4, N, 0, 4);
    linear(0, N / 4, 0, 4);
}

int main() {
    int N, K, result;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int maximum, minimum;
    for(result = 0; diff(N, &maximum, &minimum) > K; result++) {
        increase(N, minimum);
        snail(N);
        divide(N);
    }

    printf("%d", result);
}