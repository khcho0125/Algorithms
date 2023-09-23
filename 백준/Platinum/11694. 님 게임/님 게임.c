#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 1000

int P[N_MAX];

bool spragueGrundy(int size) {
    bool flag = false;
    int nim = 0, one = 0;
    for(int i = 0; i < size; i++) {
        one += (P[i] == 1);
        nim ^= P[i];
        flag |= P[i] > 1;
    }

    if(!flag) return !nim;
    if(!one || one & 1) return nim;

    for(int i = 0; i < size; i++) {
        if(P[i] != 1) P[i] = 1;
    }
    
    nim = 0;
    for(int i = 0; i < size; i++) {
        nim ^= P[i];
    }

    return nim;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }

    printf(spragueGrundy(N) ? "koosaga" : "cubelover");
}