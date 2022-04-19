#include<stdio.h>

int set[7];
int N, M;

void func(int index) {
    if(index == M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", set[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= N; i++) {
        set[index] = i;
        func(index + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        set[0] = i;
        func(1);
    }
}