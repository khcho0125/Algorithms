#include <stdio.h>

int main()
{
    int N, W, H, L;
    scanf("%d %d %d %d", &N, &W, &H, &L);
    printf("%d", ((W / L) * (H / L) > N ? N : (W / L) * (H / L)));
}