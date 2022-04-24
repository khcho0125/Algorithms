#include<stdio.h>

void star(int N) {
    for(int i = 0; i < N; i++) {
        printf("*");
    }
}

void blank(int N) {
    for(int i = 0; i < N; i++) {
        printf(" ");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        blank(i - 1);
        if(i == 1) {
            star(N);
        }
        else {
            printf("*");
            blank(N - 2);
            printf("*");
        }
        blank((N * 2) - (i * 2) - 1);
        if(i == 1) {
            star(N);
        } else {
            if(i != N) {
                printf("*");
            }
            blank(N - 2);
            printf("*");
        }
        printf("\n");
    }
    for(int i = 1; i < N; i++) {
        blank(N - i - 1);
        if(i == N - 1) {
            star(N);
        }
        else {
            printf("*");
            blank(N - 2);
            printf("*");
        }
        blank(i * 2 - 1);
        if(i == N - 1) {
            star(N);
        }
        else {
            printf("*");
            blank(N - 2);
            printf("*");
        }
        printf("\n");
    }
}