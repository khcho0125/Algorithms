#include <stdio.h>

int main()
{
    int H, W, N, M;
    scanf("%d %d %d %d", &H, &W, &N, &M);
    printf("%d", (W / (M + 1) + (W % (M + 1) != 0)) * (H / (N + 1) + (H % (N + 1) != 0)));
}