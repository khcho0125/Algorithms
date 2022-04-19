#include<stdio.h>

int main() {
    int N, A, B, C, D, num = 0, num2 = 0;
    scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);
    for(int i = A; 0 < i; i-=C) {
        num++;
    }
    for(int i = B; 0 < i; i-=D) {
        num2++;
    }
    printf("%d", num > num2 ? N - num : N - num2);
}
