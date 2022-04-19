#include <stdio.h>

int main()
{
    int N, D, V, Dsum = 0, Vsum = 0, result = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &D, &V);
        if (Dsum + result < Vsum + V)
        {
            result = Vsum + V - Dsum;
        }
        Dsum += D;
        Vsum += V;
    }
    printf("%d", result);
}