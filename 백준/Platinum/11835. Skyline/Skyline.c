#include<stdio.h>

#define N_MAX 300
#define min_third(a, b, c) ((a) < (b) ? ((a) < (c) ? a : c) : ((b) < (c) ? b : c))
#define min(a, b) ((a) < (b) ? a : b)

int noodle[N_MAX];
int table[N_MAX];

int main() {
    int N, buy, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &noodle[i]);
        if(i) {
            table[i] = min(noodle[i - 1], noodle[i]);
            noodle[i - 1] -= table[i];
            noodle[i] -= table[i];

            result += table[i] * 2;

            buy = min(table[i - 1], noodle[i]);
            table[i - 1] -= buy;
            noodle[i] -= buy;

            result += buy * 2;
        }

        result += noodle[i] * 3;
    }

    for(int i = 1; i < N - 1; i++) {
        buy = min_third(table[i - 1], table[i], table[i + 1]);
        table[i - 1] -= buy;
        table[i] -= buy;
        table[i + 1] -= buy;

        result -= buy;
    }
    
    printf("%d", result);
}