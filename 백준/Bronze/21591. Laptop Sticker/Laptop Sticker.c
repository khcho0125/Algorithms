#include <stdio.h>

int main()
{
    int w, h, w2, h2;
    scanf("%d %d %d %d", &w, &h, &w2, &h2);
    printf("%d", (w - w2 >= 2 && h - h2 >= 2));
}