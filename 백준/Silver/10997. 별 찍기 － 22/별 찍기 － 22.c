#include<stdio.h>
#include<math.h>

char map[400][400];

void top(int N, int lenght) {
    for(int i = 0; i < N * 2 - 1; i++) {
        for(int j = i; j < lenght - i && i != 1; j++) {
            map[i][j] = (i % 2 == 0 ? '*' : ' ');
        }
    }
}

void left(int N, int lenght) {
    for(int i = 0; i < N * 2 - 1; i++) {
        for(int j = i; j < lenght + 1 - i; j++) {
            map[j + 1][i] = (i % 2 == 0 ? '*' : ' ');
        }
    }
}

void right(int N, int lenght) {
    for(int i = 0; i < N * 2 - 1; i++) {
        for(int j = i; j < lenght + 1 - i; j++) {
            map[j + 1][lenght - 1 - i] = (((i % 2 == 0 && i != j) || (i % 2 && i == j)) ? '*' : ' ');
        }
    }
}

void bot(int N, int lenght) {
    for(int i = 0; i < N * 2 - 1; i++) {
        for(int j = i; j < lenght - i; j++) {
            map[lenght + 1 - i][j] = (i % 2 == 0 ? '*' : ' ');
        }
    }
}

void solve(int N, int len) {
    right(N, len);
    top(N, len);
    left(N, len);
    bot(N, len);
}

int main() {
    int N, lenght;
    scanf("%d", &N);
    lenght = (N * 2 - 1) * 2 - 1;
    if(N == 1) { 
        printf("*");
        return 0;
    }
    solve(N, lenght);
    for(int i = 0; i < lenght + 2; i++) {
        printf("%s\n", map[i]);
    }
}