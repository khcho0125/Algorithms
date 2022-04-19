#include<stdio.h>

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    if((A == 8 || A == 9) && B == C && (D == 8 || D == 9)) {
        printf("ignore");
    } else{
        printf("answer");
    }
}