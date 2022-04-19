#include <stdio.h>
int main()
{
    int A, B, C, D, p1, p2, p3;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    p1 = (A > D ? A - D : D - A) + (B > C ? B - C : C - B);
    p2 = (A > C ? A - C : C - A) + (B > D ? B - D : D - B);
    p3 = B > A ? B - A : A - B;
    printf("%d", (p1 < p2 ? p1 : p2) < p3 ? (p1 < p2 ? p1 : p2) : p3);
}