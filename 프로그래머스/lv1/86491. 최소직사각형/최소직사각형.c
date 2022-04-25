#include <stdio.h>

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define swap(a, b) {int l = a; a = b; b = l;}

int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int Max = 0, Min = 0;
    for(int i = 0; i < sizes_rows; i++) {
        if(sizes[i][0] < sizes[i][1]) {
            swap(sizes[i][0], sizes[i][1]);
        }
        Max = max(Max, sizes[i][0]);
        Min = max(Min, sizes[i][1]);
    }
    return Max * Min;
}