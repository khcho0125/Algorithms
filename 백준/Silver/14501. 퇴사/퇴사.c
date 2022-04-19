#include<stdio.h>

#define max(a, b)((a > b) ? a : b)

typedef struct Day {
    int T, P;
}D;

D day[15];

int main() {
    int N, MAX, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &day[i].T, &day[i].P);
        MAX = 0;
        for(int j = 0; j < i; j++) {
            if(i - j >= day[j].T) {
                MAX = max(MAX, day[j].P);
            }
        }
        day[i].P += MAX;
        if(day[i].T + i <= N)
            result = max(day[i].P, result);
    }
    printf("%d", result);
}