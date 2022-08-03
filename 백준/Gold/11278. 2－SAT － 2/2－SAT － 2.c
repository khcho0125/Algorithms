#include<stdio.h>

typedef struct Pair {
    int first, second;
}pair;

pair clause[100];

int compare(int bit, int idx) {

    int one = clause[idx].first < 0 ? !(bit & 1 << (clause[idx].first * -1 - 1)) : bit & 1 << (clause[idx].first - 1);
    int two = clause[idx].second < 0 ? !(bit & 1 << (clause[idx].second * -1 - 1)) : bit & 1 << (clause[idx].second - 1);

    return one | two;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &clause[i].first, &clause[i].second);
    }

    for(int i = 0, idx = 0; i < 1 << 20; i++, idx = 0) {
        for(; compare(i, idx) && idx != M; idx++);

        if(idx == M) {
            printf("1\n");
            for(int c = 0; c < N; c++) {
                printf("%d ", (i & 1 << c) != 0);
            }
            return 0;
        }
    }
    
    printf("0");
}