#include <stdio.h>

int main()
{
    int N, H, Y;
    scanf("%d %d %d", &N, &H, &Y);
    printf("%d", 4 * (H > N - H ? H : N - H) * (Y > N - Y ? Y : N - Y));
}