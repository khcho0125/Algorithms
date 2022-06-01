#include<stdio.h>

int main() {
    char str;
    int N, T = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf(" %c", &str);
        if(str != 'C') T++;
    }
    printf("%d", N / T);
}