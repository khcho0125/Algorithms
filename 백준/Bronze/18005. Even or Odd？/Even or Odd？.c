#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N % 2) printf("0");
    else if((N / 2) % 2) {
        printf("1");
    } else {
        printf("2");
    }
}