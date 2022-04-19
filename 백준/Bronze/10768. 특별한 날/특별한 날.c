#include<stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    A = A * 31 + B;
    if(A < 80) {
        printf("Before");
    } else if(A > 80) {
        printf("After");
    } else {
        printf("Special");
    }
}