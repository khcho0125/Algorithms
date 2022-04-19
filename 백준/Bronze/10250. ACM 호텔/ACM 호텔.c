#include<stdio.h>

int main() {

    int N, H, W, Case, i, Y, X;
    scanf("%d", &Case);
    for(i = 0; i < Case; i++) {
        scanf("%d %d %d", &H, &W, &N);
        Y = N / H;
        if(!(N % H)) {
            X = H;
        } else {
            X = N % H;
            Y++;
        }
        printf("%d%02d\n", X, Y);
    }
}