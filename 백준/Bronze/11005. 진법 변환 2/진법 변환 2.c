#include<stdio.h>

int i = 0;
char res[35];

void Trans(int N, int B);

int main() {
    int x, b;
    scanf("%d %d", &x, &b);
    Trans(x, b);
    printf("%s", res);
}

void Trans(int N, int B) {
    if(N == 0) return;

    int t = N % B;
    Trans(N / B, B);

    if(t > 9) res[i++] = 'A' + t - 10;
    else res[i++] = t + '0';
}