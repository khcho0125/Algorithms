#include<stdio.h>

int visit[9] = {0,};
int set[8];
int N, M;

void func(int index) {
    if(index == M) {
        for(int i = 0; i < index; i++) {
            printf("%d ", set[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(!visit[i]) {
            visit[i] = 1;
            set[index] = i;
            func(index + 1);
            visit[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        visit[i] = 1;
        set[0] = i;
        func(1);
        visit[i] = 0;
    }
}