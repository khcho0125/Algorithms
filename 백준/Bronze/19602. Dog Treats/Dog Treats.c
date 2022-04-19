#include <stdio.h>

int main()
{
    int X, L, R;
    scanf("%d %d %d", &X, &L, &R);
    printf("%s", (X + L * 2 + R * 3 < 10 ? "sad" : "happy"));
}