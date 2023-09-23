#include<stdio.h>

#define N_MAX 1000

int set[N_MAX];
int P[N_MAX];

int main() {
    int N, able = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
        for(int j = 0; j < N; j++) if(i != j) set[j] ^= P[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P[i]; j++) able += ((j ^ set[i]) == 0);
    }

    printf("%d", able);
}