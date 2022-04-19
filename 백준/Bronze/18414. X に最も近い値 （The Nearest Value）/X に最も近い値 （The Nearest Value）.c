#include <stdio.h>

int main()
{
    int X, L, R;
    scanf("%d %d %d", &X, &L, &R);
    if(X >= L && X <= R) {
        printf("%d", X);
    } else if(X <= L) {
        printf("%d", L);
    } else {
        printf("%d", R);
    }
}