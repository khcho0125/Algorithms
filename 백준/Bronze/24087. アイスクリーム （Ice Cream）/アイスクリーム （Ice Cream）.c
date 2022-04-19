#include <stdio.h>

int main()
{
    int A, B, S;
    scanf("%d %d %d", &S, &A, &B);
    printf("%d", (S > A ? 100 * ((S - A) / B + ((S - A) % B != 0)) + 250 : 250));
}