#include<stdio.h>

long long Pow(int A, int B, int C) {
    if(B == 0) {
        return 1;
    }
    long long temp = Pow(A, B / 2, C);
    temp = temp * temp % C;
    if(B % 2 == 0) {
        return temp;
    }
    return A * temp % C;
}

int main() {
    long long A, B, C, temp = 1, count = 0;
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld", Pow(A, B, C));
}