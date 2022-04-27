#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 10001 
#define min(a, b) ((a) < (b) ? a : b)

int map[101][101];

int func(int x1, int y1, int x2, int y2) {
    int Min = INF;
    int temp = INF, memory = 0;
    for(int i = y1; i < y2; i++) {
        memory = map[x1][i];
        map[x1][i] = temp;
        temp = memory;
        Min = min(Min, memory);
    }

    for(int i = x1; i < x2; i++) {
        memory = map[i][y2];
        map[i][y2] = temp;
        temp = memory;
        Min = min(Min, memory);
    }

    for(int i = y2; y1 < i; i--) {
        memory = map[x2][i];
        map[x2][i] = temp;
        temp = memory;
        Min = min(Min, memory);
    }

    for(int i = x2; x1 <= i; i--) {
        memory = map[i][y1];
        map[i][y1] = temp;
        temp = memory;
        Min = min(Min, memory);
    }

    return Min;
}

int* solution(int rows, int columns, int **queries, size_t queries_row_len, size_t queries_col_len) {
    int* answer = (int*)malloc(sizeof(int) * (queries_row_len + 1));

    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            map[i][j] = (i - 1) * columns + j;
        }
    }

    for(int i = 0; i < queries_row_len; i++) {
        answer[i] = func(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
    }

    return answer;
}