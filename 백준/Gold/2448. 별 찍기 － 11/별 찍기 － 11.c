#include <stdio.h>

char star[3100][6200] = {0,};


void Print(int Xs, int Ys, int N)
{
    if (N == 3)
    {
        for(int i = 0; i < 3; i++) {
            star[Xs + i][Ys + 2 - i] = '*';
            star[Xs + i][Ys + 2 + i] = '*';
        }
        for(int i = 0; i < 3; i++) {
            star[Xs + 2][Ys + 1 + i] = '*';
        }
    }
    else
    {
        Print(Xs, Ys + N / 2, N / 2);
        Print(Xs + N / 2, Ys, N / 2);
        Print(Xs + N / 2, Ys + N, N / 2);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    Print(1, 1, N);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N * 2; j++) {
            if(star[i][j] == '*') {
                printf("%c", star[i][j]);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}