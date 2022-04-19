#include <stdio.h>

int main()
{
    int N, M, result;
    scanf("%d %d", &N, &M);
    result = N * 1500;
    if(N > 60 + M) {
        result += (N - (60 + M)) * 1500;
    }
    printf("%d", result);
}