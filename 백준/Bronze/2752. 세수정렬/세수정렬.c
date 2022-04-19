#include<stdio.h>

int main() {
    int A, B, C, one, three;
    scanf("%d %d %d", &A, &B, &C);
    one = (A > B ? B : A) > C ? C : (A > B ? B : A);
    three = (A > B ? A : B) > C ? (A > B ? A : B) : C;
    if(one != B && three != B) A = B;
    else if(one != C && three != C) A = C; 
    printf("%d %d %d", one, A, three);
}