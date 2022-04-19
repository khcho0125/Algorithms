#include <stdio.h>

int main()
{
    int A, P;
    scanf("%d %d", &A, &P);
    if(A * 7 == P * 13) {
        printf("lika");
        return 0;
    }
    printf(A * 7 > P * 13 ? "Axel" : "Petra");
}