#include <stdio.h>

int main()
{
    int K, W, M, i;
    scanf("%d %d %d", &K, &W, &M);
    for(i = 0; K < W; K += M, i++);
    printf("%d", i);
}