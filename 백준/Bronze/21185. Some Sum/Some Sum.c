#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N % 4 == 0) {
        printf("Even");
    } else if(N % 2 == 0) {
        printf("Odd");
    } else {
        printf("Either");
    }
}